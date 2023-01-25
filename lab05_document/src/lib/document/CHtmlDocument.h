#ifndef LAB05_DOCUMENT_CHTMLDOCUMENT_H
#define LAB05_DOCUMENT_CHTMLDOCUMENT_H

#include "../file/CPath.h"
#include "../file/IFileStorage.h"
#include "../random/Random.h"
#include "IDocument.h"
#include "node/CImageNode.h"
#include "node/CParagraphNode.h"
#include "node/INode.h"
#include "render/CHtmlRenderer.h"

#include <fstream>
#include <memory>
#include <optional>
#include <utility>
#include <vector>

class CHtmlDocument : public IDocument
{
public:
	explicit CHtmlDocument(const std::shared_ptr<IFileStorage>& imageStorage)
		: m_imageStorage(imageStorage)
		, m_nodes(std::vector<std::shared_ptr<INode>>())
	{
	}

	void InsertParagraph(const std::string& text, std::optional<std::size_t> position = std::nullopt) override
	{
		InsertNode(std::make_shared<CParagraphNode>(text), position);
	}

	void InsertImage(const CPath& path, unsigned int width, unsigned int height, std::optional<std::size_t> position = std::nullopt) override
	{
		auto storedImagePath = m_imageStorage->SaveFile(path, RandomString(10));
		if (!storedImagePath.has_value())
		{
			throw std::runtime_error("could not save image to storage");
		}
		InsertNode(std::make_shared<CImageNode>(storedImagePath.value(), width, height), position);
	}

	[[nodiscard]]
	std::size_t GetNodesCount() const override
	{
		return m_nodes.size();
	}

	[[nodiscard]]
	std::shared_ptr<INode> GetNode(std::size_t index) const override
	{
		if (index >= m_nodes.size())
		{
			throw std::out_of_range("no such node");
		}

		return m_nodes[index];
	}

	void DeleteNode(std::size_t index) override
	{
		if (index >= m_nodes.size())
		{
			throw std::out_of_range("no such node");
		}

		auto it = m_nodes.begin();
		std::advance(it, index);
		m_nodes.erase(it);
	}

	void SetTitle(const std::string& title) override
	{
		m_title = title;
	}

	[[nodiscard]]
	std::string GetTitle() const override
	{
		return m_title;
	}

	void Save(const CPath& path) const override
	{
		std::ofstream file(path.String());
		if (!file)
		{
			throw std::runtime_error("could not open file to save");
		}

		file << "<!doctype html>"
				"<html>"
				"<head><title>" << GetTitle() << "</title></head>"
				"<body>";

		CHtmlRenderer htmlRenderer(file);
		for (auto& node : m_nodes)
		{
			node->Render(htmlRenderer);
		}

		file << "</body>"
				"</html>";

		file.flush();
		file.close();
	}

private:
	std::vector<std::shared_ptr<INode>> m_nodes;
	std::shared_ptr<IFileStorage> m_imageStorage;
	std::string m_title;

	void InsertNode(const std::shared_ptr<INode>& node, std::optional<std::size_t> position = std::nullopt)
	{
		if (!position.has_value() || (position.value() == 0 && m_nodes.empty()))
		{
			m_nodes.push_back(node);
			return;
		}

		if (position.value() >= m_nodes.size())
		{
			throw std::range_error("cannot insert paragraph in given position");
		}

		m_nodes.insert(m_nodes.begin() + (long)position.value(), node);
	}
};

#endif // LAB05_DOCUMENT_CHTMLDOCUMENT_H

#ifndef LAB05_DOCUMENT_CHTMLDOCUMENT_H
#define LAB05_DOCUMENT_CHTMLDOCUMENT_H

#include "CImageNode.h"
#include "CParagraphNode.h"
#include "IDocument.h"
#include "INode.h"
#include "file/CPath.h"
#include "file/IFileStorage.h"
#include "random/Random.h"

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

private:
	std::vector<std::shared_ptr<INode>> m_nodes;
	std::shared_ptr<IFileStorage> m_imageStorage;

	void InsertNode(const std::shared_ptr<INode>& node, std::optional<std::size_t> position = std::nullopt)
	{
		if (!position.has_value())
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

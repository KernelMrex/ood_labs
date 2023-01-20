#ifndef LAB05_DOCUMENT_IDOCUMENT_H
#define LAB05_DOCUMENT_IDOCUMENT_H

#include "INode.h"
#include "file/CPath.h"
#include <memory>
#include <optional>
#include <string>

class IDocument
{
public:
	virtual void InsertParagraph(const std::string& text, std::optional<std::size_t> position = std::nullopt) = 0;

	virtual void InsertImage(const CPath& path, unsigned int width, unsigned int height, std::optional<std::size_t> position = std::nullopt) = 0;

	[[nodiscard]]
	virtual std::size_t GetNodesCount() const = 0;

	[[nodiscard]]
	virtual std::shared_ptr<INode> GetNode(std::size_t index) const = 0;

	virtual void DeleteNode(std::size_t index) = 0;

	virtual void SetTitle(const std::string& title) = 0;

	[[nodiscard]]
	virtual std::string GetTitle() const = 0;

	virtual void Save(const CPath& path) const = 0;

	virtual ~IDocument() = default;
};

#endif // LAB05_DOCUMENT_IDOCUMENT_H

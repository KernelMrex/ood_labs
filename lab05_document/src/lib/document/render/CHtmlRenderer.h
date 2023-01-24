#ifndef LAB05_DOCUMENT_CHTMLRENDERER_H
#define LAB05_DOCUMENT_CHTMLRENDERER_H

#include "../node/INodeVisitor.h"
#include <ostream>

class CHtmlRenderer : public INodeVisitor
{
public:
	explicit CHtmlRenderer(std::ostream& out)
		: m_out(out)
	{}

	void Visit(const CImageNode& node) override;

	void Visit(const CParagraphNode& node) override;

private:
	std::ostream& m_out;
};

#endif // LAB05_DOCUMENT_CHTMLRENDERER_H

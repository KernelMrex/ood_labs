#ifndef LAB04_PAINTER_CPICTUREDRAFT_H
#define LAB04_PAINTER_CPICTUREDRAFT_H

#include "CShape.h"
#include <memory>
#include <vector>

class CPictureDraft
{
public:
	explicit CPictureDraft(const std::vector<std::shared_ptr<CShape>>& shapes)
		: m_shapes(shapes)
	{}

	[[nodiscard]]
	std::size_t GetShapeCount() const
	{
		return m_shapes.size();
	}

	[[nodiscard]]
	const CShape& GetShape(std::size_t index) const
	{
		return *m_shapes[index];
	}

private:
	std::vector<std::shared_ptr<CShape>> m_shapes;
};

#endif // LAB04_PAINTER_CPICTUREDRAFT_H

#ifndef LAB04_PAINTER_CPICTUREDRAFT_H
#define LAB04_PAINTER_CPICTUREDRAFT_H

#include "CShape.h"
#include <memory>
#include <vector>

class CPictureDraft
{
public:
	explicit CPictureDraft(const std::vector<std::shared_ptr<CShape>>& shapes)
		: m_shapes(std::vector<std::unique_ptr<CShape>>())
	{
		for (const auto& shape : shapes)
		{
			m_shapes.push_back(shape->Clone());
		}
	}

	[[nodiscard]]
	std::size_t GetShapeCount() const
	{
		return m_shapes.size();
	}

	[[nodiscard]]
	std::unique_ptr<CShape> GetShape(std::size_t index) const
	{
		// TODO: вернуть константную ссылку
		if (index >= m_shapes.size())
		{
			return nullptr;
		}

		return m_shapes[index]->Clone();
	}

private:
	// TODO: переделать на shared_ptr
	std::vector<std::unique_ptr<CShape>> m_shapes;
};

#endif // LAB04_PAINTER_CPICTUREDRAFT_H

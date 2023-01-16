#include "../../../../src/lib/CShape.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

class MockShape : public CShape
{
public:
	MockShape()
		: CShape(Color::RED){};

	MOCK_METHOD(void, Draw, (ICanvas & canvas), (const, override));
};

#include "../../../../src/lib/ICanvas.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

class MockCanvas : public ICanvas
{
public:
	MOCK_METHOD(void, SetColor, (Color color), (override));
	MOCK_METHOD(void, Drawline, (const Point2D& from, const Point2D& to), (override));
	MOCK_METHOD(void, DrawEllipse, (const Point2D& from, int horizontalRadius, int verticalRadius), (override));
};

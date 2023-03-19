#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../../../../src/app/canvas/ICanvas.h"

class MockCanvas : public ICanvas
{
public:
	MOCK_METHOD(void, DrawLine, (const SPoint& from, const SPoint& to), (override));
	MOCK_METHOD(void, FillPolygon, (const std::vector<SPoint>& vertices, SColor color), (override));
	MOCK_METHOD(void, DrawEllipse, (const SPoint& center, uint verticalRadius, uint horizontalRadius, const SColor& color, uint thickness), (override));
	MOCK_METHOD(void, FillEllipse, (const SPoint& center, uint verticalRadius, uint horizontalRadius, const SColor& color), (override));
};
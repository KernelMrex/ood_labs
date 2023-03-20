#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../../../../src/app/common/SFrame.h"
#include "../../../../src/app/figure/IFigure.h"

class MockFigure : public IFigure
{
public:
	MOCK_METHOD(void, Draw, (ICanvas& canvas), (override, const));
	MOCK_METHOD(void, Resize, (uint width, uint height), (override));
	MOCK_METHOD(std::optional<SFrame>, Frame, (), (override, const));
};
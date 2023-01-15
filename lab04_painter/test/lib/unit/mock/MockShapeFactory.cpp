#include "../../../../src/lib/IShapeFactory.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

class MockShapeFactory : public IShapeFactory
{
public:
	MockShapeFactory() = default;

	MOCK_METHOD(std::unique_ptr<CShape>, CreateShape, (const std::string& description), (const, override));
};

#include "../../../src/lib/command/ICommandHistory.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

class MockCommandHistory : public ICommandHistory
{
public:
	MOCK_METHOD(void, Push, (std::shared_ptr<ICommand>), (override));
	MOCK_METHOD(std::shared_ptr<ICommand>, Pop, (), (override));
	MOCK_METHOD(void, Clear, (), (override));
};
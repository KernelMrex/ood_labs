#include "../../../../src/lib/document/node/INode.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

class MockNode : public INode
{
public:
	MOCK_METHOD(void, Render, (INodeVisitor& renderer), (override, const));
	MOCK_METHOD(NodeType, Type, (), (override, const));
};
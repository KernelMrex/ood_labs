#include "../../src/lib/CHtmlDocument.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(CHtmlDocumentTest, InsertParagraph)
{
	ASSERT_NO_THROW({
		CHtmlDocument doc;
		doc.InsertParagraph("Test paragraph");
		doc.InsertParagraph("Test paragraph 2");

		ASSERT_EQ(doc.GetNodesCount(), 2);

		auto node1 = doc.GetNode(0);
		auto paragraphNode1 = std::dynamic_pointer_cast<CParagraphNode>(node1);
		ASSERT_NE(paragraphNode1.get(), nullptr);
		ASSERT_EQ(paragraphNode1->Text(), "Test paragraph");

		auto node2 = doc.GetNode(1);
		auto paragraphNode2 = std::dynamic_pointer_cast<CParagraphNode>(node2);
		ASSERT_NE(paragraphNode2.get(), nullptr);
		ASSERT_EQ(paragraphNode2->Text(), "Test paragraph 2");
	});
}

TEST(CHtmlDocumentTest, InsertParagraphInPosition)
{
	ASSERT_NO_THROW({
		CHtmlDocument doc;
		doc.InsertParagraph("Test paragraph");
		doc.InsertParagraph("Test paragraph 2", 0);

		ASSERT_EQ(doc.GetNodesCount(), 2);

		auto node1 = doc.GetNode(1);
		auto paragraphNode1 = std::dynamic_pointer_cast<CParagraphNode>(node1);
		ASSERT_NE(paragraphNode1.get(), nullptr);
		ASSERT_EQ(paragraphNode1->Text(), "Test paragraph");

		auto node2 = doc.GetNode(0);
		auto paragraphNode2 = std::dynamic_pointer_cast<CParagraphNode>(node2);
		ASSERT_NE(paragraphNode2.get(), nullptr);
		ASSERT_EQ(paragraphNode2->Text(), "Test paragraph 2");
	});

	ASSERT_THROW({
		CHtmlDocument doc;
		doc.InsertParagraph("Test paragraph");
		doc.InsertParagraph("Test paragraph 2", 1);
	}, std::range_error);
}

TEST(CHtmlDocumentTest, GetNodeOverflow)
{
	ASSERT_THROW({
		CHtmlDocument doc;
		doc.InsertParagraph("Test paragraph");
		doc.InsertParagraph("Test paragraph 2");
		auto _ = doc.GetNode(2);
	}, std::out_of_range);
}
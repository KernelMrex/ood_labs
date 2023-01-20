#include "../../src/lib/CHtmlDocument.h"
#include <gtest/gtest.h>

#include "file/MockFileStorage.cpp"

TEST(CHtmlDocumentTest, InsertParagraph)
{
	ASSERT_NO_THROW({
		CHtmlDocument doc(std::make_shared<MockFileStorage>());
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
		CHtmlDocument doc(std::make_shared<MockFileStorage>());
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
		CHtmlDocument doc(std::make_shared<MockFileStorage>());
		doc.InsertParagraph("Test paragraph");
		doc.InsertParagraph("Test paragraph 2", 1);
	}, std::range_error);
}

TEST(CHtmlDocumentTest, GetNodeOverflow)
{
	ASSERT_THROW({
		CHtmlDocument doc(std::make_shared<MockFileStorage>());
		doc.InsertParagraph("Test paragraph");
		doc.InsertParagraph("Test paragraph 2");
		auto _ = doc.GetNode(2);
	}, std::out_of_range);
}

TEST(CHtmlDocumentTest, InsertingImage)
{
	ASSERT_NO_THROW({
		auto mockFileStorage = std::make_shared<MockFileStorage>();
		EXPECT_CALL(*mockFileStorage, SaveFile(::testing::_, ::testing::_))
			.Times(1)
			.WillOnce(::testing::Return(std::optional(CPath("/resulting/stored/path.dat"))));

		CHtmlDocument doc(mockFileStorage);

		doc.InsertImage(CPath("/dev/null"), 400, 300);

		auto node = doc.GetNode(0);
		auto imageNode = std::dynamic_pointer_cast<CImageNode>(node);
		ASSERT_NE(imageNode.get(), nullptr);

		ASSERT_EQ(imageNode->Path().String(), "/resulting/stored/path.dat");
	});
}

TEST(CHtmlDocumentTest, CouldNotInsertImageDueFileStorageError)
{
	auto mockFileStorage = std::make_shared<MockFileStorage>();
	EXPECT_CALL(*mockFileStorage, SaveFile(::testing::_, ::testing::_))
		.Times(1)
		.WillOnce(::testing::Return(std::nullopt));

	CHtmlDocument doc(mockFileStorage);

	ASSERT_THROW({
		doc.InsertImage(CPath("/dev/null"), 400, 300);
	}, std::runtime_error);
}

TEST(CHtmlDocumentTest, GetAndSetTitle)
{
	CHtmlDocument doc(std::make_shared<MockFileStorage>());
	ASSERT_EQ(doc.GetTitle(), "");

	doc.SetTitle("Testing title");
	ASSERT_EQ(doc.GetTitle(), "Testing title");
}
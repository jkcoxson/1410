#include <iostream>

#include "gtest.h"

#include "BST.hpp"
using namespace std;


TEST(IntBST, Insert)
{
  BST<int> bst;

  bst.insert(40);
  bst.insert(25);
  bst.insert(75);

  EXPECT_TRUE(bst.contains(40));
  EXPECT_TRUE(bst.contains(25));
  EXPECT_TRUE(bst.contains(75));

  EXPECT_EQ(bst.search(40), "Found: root(40)");
  EXPECT_EQ(bst.search(25), "Found: root(40)->left(25)");
  EXPECT_EQ(bst.search(75), "Found: root(40)->right(75)");

  EXPECT_EQ(3, bst.count());
}

TEST(IntBST, DoesNotContain)
{
  BST<int> bst;
  bst.insert(50);
  bst.insert(25);
  bst.insert(75);
  bst.insert(2);
  bst.insert(89);


  EXPECT_FALSE(bst.contains(100));

  EXPECT_EQ(bst.search(1), "Not found: root(50)->left(25)->left(2)");
  EXPECT_EQ(bst.search(100), "Not found: root(50)->right(75)->right(89)");

  EXPECT_EQ(5, bst.count());
}

TEST(IntBST, BigSearch)
{
  BST<int> bst;
  bst.insert(50);
  bst.insert(25);
  bst.insert(49);
  bst.insert(26);
  bst.insert(48);
  bst.insert(27);
  bst.insert(47);
  bst.insert(28);

  bst.insert(75);
  bst.insert(51);
  bst.insert(74);
  bst.insert(52);
  bst.insert(73);
  bst.insert(53);
  bst.insert(72);

  EXPECT_EQ(15, bst.count());
  EXPECT_EQ(bst.search(28), "Found: root(50)->left(25)->right(49)->left(26)->right(48)->left(27)->right(47)->left(28)");
  EXPECT_EQ(bst.search(72), "Found: root(50)->right(75)->left(51)->right(74)->left(52)->right(73)->left(53)->right(72)");
}

TEST(IntBST, Remove)
{

	BST<int> bst;
	bst.insert(50);
	bst.insert(25);
	bst.insert(42);
	bst.insert(26);
	bst.insert(88);
	bst.insert(75);
	bst.insert(46);
	bst.insert(18);
	bst.insert(44);

	bst.remove(50);


	EXPECT_EQ(bst.search(18), "Found: root(46)->left(25)->left(18)");
 
  EXPECT_TRUE(true);
}

TEST(StringBST, Insert)
{
  BST<std::string> bst;

  bst.insert("50");
  bst.insert("25");
  bst.insert("75");

  EXPECT_TRUE(bst.contains("50"));
  EXPECT_TRUE(bst.contains("25"));
  EXPECT_TRUE(bst.contains("75"));

  EXPECT_EQ(bst.search("50"), "Found: root(50)");
  EXPECT_EQ(bst.search("25"), "Found: root(50)->left(25)");
  EXPECT_EQ(bst.search("75"), "Found: root(50)->right(75)");

  EXPECT_EQ(3, bst.count());
}

TEST(StringBST, DoesNotContain)
{
  BST<std::string> bst;
  bst.insert("50");
  bst.insert("25");
  bst.insert("75");

  EXPECT_FALSE(bst.contains("1"));

  EXPECT_EQ(bst.search("1"), "Not found: root(50)->left(25)");

  EXPECT_EQ(3, bst.count());
}

TEST(StringBST, BigSearch)
{
  BST<std::string> bst;
  bst.insert("50");
  bst.insert("25");
  bst.insert("49");
  bst.insert("26");
  bst.insert("48");
  bst.insert("27");
  bst.insert("47");
  bst.insert("28");

  bst.insert("75");
  bst.insert("51");
  bst.insert("74");
  bst.insert("52");
  bst.insert("73");
  bst.insert("53");
  bst.insert("72");

  EXPECT_EQ(15, bst.count());
  EXPECT_EQ(bst.search("28"), "Found: root(50)->left(25)->right(49)->left(26)->right(48)->left(27)->right(47)->left(28)");
  EXPECT_EQ(bst.search("72"), "Found: root(50)->right(75)->left(51)->right(74)->left(52)->right(73)->left(53)->right(72)");
}

TEST(StringBST, Remove)
{
  // EXTRA CREDIT
	BST<std::string> bst;
	bst.insert("50");
	bst.insert("25");
	bst.insert("49");
	bst.insert("26");
	bst.insert("48");
	bst.insert("27");
	bst.insert("47");
	bst.insert("28");

	bst.insert("75");
	bst.insert("51");
	bst.insert("74");
	bst.insert("52");
	bst.insert("32");
	bst.insert("53");
	bst.insert("72");
	bst.remove("50");
	

	EXPECT_EQ(bst.search("32"), "Found: root(49)->left(25)->right(26)->right(48)->left(27)->right(47)->left(28)->right(32)");

  EXPECT_TRUE(true);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}

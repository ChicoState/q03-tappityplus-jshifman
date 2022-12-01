/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
 
class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(tappityTest, emptyStringsInitial_length)
{
	tappity t = tappity("");
	int diff = t.length_difference();
	ASSERT_EQ(diff,0);
}

TEST(tappityTest, emptyStringsInitial_accuracy)
{
	tappity t = tappity("");
	double accuracy = t.accuracy();
	ASSERT_EQ(accuracy, 100);
}

TEST(tappityTest, emptyStringsInput_length)
{
	tappity t = tappity("");
	t.entry("");
	int diff = t.length_difference();
	ASSERT_EQ(diff,0);
}

TEST(tappityTest, emptyStringsInput_accuracy)
{
	tappity t = tappity("");
	t.entry("");
	double accuracy = t.accuracy();
	ASSERT_EQ(accuracy, 100);
}

TEST(tappityTest, emptyRef_length)
{
	tappity t = tappity("");
	t.entry("Hello World");
	int length = strlen("Hello World");
	int result = t.length_difference();
	ASSERT_EQ(result, length);
}

TEST(tappityTest, emptyRef_accuracy)
{
	tappity t = tappity("");
	t.entry("Hello World");
	double result = t.accuracy();
	ASSERT_EQ(result, 0);
}

TEST(tappityTest, emptyInput_length)
{
	tappity t = tappity("Hello World");
	t.entry("");
	int length = strlen("Hello World");
	int result = t.length_difference();
	ASSERT_EQ(result, length);
}

TEST(tappityTest, emptyInput_accuracy)
{
	tappity t = tappity("Hello World");
	t.entry("");
	double result = t.accuracy();
	ASSERT_EQ(result, 0);
}

TEST(tappityTest, exactSame_length)
{
	tappity t = tappity("Hello World");
	t.entry("Hello World");
	int result = t.length_difference();
	ASSERT_EQ(0, result);
}

TEST(tappityTest, exactSame_accuracy)
{
	tappity t = tappity("Hello World");
	t.entry("Hello World");
	double result = t.accuracy();
	ASSERT_EQ(100, result);
}

TEST(tappityTest, halfOffset_length)
{
	tappity t = tappity("Hello World");
	t.entry("HelloWorld");
	int result = t.length_difference();
	ASSERT_EQ(1, result);
}

TEST(tappityTest, halfOffset_accuracy)
{
	tappity t = tappity("Hello World");
	t.entry("HelloWorld");
	double result = t.accuracy();
	double expected = 100 * 5.0/strlen("Hello World");
	ASSERT_EQ(expected, result);
}

TEST(tappityTest, caseSensitive_length)
{
	tappity t = tappity("Hello World");
	t.entry("hello world");
	int result = t.length_difference();
	ASSERT_EQ(0, result);
}

TEST(tappityTest, caseSensitive_accuracy)
{
	tappity t = tappity("Hello World");
	t.entry("hello world");
	double result = t.accuracy();
	double expected = 100 * (9.0/strlen("Hello World"));
	ASSERT_EQ(expected, result);
}

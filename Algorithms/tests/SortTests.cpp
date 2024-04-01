

#include "QuickSort.h"
#include "gtest/gtest.h"

#include <random>
#include <limits>
#include <vector>
#include "Array.hpp"


class IntSortTests : public ::testing::Test
{

public:
	Array<int> empty_arr;
	Array<int> arr1;
	Array<int> arr2;
	Array<int> arr3;
	Array<int> arr4;
	Array<int> arr5;
	Array<int> arr6;
	Array<int> rep_arr;
	std::vector<int> ads;

	//Get a random seed from the OS entropy device, or whatever
	std::random_device rd;
	//Use the 64-bit Mersenne Twister 19937 generator
	//and seed it with entropy.
	std::mt19937_64 eng = std::mt19937_64(rd());

	IntSortTests()
	{

	}

	~IntSortTests() override
	{

	}

	void insert_randomly(Array<int>& arr, size_t size)
	{
		std::uniform_int_distribution<int> distr(INT_MIN, INT_MAX);
		for (size_t i = 0; i < size; i++)
		{
			arr.Insert(distr(eng));
		}
	}

	void SetUp() override
	{
		empty_arr = {};
		arr1 = { 1 };
		arr2 = { 1, -6 };
		arr3 = { 1, -6, 1 };
		arr4 = { 2, -8, 4, 1 };
		arr5 = { 2, 6, -1, 7, -9 };
		arr6 = { 2, 3, -8, 0, 2, 1 };
		rep_arr = { 2, 2, 2, 2 };
		ads = { 2, 0, 1, 3, -5, 1 };
	};

	void TearDown() override
	{

	};
};

TEST_F(IntSortTests, IsGetPivotCorrect)
{
	int mid = 1;
	Array<int> arr1 { 2, 0, 1 };
	Array<int> arr2 { 0, 2, 1 };
	Array<int> arr3 { 2, 1, 0 };
	Array<int> arr4 { 0, 1, 2 };
	Array<int> arr5 { 1, 2, 0 };
	Array<int> arr6 { 1, 0, 2 };

	std::vector<int> arr7{ 2, 0, 1 };
	EXPECT_EQ(gts::get_pivot(arr7.cbegin(), arr7.cend() - 1, std::greater<int>()), mid);

	EXPECT_EQ(gts::get_pivot(arr1.cbegin(), arr1.cend() - 1, std::greater<int>()), mid);
	EXPECT_EQ(gts::get_pivot(arr2.cbegin(), arr2.cend() - 1, std::greater<int>()), mid);
	EXPECT_EQ(gts::get_pivot(arr3.cbegin(), arr3.cend() - 1, std::greater<int>()), mid);
	EXPECT_EQ(gts::get_pivot(arr4.cbegin(), arr4.cend() - 1, std::greater<int>()), mid);
	EXPECT_EQ(gts::get_pivot(arr5.cbegin(), arr5.cend() - 1, std::greater<int>()), mid);
	EXPECT_EQ(gts::get_pivot(arr6.cbegin(), arr6.cend() - 1, std::greater<int>()), mid);

	EXPECT_EQ(gts::get_pivot(arr1.cbegin(), arr1.cend() - 1, std::less<int>()), mid);
	EXPECT_EQ(gts::get_pivot(arr2.cbegin(), arr2.cend() - 1, std::less<int>()), mid);
	EXPECT_EQ(gts::get_pivot(arr3.cbegin(), arr3.cend() - 1, std::less<int>()), mid);
	EXPECT_EQ(gts::get_pivot(arr4.cbegin(), arr4.cend() - 1, std::less<int>()), mid);
	EXPECT_EQ(gts::get_pivot(arr5.cbegin(), arr5.cend() - 1, std::less<int>()), mid);
	EXPECT_EQ(gts::get_pivot(arr6.cbegin(), arr6.cend() - 1, std::less<int>()), mid);
}

TEST_F(IntSortTests, AscInsertionSort)
{
	gts::insertion_sort(empty_arr.begin(), empty_arr.end(), std::less<int>());
	gts::insertion_sort(arr1.begin(), arr1.end(), std::less<int>());
	gts::insertion_sort(arr2.begin(), arr2.end(), std::less<int>());
	gts::insertion_sort(arr3.begin(), arr3.end(), std::less<int>());
	gts::insertion_sort(arr4.begin(), arr4.end(), std::less<int>());
	gts::insertion_sort(arr5.begin(), arr5.end(), std::less<int>());
	gts::insertion_sort(arr6.begin(), arr6.end(), std::less<int>());
	gts::insertion_sort(rep_arr.begin(), rep_arr.end(), std::less<int>());
	
	EXPECT_TRUE(gts::is_sorted(arr1.begin(), arr1.end(), std::less<int>()));
	EXPECT_TRUE(gts::is_sorted(arr2.begin(), arr2.end(), std::less<int>()));
	EXPECT_TRUE(gts::is_sorted(arr3.begin(), arr3.end(), std::less<int>()));
	EXPECT_TRUE(gts::is_sorted(arr4.begin(), arr4.end(), std::less<int>()));
	EXPECT_TRUE(gts::is_sorted(arr5.begin(), arr5.end(), std::less<int>()));
	EXPECT_TRUE(gts::is_sorted(arr6.begin(), arr6.end(), std::less<int>()));
	EXPECT_TRUE(gts::is_sorted(empty_arr.begin(), empty_arr.end(), std::less<int>()));
	EXPECT_TRUE(gts::is_sorted(rep_arr.begin(), rep_arr.end(), std::less<int>()));
	
	gts::insertion_sort(ads.begin(), ads.end(), std::less<int>());
	EXPECT_TRUE(is_sorted(ads.begin(), ads.end(), std::less<int>()));
}

TEST_F(IntSortTests, AscQSortNotOpt)
{
	gts::qsort_not_opt(empty_arr.begin(), empty_arr.end(), std::less<int>());
	gts::qsort_not_opt(arr1.begin(), arr1.end(), std::less<int>());
	gts::qsort_not_opt(arr2.begin(), arr2.end(), std::less<int>());
	gts::qsort_not_opt(arr3.begin(), arr3.end(), std::less<int>());
	gts::qsort_not_opt(arr4.begin(), arr4.end(), std::less<int>());
	gts::qsort_not_opt(arr5.begin(), arr5.end(), std::less<int>());
	gts::qsort_not_opt(arr6.begin(), arr6.end(), std::less<int>());
	gts::qsort_not_opt(rep_arr.begin(), rep_arr.end(), std::less<int>());

	EXPECT_TRUE(gts::is_sorted(arr1.begin(), arr1.end(), std::less<int>()));
	EXPECT_TRUE(gts::is_sorted(arr2.begin(), arr2.end(), std::less<int>()));
	EXPECT_TRUE(gts::is_sorted(arr3.begin(), arr3.end(), std::less<int>()));
	EXPECT_TRUE(gts::is_sorted(arr4.begin(), arr4.end(), std::less<int>()));
	EXPECT_TRUE(gts::is_sorted(arr5.begin(), arr5.end(), std::less<int>()));
	EXPECT_TRUE(gts::is_sorted(arr6.begin(), arr6.end(), std::less<int>()));
	EXPECT_TRUE(gts::is_sorted(empty_arr.begin(), empty_arr.end(), std::less<int>()));
	EXPECT_TRUE(gts::is_sorted(rep_arr.begin(), rep_arr.end(), std::less<int>()));

	gts::qsort_not_opt(ads.begin(), ads.end(), std::less<int>());
	EXPECT_TRUE(is_sorted(ads.begin(), ads.end(), std::less<int>()));
}

TEST_F(IntSortTests, AscQSort)
{
	Array<int> qarr1(100);
	Array<int> qarr2(200);
	Array<int> qarr3(560);
	Array<int> qarr4(1000);
	Array<int> qarr5(10000);

	insert_randomly(qarr1, 100);
	insert_randomly(qarr2, 200);
	insert_randomly(qarr3, 560);
	insert_randomly(qarr4, 1000);
	insert_randomly(qarr5, 10000);

	gts::qsort(empty_arr.begin(), empty_arr.end(), std::less<int>());
	gts::qsort(qarr1.begin(), qarr1.end(), std::less<int>());
	gts::qsort(qarr2.begin(), qarr2.end(), std::less<int>());
	gts::qsort(qarr3.begin(), qarr3.end(), std::less<int>());
	gts::qsort(qarr4.begin(), qarr4.end(), std::less<int>());
	gts::qsort(qarr5.begin(), qarr5.end(), std::less<int>());

	EXPECT_TRUE(gts::is_sorted(qarr1.begin(), qarr1.end(), std::less <int>()));
	EXPECT_TRUE(gts::is_sorted(qarr2.begin(), qarr2.end(), std::less<int>()));
	EXPECT_TRUE(gts::is_sorted(qarr3.begin(), qarr3.end(), std::less<int>()));
	EXPECT_TRUE(gts::is_sorted(qarr4.begin(), qarr4.end(), std::less<int>()));
	EXPECT_TRUE(gts::is_sorted(qarr5.begin(), qarr5.end(), std::less<int>()));
}

TEST_F(IntSortTests, DescInsertionSort)
{
	gts::insertion_sort(empty_arr.begin(), empty_arr.end(), std::greater<int>());
	gts::insertion_sort(arr1.begin(), arr1.end(), std::greater<int>());
	gts::insertion_sort(arr2.begin(), arr2.end(), std::greater<int>());
	gts::insertion_sort(arr3.begin(), arr3.end(), std::greater<int>());
	gts::insertion_sort(arr4.begin(), arr4.end(), std::greater<int>());
	gts::insertion_sort(arr5.begin(), arr5.end(), std::greater<int>());
	gts::insertion_sort(arr6.begin(), arr6.end(), std::greater<int>());
	gts::insertion_sort(rep_arr.begin(), rep_arr.end(), std::greater<int>());

	EXPECT_TRUE(gts::is_sorted(arr1.begin(), arr1.end(), std::greater<int>()));
	EXPECT_TRUE(gts::is_sorted(arr2.begin(), arr2.end(), std::greater<int>()));
	EXPECT_TRUE(gts::is_sorted(arr3.begin(), arr3.end(), std::greater<int>()));
	EXPECT_TRUE(gts::is_sorted(arr4.begin(), arr4.end(), std::greater<int>()));
	EXPECT_TRUE(gts::is_sorted(arr5.begin(), arr5.end(), std::greater<int>()));
	EXPECT_TRUE(gts::is_sorted(arr6.begin(), arr6.end(), std::greater<int>()));
	EXPECT_TRUE(gts::is_sorted(empty_arr.begin(), empty_arr.end(), std::greater<int>()));
	EXPECT_TRUE(gts::is_sorted(rep_arr.begin(), rep_arr.end(), std::greater<int>()));

	gts::insertion_sort(ads.begin(), ads.end(), std::greater<int>());
	EXPECT_TRUE(is_sorted(ads.begin(), ads.end(), std::greater<int>()));
}

TEST_F(IntSortTests, DescQSortNotOpt)
{
	gts::qsort_not_opt(empty_arr.begin(), empty_arr.end(), std::greater<int>());
	gts::qsort_not_opt(arr1.begin(), arr1.end(), std::greater<int>());
	gts::qsort_not_opt(arr2.begin(), arr2.end(), std::greater<int>());
	gts::qsort_not_opt(arr3.begin(), arr3.end(), std::greater<int>());
	gts::qsort_not_opt(arr4.begin(), arr4.end(), std::greater<int>());
	gts::qsort_not_opt(arr5.begin(), arr5.end(), std::greater<int>());
	gts::qsort_not_opt(arr6.begin(), arr6.end(), std::greater<int>());
	gts::qsort_not_opt(rep_arr.begin(), rep_arr.end(), std::greater<int>());

	EXPECT_TRUE(gts::is_sorted(arr1.begin(), arr1.end(), std::greater<int>()));
	EXPECT_TRUE(gts::is_sorted(arr2.begin(), arr2.end(), std::greater<int>()));
	EXPECT_TRUE(gts::is_sorted(arr3.begin(), arr3.end(), std::greater<int>()));
	EXPECT_TRUE(gts::is_sorted(arr4.begin(), arr4.end(), std::greater<int>()));
	EXPECT_TRUE(gts::is_sorted(arr5.begin(), arr5.end(), std::greater<int>()));
	EXPECT_TRUE(gts::is_sorted(arr6.begin(), arr6.end(), std::greater<int>()));
	EXPECT_TRUE(gts::is_sorted(empty_arr.begin(), empty_arr.end(), std::greater<int>()));
	EXPECT_TRUE(gts::is_sorted(rep_arr.begin(), rep_arr.end(), std::greater<int>()));

	gts::qsort_not_opt(ads.begin(), ads.end(), std::greater<int>());
	EXPECT_TRUE(is_sorted(ads.begin(), ads.end(), std::greater<int>()));
}

TEST_F(IntSortTests, DescQSort)
{
	Array<int> qarr1(100);
	Array<int> qarr2(200);
	Array<int> qarr3(560);
	Array<int> qarr4(1000);
	Array<int> qarr5(10000);

	insert_randomly(qarr1, 100);
	insert_randomly(qarr2, 200);
	insert_randomly(qarr3, 560);
	insert_randomly(qarr4, 1000);
	insert_randomly(qarr5, 10000);

	gts::qsort(empty_arr.begin(), empty_arr.end(), std::greater<int>());
	gts::qsort(qarr1.begin(), qarr1.end(), std::greater<int>());
	gts::qsort(qarr2.begin(), qarr2.end(), std::greater<int>());
	gts::qsort(qarr3.begin(), qarr3.end(), std::greater<int>());
	gts::qsort(qarr4.begin(), qarr4.end(), std::greater<int>());
	gts::qsort(qarr5.begin(), qarr5.end(), std::greater<int>());

	EXPECT_TRUE(gts::is_sorted(qarr1.begin(), qarr1.end(), std::greater<int>()));
	EXPECT_TRUE(gts::is_sorted(qarr2.begin(), qarr2.end(), std::greater<int>()));
	EXPECT_TRUE(gts::is_sorted(qarr3.begin(), qarr3.end(), std::greater<int>()));
	EXPECT_TRUE(gts::is_sorted(qarr4.begin(), qarr4.end(), std::greater<int>()));
	EXPECT_TRUE(gts::is_sorted(qarr5.begin(), qarr5.end(), std::greater<int>()));
}

class StringSortTests : public ::testing::Test
{

public:
	Array<std::string> empty_arr;
	Array<std::string> arr1;
	Array<std::string> arr2;
	Array<std::string> arr3;
	Array<std::string> arr4;
	Array<std::string> arr5;
	Array<std::string> arr6;
	Array<std::string> arr7;
	Array<std::string> rep_arr;
	std::vector<std::string> ads;

	//Get a random seed from the OS entropy device, or whatever
	std::random_device rd;
	//Use the 64-bit Mersenne Twister 19937 generator
	//and seed it with entropy.
	std::mt19937_64 eng = std::mt19937_64(rd());

	Array<std::string> qarr1 = Array<std::string>(100);
	Array<std::string> qarr2 = Array<std::string>(200);
	Array<std::string> qarr3 = Array<std::string>(300);
	Array<std::string> qarr4 = Array<std::string>(400);
	Array<std::string> qarr5 = Array<std::string>(500);

	StringSortTests()
	{

	}

	~StringSortTests() override
	{

	}

	char alphabet[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'k', 'l', 'o' };

	void insert_randomly(Array<std::string>& arr, size_t size)
	{
		std::uniform_int_distribution<int> distr(0, 9);
		for (size_t i = 0; i < size; i++)
		{
			arr.Insert(std::string());
			for (size_t j = 0; j < 5; j++)
			{
				arr[i].push_back(alphabet[distr(eng)]);
			}
		}
	}

	void SetUp() override
	{
		empty_arr = {};
		arr1 = { "abz" };
		arr2 = { "a", "z", "x" };
		arr3 = { "a", "z", "x", "f" };
		arr4 = { "l", "ü", "z", "t", "xz" };
		arr5 = { "zxczxcasd", "asdzx", "awer", "amicoho" };
		arr6 = { "fasfaf", "dsadasda", "asdasda", "zxzxzx" };
		rep_arr = { "ami cochon", "ami cochon", "ami cochon", "ami cochon" };
		ads = { "zxczxcasd", "asdzx", "awer", "amicoho" };
	};

	void TearDown() override
	{

	};
};

TEST_F(StringSortTests, IsGetPivotCorrect)
{
	std::string mid = "b";
	Array<std::string> arr1{ "c", "a", "b" };
	Array<std::string> arr2{ "a", "c", "b" };
	Array<std::string> arr3{ "c", "b", "a" };
	Array<std::string> arr4{ "a", "b", "c" };
	Array<std::string> arr5{ "b", "c", "a" };
	Array<std::string> arr6{ "b", "a", "c" };

	std::vector<std::string> arr7{ "c", "a", "b" };
	EXPECT_EQ(gts::get_pivot(arr7.cbegin(), arr7.cend() - 1, std::greater<std::string>()), mid);

	EXPECT_EQ(gts::get_pivot(arr1.cbegin(), arr1.cend() - 1, std::greater<std::string>()), mid);
	EXPECT_EQ(gts::get_pivot(arr2.cbegin(), arr2.cend() - 1, std::greater<std::string>()), mid);
	EXPECT_EQ(gts::get_pivot(arr3.cbegin(), arr3.cend() - 1, std::greater<std::string>()), mid);
	EXPECT_EQ(gts::get_pivot(arr4.cbegin(), arr4.cend() - 1, std::greater<std::string>()), mid);
	EXPECT_EQ(gts::get_pivot(arr5.cbegin(), arr5.cend() - 1, std::greater<std::string>()), mid);
	EXPECT_EQ(gts::get_pivot(arr6.cbegin(), arr6.cend() - 1, std::greater<std::string>()), mid);

	EXPECT_EQ(gts::get_pivot(arr1.cbegin(), arr1.cend() - 1, std::less<std::string>()), mid);
	EXPECT_EQ(gts::get_pivot(arr2.cbegin(), arr2.cend() - 1, std::less<std::string>()), mid);
	EXPECT_EQ(gts::get_pivot(arr3.cbegin(), arr3.cend() - 1, std::less<std::string>()), mid);
	EXPECT_EQ(gts::get_pivot(arr4.cbegin(), arr4.cend() - 1, std::less<std::string>()), mid);
	EXPECT_EQ(gts::get_pivot(arr5.cbegin(), arr5.cend() - 1, std::less<std::string>()), mid);
	EXPECT_EQ(gts::get_pivot(arr6.cbegin(), arr6.cend() - 1, std::less<std::string>()), mid);
}

TEST_F(StringSortTests, AscInsertionSort)
{
	gts::insertion_sort(empty_arr.begin(), empty_arr.end(), std::less<std::string>());
	gts::insertion_sort(arr1.begin(), arr1.end(), std::less<std::string>());
	gts::insertion_sort(arr2.begin(), arr2.end(), std::less<std::string>());
	gts::insertion_sort(arr3.begin(), arr3.end(), std::less<std::string>());
	gts::insertion_sort(arr4.begin(), arr4.end(), std::less<std::string>());
	gts::insertion_sort(arr5.begin(), arr5.end(), std::less<std::string>());
	gts::insertion_sort(arr6.begin(), arr6.end(), std::less<std::string>());
	gts::insertion_sort(rep_arr.begin(), rep_arr.end(), std::less<std::string>());

	EXPECT_TRUE(gts::is_sorted(arr1.begin(), arr1.end(), std::less<std::string>()));
	EXPECT_TRUE(gts::is_sorted(arr2.begin(), arr2.end(), std::less<std::string>()));
	EXPECT_TRUE(gts::is_sorted(arr3.begin(), arr3.end(), std::less<std::string>()));
	EXPECT_TRUE(gts::is_sorted(arr4.begin(), arr4.end(), std::less<std::string>()));
	EXPECT_TRUE(gts::is_sorted(arr5.begin(), arr5.end(), std::less<std::string>()));
	EXPECT_TRUE(gts::is_sorted(arr6.begin(), arr6.end(), std::less<std::string>()));
	EXPECT_TRUE(gts::is_sorted(empty_arr.begin(), empty_arr.end(), std::less<std::string>()));
	EXPECT_TRUE(gts::is_sorted(rep_arr.begin(), rep_arr.end(), std::less<std::string>()));

	gts::insertion_sort(ads.begin(), ads.end(), std::less<std::string>());
	EXPECT_TRUE(is_sorted(ads.begin(), ads.end(), std::less<std::string>()));
}

TEST_F(StringSortTests, AscQSortNotOpt)
{
	gts::qsort_not_opt(empty_arr.begin(), empty_arr.end(), std::less<std::string>());
	gts::qsort_not_opt(arr1.begin(), arr1.end(), std::less<std::string>());
	gts::qsort_not_opt(arr2.begin(), arr2.end(), std::less<std::string>());
	gts::qsort_not_opt(arr3.begin(), arr3.end(), std::less<std::string>());
	gts::qsort_not_opt(arr4.begin(), arr4.end(), std::less<std::string>());
	gts::qsort_not_opt(arr5.begin(), arr5.end(), std::less<std::string>());
	gts::qsort_not_opt(arr6.begin(), arr6.end(), std::less<std::string>());
	gts::qsort_not_opt(rep_arr.begin(), rep_arr.end(), std::less<std::string>());

	EXPECT_TRUE(gts::is_sorted(arr1.begin(), arr1.end(), std::less<std::string>()));
	EXPECT_TRUE(gts::is_sorted(arr2.begin(), arr2.end(), std::less<std::string>()));
	EXPECT_TRUE(gts::is_sorted(arr3.begin(), arr3.end(), std::less<std::string>()));
	EXPECT_TRUE(gts::is_sorted(arr4.begin(), arr4.end(), std::less<std::string>()));
	EXPECT_TRUE(gts::is_sorted(arr5.begin(), arr5.end(), std::less<std::string>()));
	EXPECT_TRUE(gts::is_sorted(arr6.begin(), arr6.end(), std::less<std::string>()));
	EXPECT_TRUE(gts::is_sorted(empty_arr.begin(), empty_arr.end(), std::less<std::string>()));
	EXPECT_TRUE(gts::is_sorted(rep_arr.begin(), rep_arr.end(), std::less<std::string>()));

	gts::qsort_not_opt(ads.begin(), ads.end(), std::less<std::string>());
	EXPECT_TRUE(is_sorted(ads.begin(), ads.end(), std::less<std::string>()));
}

TEST_F(StringSortTests, AscQSort)
{
	insert_randomly(qarr1, 100);
	insert_randomly(qarr2, 200);
	insert_randomly(qarr3, 300);
	insert_randomly(qarr4, 400);
	insert_randomly(qarr5, 500);

	gts::qsort(empty_arr.begin(), empty_arr.end(), std::less<std::string>());
	gts::qsort(qarr1.begin(), qarr1.end(), std::less<std::string>());
	gts::qsort(qarr2.begin(), qarr2.end(), std::less<std::string>());
	gts::qsort(qarr3.begin(), qarr3.end(), std::less<std::string>());
	gts::qsort(qarr4.begin(), qarr4.end(), std::less<std::string>());
	gts::qsort(qarr5.begin(), qarr5.end(), std::less<std::string>());
	gts::qsort(rep_arr.begin(), rep_arr.end(), std::less<std::string>());

	EXPECT_TRUE(gts::is_sorted(qarr1.begin(), qarr1.end(), std::less<std::string>()));
	EXPECT_TRUE(gts::is_sorted(qarr2.begin(), qarr2.end(), std::less<std::string>()));
	EXPECT_TRUE(gts::is_sorted(qarr3.begin(), qarr3.end(), std::less<std::string>()));
	EXPECT_TRUE(gts::is_sorted(qarr4.begin(), qarr4.end(), std::less<std::string>()));
	EXPECT_TRUE(gts::is_sorted(qarr5.begin(), qarr5.end(), std::less<std::string>()));
	EXPECT_TRUE(gts::is_sorted(empty_arr.begin(), empty_arr.end(), std::less<std::string>()));
	EXPECT_TRUE(gts::is_sorted(rep_arr.begin(), rep_arr.end(), std::less<std::string>()));
}

TEST_F(StringSortTests, DescInsertionSort)
{
	gts::insertion_sort(empty_arr.begin(), empty_arr.end(), std::greater<std::string>());
	gts::insertion_sort(arr1.begin(), arr1.end(), std::greater<std::string>());
	gts::insertion_sort(arr2.begin(), arr2.end(), std::greater<std::string>());
	gts::insertion_sort(arr3.begin(), arr3.end(), std::greater<std::string>());
	gts::insertion_sort(arr4.begin(), arr4.end(), std::greater<std::string>());
	gts::insertion_sort(arr5.begin(), arr5.end(), std::greater<std::string>());
	gts::insertion_sort(arr6.begin(), arr6.end(), std::greater<std::string>());
	gts::insertion_sort(rep_arr.begin(), rep_arr.end(), std::greater<std::string>());

	EXPECT_TRUE(gts::is_sorted(arr1.begin(), arr1.end(), std::greater<std::string>()));
	EXPECT_TRUE(gts::is_sorted(arr2.begin(), arr2.end(), std::greater<std::string>()));
	EXPECT_TRUE(gts::is_sorted(arr3.begin(), arr3.end(), std::greater<std::string>()));
	EXPECT_TRUE(gts::is_sorted(arr4.begin(), arr4.end(), std::greater<std::string>()));
	EXPECT_TRUE(gts::is_sorted(arr5.begin(), arr5.end(), std::greater<std::string>()));
	EXPECT_TRUE(gts::is_sorted(arr6.begin(), arr6.end(), std::greater<std::string>()));
	EXPECT_TRUE(gts::is_sorted(empty_arr.begin(), empty_arr.end(), std::greater<std::string>()));
	EXPECT_TRUE(gts::is_sorted(rep_arr.begin(), rep_arr.end(), std::greater<std::string>()));

	gts::insertion_sort(ads.begin(), ads.end(), std::greater<std::string>());
	EXPECT_TRUE(is_sorted(ads.begin(), ads.end(), std::greater<std::string>()));
}

TEST_F(StringSortTests, DescQSortNotOpt)
{
	gts::qsort_not_opt(empty_arr.begin(), empty_arr.end(), std::greater<std::string>());
	gts::qsort_not_opt(arr1.begin(), arr1.end(), std::greater<std::string>());
	gts::qsort_not_opt(arr2.begin(), arr2.end(), std::greater<std::string>());
	gts::qsort_not_opt(arr3.begin(), arr3.end(), std::greater<std::string>());
	gts::qsort_not_opt(arr4.begin(), arr4.end(), std::greater<std::string>());
	gts::qsort_not_opt(arr5.begin(), arr5.end(), std::greater<std::string>());
	gts::qsort_not_opt(arr6.begin(), arr6.end(), std::greater<std::string>());
	gts::qsort_not_opt(rep_arr.begin(), rep_arr.end(), std::greater<std::string>());

	EXPECT_TRUE(gts::is_sorted(arr1.begin(), arr1.end(), std::greater<std::string>()));
	EXPECT_TRUE(gts::is_sorted(arr2.begin(), arr2.end(), std::greater<std::string>()));
	EXPECT_TRUE(gts::is_sorted(arr3.begin(), arr3.end(), std::greater<std::string>()));
	EXPECT_TRUE(gts::is_sorted(arr4.begin(), arr4.end(), std::greater<std::string>()));
	EXPECT_TRUE(gts::is_sorted(arr5.begin(), arr5.end(), std::greater<std::string>()));
	EXPECT_TRUE(gts::is_sorted(arr6.begin(), arr6.end(), std::greater<std::string>()));
	EXPECT_TRUE(gts::is_sorted(empty_arr.begin(), empty_arr.end(), std::greater<std::string>()));
	EXPECT_TRUE(gts::is_sorted(rep_arr.begin(), rep_arr.end(), std::greater<std::string>()));

	gts::qsort_not_opt(ads.begin(), ads.end(), std::greater<std::string>());
	EXPECT_TRUE(is_sorted(ads.begin(), ads.end(), std::greater<std::string>()));
}

TEST_F(StringSortTests, DescQSort)
{
	Array<std::string> qarr1(100);
	Array<std::string> qarr2(200);
	Array<std::string> qarr3(300);
	Array<std::string> qarr4(400);
	Array<std::string> qarr5(500);

	insert_randomly(qarr1, 100);
	insert_randomly(qarr2, 200);
	insert_randomly(qarr3, 300);
	insert_randomly(qarr4, 400);
	insert_randomly(qarr5, 500);

	gts::qsort(empty_arr.begin(), empty_arr.end(), std::greater<std::string>());
	gts::qsort(qarr1.begin(), qarr1.end(), std::greater<std::string>());
	gts::qsort(qarr2.begin(), qarr2.end(), std::greater<std::string>());
	gts::qsort(qarr3.begin(), qarr3.end(), std::greater<std::string>());
	gts::qsort(qarr4.begin(), qarr4.end(), std::greater<std::string>());
	gts::qsort(qarr5.begin(), qarr5.end(), std::greater<std::string>());
	gts::qsort(rep_arr.begin(), rep_arr.end(), std::greater<std::string>());

	EXPECT_TRUE(gts::is_sorted(qarr1.begin(), qarr1.end(), std::greater<std::string>()));
	EXPECT_TRUE(gts::is_sorted(qarr2.begin(), qarr2.end(), std::greater<std::string>()));
	EXPECT_TRUE(gts::is_sorted(qarr3.begin(), qarr3.end(), std::greater<std::string>()));
	EXPECT_TRUE(gts::is_sorted(qarr4.begin(), qarr4.end(), std::greater<std::string>()));
	EXPECT_TRUE(gts::is_sorted(qarr5.begin(), qarr5.end(), std::greater<std::string>()));
	EXPECT_TRUE(gts::is_sorted(empty_arr.begin(), empty_arr.end(), std::greater<std::string>()));
	EXPECT_TRUE(gts::is_sorted(rep_arr.begin(), rep_arr.end(), std::greater<std::string>()));
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	return 1;
}
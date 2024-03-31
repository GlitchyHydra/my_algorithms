#include "hzpch.h"
#include "gtest/gtest.h"
#include <gtest/gtest.h>

#include "Strings.h"

namespace StringTests {
    class StoiTests : public ::testing::Test
    {

    public:

        StoiTests()
        {

        }

        ~StoiTests() override
        {

        }


        void SetUp() override
        {
        };

        void TearDown() override
        {

        };
    };

    TEST_F(StoiTests, IsSimpleCasesCorrect)
    {
        int num;
        std::string str = "";
        EXPECT_FALSE (stoi(str, num));

        str = "4aa4";
        EXPECT_FALSE (stoi(str, num));

        str = "-a";
        EXPECT_FALSE (stoi(str, num));

        str = "1-23";
        EXPECT_FALSE (stoi(str, num));

        str = "123-";
        EXPECT_FALSE (stoi(str, num));

        str = "-123";
        EXPECT_TRUE (stoi(str, num));
        EXPECT_EQ (num, -123);

        str = "+123";
        EXPECT_TRUE (stoi(str, num));
        EXPECT_EQ (num, 123);
    }

    TEST_F(StoiTests, IsOverflowCasesCorrect)
    {
        int num;
        std::string str = std::to_string (INT_MAX);
        str.push_back('a');
        EXPECT_FALSE (stoi(str, num));

        str = std::to_string (INT_MAX);
        str.push_back('a');
        EXPECT_FALSE (stoi(str, num));

        str = std::to_string (INT_MIN);
        EXPECT_TRUE (stoi(str, num));
        EXPECT_EQ (num, INT_MIN);

        str = std::to_string (INT_MAX);
        EXPECT_TRUE (stoi(str, num));
        EXPECT_EQ (num, INT_MAX);
    }

    class MulSumTests : public ::testing::Test
    {

    public:

        MulSumTests()
        {

        }

        ~MulSumTests() override
        {

        }


        void SetUp() override
        {
        };

        void TearDown() override
        {

        };
    };

    TEST_F(MulSumTests, CheckSimple)
    {
        std::string str = "12+1*1*5+2*3+13";
        EXPECT_EQ (perform_mul_sum_operations (str), 36);

        str = "12";
        EXPECT_EQ (perform_mul_sum_operations (str), 12);

        str = "12+1";
        EXPECT_EQ (perform_mul_sum_operations (str), 13);

        str = "12*1";
        EXPECT_EQ (perform_mul_sum_operations (str), 12);

        str = "12*1";
        EXPECT_EQ (perform_mul_sum_operations (str), 12);

        str = "12*1*3*2+1";
        EXPECT_EQ (perform_mul_sum_operations (str), 73);

        str = "12+1*3*1";
        EXPECT_EQ (perform_mul_sum_operations (str), 15);
    }
}



int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 1;
}
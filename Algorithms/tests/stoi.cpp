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

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

int dfsNextValue (ListNode* node, int prevNum, int left, std::pair<int,int>& rightIndices, std::vector<int>& res) {
    if (!node->next)
        return node->val;

    int currentNum = node->val;
    int nextNum = dfsNextValue(node->next, node->val, left + 1, rightIndices, res);
    if (!(currentNum > nextNum && currentNum > prevNum ||
        currentNum < nextNum && currentNum < prevNum)) {
        return node->val;
    }

    if (rightIndices.second > -1) {
        res[0] = std::min (res[0], rightIndices.first - left);
        res[1] = rightIndices.second - left;
        rightIndices.first = left;
    } else {
        rightIndices.first = left;
        rightIndices.second = left;
    }

    return node->val;
}

    std::vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        std::pair<int, int> rightIndices {-1, -1};
        std::vector<int> res { INT_MAX, -1 };
        dfsNextValue (head, head->val, 0, rightIndices, res);
        return res[0] == INT_MAX ? std::vector {-1, -1} : res; 
    }

    //5,3,1,2,5,1,2
int main(int argc, char** argv)
{
    ListNode* head = new ListNode(5);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next = new ListNode(2);
    nodesBetweenCriticalPoints (head);
    /*::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();*/
    return 1;
}
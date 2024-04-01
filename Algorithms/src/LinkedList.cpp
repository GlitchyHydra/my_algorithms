#include "hzpch.h"
#include "LinkedList.h"

//Example: 5,3,1,2,5,1,2
int dfsNextValue (ListNode* node, int prevNum, int left, int& rightIdx, std::vector<int>& res) {
    if (!node->next)
        return node->val;

    int currentNum = node->val;
    int nextNum = dfsNextValue(node->next, node->val, left + 1, rightIdx, res);
    if (!(currentNum > nextNum && currentNum > prevNum ||
        currentNum < nextNum && currentNum < prevNum)) {
        return node->val;
    }

    if (rightIdx > -1) {
        int distance = rightIdx - left;
        res[0] = std::min (res[0], distance);
        res[1] += distance;
        rightIdx = left;
    } else
        rightIdx = left;

    return node->val;
}

std::vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    int rightIdx = -1;
    std::vector<int> res { INT_MAX, 0 };
    dfsNextValue (head, head->val, 0, rightIdx, res);
    return res[0] == INT_MAX ? std::vector {-1, -1} : res; 
}
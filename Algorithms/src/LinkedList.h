#pragma once



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
std::vector<int> nodesBetweenCriticalPoints(ListNode* head);
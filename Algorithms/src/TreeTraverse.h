#pragma once

// На вход дается непустое бинарное дерево.
// Найти максимальную сумму пути в этом дереве.
// "Путь" в бинарном дереве -- последовательность узлов, связанных отношениями родитель--потомок.
// Путь должен содержать как минимум один узел.
// Пример 1
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int findMaxPathSum(TreeNode* root, int& maxSubtreeSum);


int getMaxSumDFS (TreeNode* node, int& pathSum) {
    if (!node)
        return 0;

    int leftSum = getMaxSumDFS (node->left, pathSum);
    int rightSum = getMaxSumDFS (node->right, pathSum);

    int maxSubtreeSum = std::max (leftSum, rightSum);
    int currentMaxSum = std::max(maxSubtreeSum + node->val, node->val);
    int maxSum = std::max (currentMaxSum, leftSum + rightSum + node->val);
    pathSum = std::max (maxSum, pathSum);
    return currentMaxSum;
}

int findMaxPathSum (TreeNode* root) {
    int result = INT_MIN;
    getMaxSumDFS (root, result);
    return result;
}
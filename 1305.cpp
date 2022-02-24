#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void getElements(TreeNode *root)
    {
        if (root == nullptr)
            return;
        sortedList.push_back(root->val);
        getElements(root->left);
        getElements(root->right);
    }

    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        getElements(root1);
        getElements(root2);
        sort(sortedList.begin(), sortedList.end());

        return sortedList;
    }

    vector<int> sortedList;
};

int main()
{
    Solution sol;
    TreeNode root1(2);
    TreeNode root2(1);
    vector<int> arr = sol.getAllElements(&root1, &root2);
    return 0;
}
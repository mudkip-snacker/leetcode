#include <queue>
using namespace std;

// Definition for a binary tree node.
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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int depth = 0;
        queue<TreeNode *> q;
        queue<TreeNode *> q2;
        q.push(root);

        TreeNode *curr;
        while (!q.empty())
        {
            swap(q, q2);
            while (!q2.empty())
            {
                curr = q2.front();
                q2.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            depth++;
        }

        return depth;
    }
};
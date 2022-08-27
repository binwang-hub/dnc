#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        queue<TreeNode*> que;
        vector<vector<int>> result;

        if(root != NULL)
        {
            que.push(root);
        }

        while(!que.empty())
        {
            vector<int> temp;

            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                temp.push_back(node->val);

                if(node->left){
                    que.push(node->left);
                }

                if(node->right){
                    que.push(node->right);
                }
            }

            result.push_back(temp);
        }
        return result;
    }
    
    TreeNode* solve(TreeNode *root){
        if(root && root->val < 0){
            root = nullptr;
            return root;
        }
        
        if(root->left && root->val + root->left->val < 0){
            root->left = nullptr;
        }
        else{
            solve(root->left);
        }
        
        if(root->right && root->val + root->right->val < 0){
            root->right = nullptr;
        }
        else{
            solve(root->right);
        }
        
        return root;
    }
};

int main()
{
    TreeNode root(3);
    TreeNode node1(9);
    TreeNode node2(-20);
    TreeNode node3(15);
    TreeNode node4(7);
    root.left = &node1;
    root.right = &node2;
    node2.left = &node3;
    node2.right = &node4;

    Solution s;
    s.solve(&root);
    for (const auto &v : s.levelOrder(&root))
    {
        for (auto i : v)
            std::cout << i << " ";
        std::cout << std::endl;
    }

    return 0;
}

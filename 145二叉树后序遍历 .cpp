// 二叉树的后序遍历是在栈1中  先压头 再压左子树 最后压右子树   头左右
// 在栈2中 

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int>result;
        if (root != nullptr)
        {
            stack<TreeNode*>s1;
            stack<TreeNode*>s2;
            s1.push(root);
            while(!s1.empty())
            {
                TreeNode* temp = s1.top();
                s1.pop();
                s2.push(temp);

                if (temp->left)
                {
                    s1.push(temp->left);
                }

                if (temp->right)
                {
                    s1.push(temp->right);
                }
            }

            while(!s2.empty())
            {
                TreeNode* temp = s2.top();
                result.push_back(temp->val);
                s2.pop();
            }
        }
        return result;
    }
};
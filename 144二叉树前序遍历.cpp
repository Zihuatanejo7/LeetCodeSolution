// 二叉树得前序遍历是先压右子树   再压左子树

class Solution 
{
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int>result;
        if(root!=nullptr)
        {
            stack<TreeNode*>s;
            s.push(root);
            while(!s.empty())
            {
                TreeNode* temp = s.top();
                s.pop();
                result.push_back(temp->val);
                if (temp->right)
                {
                    s.push(temp->right);
                }
                if (temp->left)
                {
                    s.push(temp->left);
                }

            }
            
        }
        return result;
    }
};
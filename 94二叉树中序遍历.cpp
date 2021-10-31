// 中序遍历  先把左边界 全部压入栈

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int>result;
        stack<TreeNode*>s;
        while(root || !s.empty())
        {
			// 左边界全压栈
            while(root)
            {
                s.push(root);
                root=root->left;
            }
			
            if (!s.empty())
            {
                root= s.top();
                s.pop();
                result.push_back(root->val);
                root= root->right;
            }

        }  
        return result;
    }
};
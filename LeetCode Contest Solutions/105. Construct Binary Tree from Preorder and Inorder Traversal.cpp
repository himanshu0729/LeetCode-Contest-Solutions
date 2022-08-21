    TreeNode* build(vector<int>& preorder, int preLeft, int preRight, vector<int>& inorder, int inLeft, int inRight, unordered_map<int, int> &imp){
        
        if(preLeft > preRight || inLeft > inRight)
            return NULL;
        
        TreeNode *curr = new TreeNode(preorder[preLeft]);
        int idx = imp[preorder[preLeft]];
        int left = idx - inLeft;
        
        curr->left = build(preorder, preLeft + 1, preLeft + left, inorder, inLeft, idx-1, imp);
        curr->right = build(preorder, preLeft + left + 1, preRight, inorder, idx + 1, inRight, imp);
            
        return curr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> imp;
        int n = inorder.size();
        for(int i = 0; i < n; i++){
            imp[inorder[i]] = i;
        }
        
        return build(preorder, 0, n-1, inorder, 0, n-1, imp);
    }

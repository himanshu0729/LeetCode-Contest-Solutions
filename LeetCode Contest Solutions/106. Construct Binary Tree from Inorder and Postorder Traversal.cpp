    TreeNode* build(vector<int>& postorder, int postLeft, int postRight, vector<int>& inorder, int inLeft, int inRight,  unordered_map<int, int> &imp){
        if(postLeft > postRight || inLeft > inRight){
            return NULL;
        }
        
        TreeNode *curr = new TreeNode(postorder[postRight]);
        int idx = imp[postorder[postRight]];
        int left = idx - inLeft;
        
        curr->left = build(postorder, postLeft, postLeft + left - 1, inorder, inLeft, idx-1, imp);
        curr->right = build(postorder, postLeft + left, postRight-1, inorder, idx+1, inRight, imp);
            
        return curr;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> imp;
        int n = inorder.size();
        for(int i = 0; i < n; i++){
            imp[inorder[i]] = i;
        }
        
        return build(postorder, 0, n-1, inorder, 0, n-1, imp);
    }

    TreeNode* createTree(TreeNode *root1, TreeNode *root2){
        
        if(root1 == NULL && root2 == NULL) 
            return NULL;
        
        
        else if(root1 != NULL && root2 == NULL)
            return root1;
        
        
        else if(root2 != NULL && root1 == NULL)
            return root2;
        
        else 
            root1->val = root1->val + root2->val;
        
        root1->left = createTree(root1->left, root2->left);
        root1->right = createTree(root1->right, root2->right);
        
        return root1;
        
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        if(root1 == NULL)
            return root2;
        if(root2 == NULL)
            return root1;
        
        TreeNode *root = createTree(root1, root2);
        
        return root;
    }

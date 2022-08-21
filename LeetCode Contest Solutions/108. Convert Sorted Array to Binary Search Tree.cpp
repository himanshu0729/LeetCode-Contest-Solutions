    TreeNode* buildTree(vector<int>& nums, int left, int right){
        
        if(left > right)
            return NULL;
        
        int mid = (left + right) / 2;
        
        TreeNode* curr = new TreeNode(nums[mid]);
        
        curr->left = buildTree(nums, left, mid-1);
        curr->right = buildTree(nums, mid+1, right);
        
        return curr;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return NULL;
        return buildTree(nums, 0, n-1);
    }

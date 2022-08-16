    int count = 0;
    unordered_map<long, int> mp;
    
    void countPath(TreeNode *root, long long sum, int targetSum){
        if(root == NULL)
            return;
   
        sum += root->val;
        
        if(sum == targetSum)
            count++;
        
        if(mp.find(sum - targetSum) != mp.end())
            count += mp[sum-targetSum];
      
        mp[sum]++;
        countPath(root->left, sum , targetSum);
        countPath(root->right, sum, targetSum);
        mp[sum]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        countPath(root, 0, targetSum);
        return count;
    }

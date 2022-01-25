108. Convert Sorted Array to Binary Search Tree
Easy

5606

334

Add to List

Share
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

 

Example 1:


Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:



//---------------------------------------------------------------------- revursive ---------------------------------------------------------------------------------

 TreeNode* helper(vector<int>nums, int i, int j){
        if(i>j){
            return NULL;
        }
        int mid=(i+j)/2;
        TreeNode* t=new TreeNode(nums[mid]);
        t->left=helper(nums,i,mid-1);
        t->right=helper(nums,mid+1,j);
        return t;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }



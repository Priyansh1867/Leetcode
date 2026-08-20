/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root , priority_queue<int,vector<int>,greater<int>>&pq)
    {
        // Base case: return if the current node is null
        if(!root) return; 
        // Push current node's value into the priority queue (min-heap)
        pq.push(root->val);
        // Recursively traverse the left and right subtrees
        traverse(root->left,pq);
        traverse(root->right,pq);
    }
    int getMinimumDifference(TreeNode* root) {// Recursively traverse the left and right subtrees$0
        priority_queue<int , vector<int> , greater<int>>pq; //Minimum element top pr aa jayega;
        // Step 1: Traverse the tree and insert all elements into the min-heap
        traverse(root , pq);

        // Initialize minimum difference with the maximum possible integer value
        int Min_Diff = INT_MAX;
        // Extract the smallest element to serve as the initial previous value
        int prev = pq.top();
        pq.pop();

        // Step 2: Process remaining elements in sorted order to find the minimum adjacent difference
        while(!pq.empty())
        {
            int curr = pq.top();
            pq.pop();
            // Update minimum difference between consecutive sorted values
            Min_Diff = min(Min_Diff , curr - prev);
            // Move current element to previous for the next comparison
            prev = curr;
        }
        return Min_Diff;
    }
};
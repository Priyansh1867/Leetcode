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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true; // agar dono NULL hue toh true
        else if(p == NULL || q == NULL || p->val != q->val) return false; // ek bhi different hua toh false

        //pehle left jayege and then right jayege agar same aata gya toh true else false.
        if(isSameTree(p->left,q->left) && isSameTree(p->right , q->right)) return true;
        else return false;
    }
};
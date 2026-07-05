// // //Description
// // Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

// // Assume a BST is defined as follows:

// // The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.


/* Approach:
1.Created a data structure which takes values (sum,isBST,maxval,minval)
2.Created a helper function which uses postorder traversal and moves to the leftmost node
3.It checks the root if it is null assigns sum of 0,and valid bst as individual nodes are also valid,minval as INT_MAX so that the
next root value is always smaller and same for maxval
4.Checked if the node followed all properties of the bst,if it does then save the current sum and save the maxsum as the maximum value 
of currsum and itself and defined the value to be returned to the parentnode.
5.If it does not follow the BST condition return the sum=0,isBST false and dummy values.


*/
 //* Definition for a binary tree node.

#include <climits>
#include <algorithm>
using namespace std;
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

struct SubtreeInfo {
    int sum;
    bool isBST;
    int maxval;   // Largest value in this subtree
    int minval;  // Smallest value in this subtree

    SubtreeInfo(int s, bool bst, int maxL, int minR): sum(s), isBST(bst), maxval(maxL), minval(minR) {}
};
class Solution {
private:
    SubtreeInfo helper(TreeNode*root, int& maxsum){
        if(!root) return SubtreeInfo(0,true,INT_MIN,INT_MAX);

        SubtreeInfo left=helper(root->left,maxsum);
        SubtreeInfo right=helper(root->right,maxsum);

        if(left.isBST && right.isBST && root->val>left.maxval && root->val<right.minval){
            int currsum=root->val+left.sum+right.sum;
            maxsum=max(currsum,maxsum);
            int currentMin = min(root->val, left.minval);
            int currentMax = max(root->val, right.maxval);

            return SubtreeInfo(currsum, true, currentMax, currentMin);
        }
        return SubtreeInfo(0, false, 0, 0);

    }
public:
    int maxSumBST(TreeNode* root) {
        int maxsum=0;
        helper(root,maxsum);
        return maxsum;
        
    }
};

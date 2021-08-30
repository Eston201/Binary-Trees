#include<iostream>

using namespace std;





struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p==nullptr && q == nullptr){
            return true;
        }

        else if(p != nullptr && q != nullptr){
            return((p->val == q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
        }
        
        else{
            return false;
        }

    }

    int maxDepth(TreeNode* root) {
        
        if(root == nullptr){
            return 0;
        }

        else{
            int ldepth = maxDepth(root->left);
            int rdepth = maxDepth(root->right);
            //the plus one accounts for the root node of each subtree
            if(ldepth > rdepth){
                return(ldepth+1);
            }
            else{
                return(rdepth+1);
            }
        }
    }

    bool hasPathSum(TreeNode *root , int target){
        
        if(root == nullptr){
            return false;;
        }
        target -= root->val;
        if(root->left==nullptr && root->right==nullptr){
            if(target ==0){
                return true;
            }
        }
         return hasPathSum(root->left, target) || hasPathSum(root->right, target);


    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == nullptr){
            return 0;
        }
        int lheigth = maxDepth(root->left);
        int rheight = maxDepth(root->right);
        int ldia = diameterOfBinaryTree(root->left);
        int rdia = diameterOfBinaryTree(root->right);

        return max(lheigth+rheight,max(ldia,rdia));
    }


};

int main(){

    Solution sol;

    
    TreeNode *c = new TreeNode(2);
    TreeNode *root = new TreeNode(1,c,nullptr);
   
    cout << sol.diameterOfBinaryTree(root);
    
    return 0;


}

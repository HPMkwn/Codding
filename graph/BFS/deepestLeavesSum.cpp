#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int deepestLeavesSum(TreeNode* root) {
    if(!root)return 0;
    queue<TreeNode* > q;
    q.push(root);

    while(!q.empty()){
        int count=0;
        int i = q.size();
        bool isDeepest = false;
        while (i--)
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->left || node->right){
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                isDeepest=true;
            }else{
                count += node->val;
            }
        }

        if(isDeepest){
            return count;
        }
    }
    return 0;
}

int main(){
    
    return 0;
}


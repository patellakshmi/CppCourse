//
// Created by Lakshmi S Patel on 23/05/21.
//

#ifndef CPPCOURSE_MAXPATHSUMINBT_H
#define CPPCOURSE_MAXPATHSUMINBT_H

#include <iostream>
#include <map>
#include <vector>
using namespace std;

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

    int max(int a, int b, int c, int d){
        return max(a, max(b, c, d));
    }

    int max(int a, int b, int c){
        return max(a, max(b,c));
    }

    int max(int a, int b){
        if( a > b ) return a;
        return b;
    }

    int maxPathSumUtil(TreeNode *root, int &maxPath){

        if( root == nullptr) return 0;

        if( root->left == nullptr && root->right == nullptr){
            if( maxPath < root->val ) maxPath = root->val;
            return root->val;
        }

        int left = 0;
        int right = 0;

        if( root->left != nullptr) left = maxPathSumUtil(root->left, maxPath);
        if( root->right != nullptr) right = maxPathSumUtil(root->right, maxPath);

        maxPath = ( root->left != nullptr) && ( root->right != nullptr) ?                                 max(
                max(maxPath,left,right,root->val),
                max(left+root->val,right+root->val,left+right+root->val)
        ): maxPath;

        maxPath = ( root->right != nullptr) ?
                  max(maxPath,right,root->val,right+root->val): maxPath;

        maxPath = ( root->left != nullptr) ?
                  max(maxPath,left, root->val,left+root->val): maxPath;

        if( left < 0 && right < 0 ) return root->val;
        if( left < 0 ) return right+root->val;
        if( right < 0 ) return left+root->val;
        if( left+root->val > right+root->val) return left+root->val;
        else return right+root->val;


    }

    int solve(TreeNode *root, int &maxPath){
        if( root == nullptr) return 0;
        int left = solve(root->left, maxPath);
        int right = solve(root->right, maxPath);
        int temp = max(left+root->val, right+root->val, root->val);
        maxPath = max(maxPath, temp, left+right+root->val);
        return temp;
    }


    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        solve(root, maxPath);
        return maxPath;
    }
};

#endif //CPPCOURSE_MAXPATHSUMINBT_H

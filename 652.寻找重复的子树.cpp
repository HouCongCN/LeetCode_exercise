/*
 * @Author: HouCong
 * @Date: 2020-01-07 16:15:11
 * @LastEditTime : 2020-01-09 21:56:12
 * @Description: file content
 * @FilePath: \LeetCode_exercise\652.寻找重复的子树.cpp
 */
/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    /*
     * 1. 遍历二叉树，将每个子树序列化
     * //!2. 每个子树的存储方式为string，并利用递归深度搜索
     * 3. 建立map，key为子树string，value为出现次数
     */ 

    string DFS(vector<TreeNode*> res, TreeNode* root, unordered_map<string, int> m)  
    {
        //* 填补空结点，保证每个子树序列化后结构类似，方便比较
        if (root == NULL) return "#";
        //! to_string的使用
        string tmp = to_string(root->val) + DFS(res, root->left, m) + DFS(res, root->right, m);
        if (m[tmp] == 1)
            res.push_back(root);
        m[tmp]++;   
        
        return tmp;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        unordered_map<string, int> m;
        if (root == NULL)
            return result;
        
        DFS(result, root, m);
        return result;
    }
};
// @lc code=end


/*
 * @Author: your name
 * @Date: 2020-01-02 20:01:05
 * @LastEditTime : 2020-01-02 20:47:41
 * @LastEditors  : Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \LeetCode\1.两数之和.cpp
 */
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:   
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        // vector<int> r;
        int size = nums.size();
        //* 3.一次遍历哈希表，加入时就判断，还能解决重复问题
        for (int i = 0; i < size; i++)
        {
            int temp = target - nums[i];
            if (m.count(temp) == 1)
                return {m.find(temp)->second, i};
                
            m.insert(make_pair(nums[i], i));
        }
        return {-1};

        // //* 1.暴力求解
        // for (int i = 0; i < size; i++)
        // {
        //     for (int j = i+1; j < size; j++)
        //     {
        //         if (m[i] + m[j] == target)
        //         {
        //             // r.push_back(i);
        //             // r.push_back(j);
        //             // return r;
        //             return {i, j};
        //         }
        //     }
        // }
        // return {-1};

        // //* 2.查找target-m[i]是否在m[i]中
        // for (int i = 0; i < size; i++)
        // {
        //     int temp = target - nums[i];
        //     if (m.find(temp) != m.end() && temp != nums[i])
        //     {    return {i, m.find(temp)->second};
        //     }
        // }
        // return {-1};
    }
};
// @lc code=end


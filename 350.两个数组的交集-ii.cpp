/*
 * @Author: your name
 * @Date: 2020-01-04 23:25:27
 * @LastEditTime : 2020-01-05 00:32:50
 * @LastEditors  : Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \LeetCode_exercise\350.两个数组的交集-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /*
    * 1. 重复数字也需要显示
    * 2. key为数组值，value为重复次数
    * 
    * ！！vector查找是O(N),map查找是O(1)
    */
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums1.size(); i++)
        {
            //* key为数组值，value为重复次数
            if (m.count(nums1[i]) == 0)
                m.insert(make_pair(nums1[i], 1));
            else
                m[nums1[i]]++;            
        }
        
        vector<int> result;
        for (int i = 0; i < nums2.size(); i++)
        {
            if (m.count(nums2[i]) == 1 && m[nums2[i]] > 0)
            {
                result.push_back(nums2[i]);
                m[nums2[i]]--;
            }
        }

        return result;
    }
};
// @lc code=end


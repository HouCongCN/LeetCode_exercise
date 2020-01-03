/*
 * @Author: your name
 * @Date: 2020-01-02 17:14:33
 * @LastEditTime : 2020-01-02 17:40:35
 * @LastEditors  : Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \LeetCode\349.两个数组的交集.cpp
 */
/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //! 主要是怎么给vector去重
        /*
            利用set给vector去重
            unordered_set<int> s1(nums1.begin(), nums1.end());
            unordered_set<int> s2(nums2.begin(), nums2.end());

            set转成vector
            vector<int> result(s1.begin(), s1.end());
        */

        unordered_set<int> s1, s2;
        vector<int> r;
        for (int num1:nums1)
        {
            if (s1.count(num1) == 1)
                continue;
            else
                s1.insert(num1);
        }

        for (int num2:nums2)
        {
            if (s2.count(num2) == 1)
                continue;
            else
                s2.insert(num2);
        }

        for (auto i = s2.begin(); i != s2.end(); i++)
        {
            if (s1.count(*i) == 1)
                r.push_back(*i);
        }

        return r;
    }
};
// @lc code=end


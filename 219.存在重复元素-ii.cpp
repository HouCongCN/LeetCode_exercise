/*
 * @Author: HouCong
 * @Date: 2020-01-05 00:35:02
 * @LastEditTime: 2020-01-05 01:05:15
 * @Description: file content
 * @FilePath: \LeetCode_exercise\219.存在重复元素-ii.cpp
 */

/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
#include <stdlib.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /*
     * 题目含义：存在两个索引满足n[i]=n[j],并且|i-j|<=k，即可返回true
     */
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int max = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.count(nums[i]) == 0)
                m.insert(make_pair(nums[i], i));
            else
            {
                if (i - m[nums[i]] <= k)
                    return true;
                m[nums[i]] = i;
            }
        }
        return false;
    }
};
// @lc code=end


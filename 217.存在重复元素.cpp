/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> saved;
        for (int num:nums)   
        {
            if (saved.count(num) == 1)
            {
                return true;
            }
            else
            {
                saved.insert(num);
            }
        }
        return false;
    }
};
// @lc code=end


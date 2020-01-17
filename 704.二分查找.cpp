/*
 * @Author: HouCong
 * @Date: 2020-01-15 19:20:59
 * @LastEditTime : 2020-01-15 19:57:21
 * @Description: file content
 * @FilePath: \LeetCode_exercise\704.二分查找.cpp
 */
/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int front = 0;        
        int end = size - 1;

        while (front <= end)
        {
            int mid = (front + end)/2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
            {
                front = mid + 1;
            }
            else
            {
                end = mid - 1;
            }   
        }
        return -1;
    }
};
// @lc code=end


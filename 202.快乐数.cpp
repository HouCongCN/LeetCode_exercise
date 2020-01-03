/*
 * @Author: your name
 * @Date: 2020-01-02 17:44:00
 * @LastEditTime : 2020-01-02 18:44:36
 * @LastEditors  : Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \LeetCode\202.快乐数.cpp
 */
/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool CalculateSquareSum(int n, unordered_set<int> s)
    {
        vector<int> nums;
        int sum = 0;
        while (n > 0)
        {
            int temp = n % 10;
            nums.push_back(temp);
            n = n / 10;
        }

        for (auto i = nums.begin(); i != nums.end(); i++)
        {
            sum += (*i) * (*i);
        }

        //* 对平方和对判断
        if (sum == 1)
            return true;
        else
        {
            if (s.count(sum) == 1)
                return false;
            else
            {   s.insert(sum);
                return CalculateSquareSum(sum, s);
            }            
        }  
    }


    bool isHappy(int n) {
        if (n == 1)
            return true;

        unordered_set<int> s;
        return CalculateSquareSum(n, s);        
    }
};
// @lc code=end


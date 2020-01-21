/*
 * @Author: HouCong
 * @Date: 2020-01-10 01:08:20
 * @LastEditTime : 2020-01-10 02:42:22
 * @Description: file content
 * @FilePath: \LeetCode_exercise\3.无重复字符的最长子串.cpp
 */
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    /*
     * 1. 暴力破解，遍历 
     * 2. 滑动窗口，窗口[start, end)内无重复字符
     *    end递增，start当遇到重复字符时更新
     *    max_len为过程中最长窗口
     */
    int lengthOfLongestSubstring(string s) {
        // if (s.empty()) return 0;
        // if (s.size() == 1) return 1;

        //* 暴力破解
        // unordered_map<int, string> m;
        // int max = 0;
        // for (int i = 0; i < s.size(); i++)
        // {
        //     m[i] += s[i];
        //     for (int j = i+1; j < s.size(); j++)
        //     {
        //         //! string.find != string::npos的使用
        //         if (m[i].find(s[j]) != string::npos) 
        //             break;
        //         else
        //             m[i] += s[j];
        //     }
        //     int size = m[i].size();
        //     max = max > size ? max :size;
        // }
        // return max;

        //* 滑动窗口 map(k, v) k为字符，v为索引+1，代表从后面开始不重复
        unordered_map<char, int> m;
        int max = 0;
        for (int start = 0, end = 0; end < s.size(); end++)
        {
            char tmp = s[end];
            if (m.count(tmp) == 0)
                m[tmp] = end + 1; 
            else
            {
                //* 窗口内存在重复字符d
                if (start < m[tmp])
                {   start = m[tmp];  
                }  
                m[tmp] = end + 1;                  
            }

            int len = end - start + 1;
            max = max > len ? max : len;
        }
        return max;
    }
};
// @lc code=end


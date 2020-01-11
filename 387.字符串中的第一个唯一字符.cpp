/*
 * @Author: HouCong
 * @Date: 2020-01-03 11:40:30
 * @LastEditTime : 2020-01-03 14:52:28
 * @Description: file content
 * @FilePath: \LeetCode_exercise\387.字符串中的第一个唯一字符.cpp
 */
/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        //* 1.利用哈希映射
        unordered_map<char, int> m;
        int min_index = s.size();
        for (int i=0; i<s.size(); i++)
        {
            if (m.count(s[i]) == 1)
            {
                m[s[i]] = -1;
            }
            else
            {
                m.insert(make_pair(s[i], i));
            }
        }

        for (auto i = m.begin(); i != m.end(); i++)
        {
            if (i->second >= 0)
            {
                min_index = min_index < i->second ? min_index:i->second;
            }
        }
        
        if (min_index == s.size())
            return -1;
        else
            return min_index;

        //* 2.利用动态数组
        if (s.empty()) return -1;
        vector<int> result(26, 0);
        for (char c:s)
        {
            result[c-'a'] ++;
        }
        int i = 0;
        for (char c:s)
        {
            if (result[c -'a'] == 1)
                return i;
            i++;
        }
        return -1;
    }
};
// @lc code=end


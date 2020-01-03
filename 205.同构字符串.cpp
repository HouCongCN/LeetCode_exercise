/*
 * @Author: your name
 * @Date: 2020-01-03 09:23:55
 * @LastEditTime : 2020-01-03 09:52:17
 * @LastEditors  : Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \LeetCode\205.同构字符串.cpp
 */
/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /*
     * 此题不关注具体的字符，而是关注整个字符串的结构组成。
     * 利用相同位置的字符差值，并在字符串中确认是否相同字符对应的差值相同
    */
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        int size = s.size();
        unordered_map<char, int> ms, mt;
        for (int i=0; i<size; i++)
        {
            int temp = s[i] - t[i];
            if (ms.count(s[i]) == 0 && mt.count(t[i]) == 0)
            {   ms.insert(make_pair(s[i], temp));
                mt.insert(make_pair(t[i], temp));
            }
            else if (ms.count(s[i]) + mt.count(t[i]) == 1)
                return false;
            else //两个都出现过
            {
                if (ms[s[i]] != temp)
                    return false;
            }
        }    

        return true;    
    }
};
// @lc code=end


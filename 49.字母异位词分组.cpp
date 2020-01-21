/*
 * @Author: HouCong
 * @Date: 2020-01-05 01:08:51
 * @LastEditTime : 2020-01-05 02:26:17
 * @Description: file content
 * @FilePath: \LeetCode_exercise\49.字母异位词分组.cpp
 */
/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /*
     * 1. 如何比较两个字符串是字母异位词
     * 2. 二维vector的初始化
     * 3. sort对vector和string的排序使用
     */

    //* 比较的方式: 1. 将字符串排序，然后比较   2. 比较每个字符出现次数
    //! 用质数表示26个字母，把字符串的各个字母相乘，
    //! 这样可保证字母异位词的乘积必定是相等的。

    /*************** 比较方式一 ***************/
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> r;
        unordered_map<string, int> m; 
        int index = 0;
        for (int i = 0; i < strs.size(); i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (m.count(tmp) == 1)
            {
                r[m[tmp]].push_back(strs[i]);
            }
            else
            {
                m[tmp] = index;
                r.push_back({strs[i]});  
                index ++;      
            }
        }

        return r;
    }



    /*************** 比较方式二 ***************/
    // bool Compare(string s1, string s2)
    // {
    //     if (s1.size() != s2.size())
    //         return false;
        
    //     unordered_map<char, int> m;
    //     for (char c1:s1)
    //         m[c1]++;
        
    //     for (char c2:s2)
    //     {
    //         if (m.count(c2) == 1 && m[c2] > 0)
    //             m[c2]--;
    //     }

    //     for (auto i = m.begin(); i != m.end(); i++)
    //     {
    //         if (i->second != 0)
    //             return false;
    //     }
    //     return true;
        
    // }

    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     vector<vector<string>> r;
    //     unordered_map<string, int> m; //记录每组字母异位词第一个的索引
    //     int index = 0;
    //     r.push_back({strs[0]});
    //     m[strs[0]] = 0;
    //     for (int i = 1; i < strs.size(); i++)
    //     {
    //         int flag = 0;
    //         for (int j = 0; j < i; j++)
    //         {
    //             //* 比较两个字符串是否为字母异位词
    //             if (Compare(strs[i], strs[j]))
    //             {   r[m[strs[j]]].push_back(strs[i]);
    //                 flag = 1;
    //                 break;
    //             }                
    //         }
            
    //         //* flag = 1说明找到字母异位词,已加入r中
    //         if (flag == 1)
    //             continue;
    //         else
    //         {
    //             r.push_back({strs[i]});
    //             index ++;
    //             m[strs[i]] = index;
    //         }
    //     }

    //     return r;
    // }


};
// @lc code=end


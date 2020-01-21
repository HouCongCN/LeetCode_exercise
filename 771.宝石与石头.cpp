/*
 * @Author: HouCong
 * @Date: 2020-01-10 01:00:38
 * @LastEditTime : 2020-01-10 01:07:51
 * @Description: file content
 * @FilePath: \LeetCode_exercise\771.宝石与石头.cpp
 */
/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 */

// @lc code=start
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> gem;
        int num = 0;
        for (char c:J)    
        {
            gem.insert(c);
        }

        for (char c:S)
        {
            if (gem.count(c) == 1)
                num++;
        }
        return num;
    }
};
// @lc code=end


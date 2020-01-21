/*
 * @Author: HouCong
 * @Date: 2020-01-11 13:49:24
 * @LastEditTime : 2020-01-11 14:32:29
 * @Description: file content
 * @FilePath: \LeetCode_exercise\454.四数相加-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /*
     * 1. 暴力破解 O(N^4) 效率太低
     * 
     * 2. 将四个列表分成两组，AB和CD。AB的和形成一个哈希表，当求CD的和时，
     *    在AB的哈希表中寻找相反数，形成一个所求的元祖      O(N^2)
     *    哈希表:   key -> 和    value -> 形成该和的组合个数
     */
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> m_AB;
        // unordered_map<int, int> m_CD;
        int count = 0;

        //* 计算A和B两个列表的和及对应组合数
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < B.size(); j++)
            {
                int tmp = A[i] + B[j];
                m_AB[tmp]++;
            }
        }

        //* 计算C和B两个列表和，并在m_AB中查找是否有相反数
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < B.size(); j++)
            {
                int tmp = -C[i] - D[j];
                if (m_AB.count(tmp) == 1)
                {
                    count += m_AB[tmp];
                }
            }
        }

        return count;
    }
};
// @lc code=end


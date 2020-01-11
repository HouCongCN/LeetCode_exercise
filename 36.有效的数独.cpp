/*
 * @Author: HouCong
 * @Date: 2020-01-06 19:16:07
 * @LastEditTime : 2020-01-07 09:39:34
 * @Description: file content
 * @FilePath: \LeetCode_exercise\36.有效的数独.cpp
 */
/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /*
     * 1. 建立多个哈希映射，一次遍历，利用三次 
     * 2. 一次遍历的话，子数独3x3的序号处理
     * 3. 哈希映射：key为数值，value为出现次数  
     */
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> row[9];
        unordered_map<char, int> col[9];
        unordered_map<char, int> sub[9];
        
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char tmp = board[i][j];
                int sub_index = (i/3) *3 + j/3;

                if (tmp != '.')
                {
                    // each row
                    if (row[i].count(tmp) == 0)
                        row[i].insert(make_pair(tmp, 1));
                    else
                        return false;
                    
                     // each column
                    if (col[j].count(tmp) == 0)
                        col[j].insert(make_pair(tmp, 1));
                    else
                        return false;

                     // each sub box
                    if (sub[sub_index].count(tmp) == 0)
                        sub[sub_index].insert(make_pair(tmp, 1));
                    else
                        return false;
                }
            }
        }

        return true;


        // //* 1.每行
        // for (int i = 0; i < 9; i++)
        // {
        //     unordered_map<char, int> m;
        //     for (int j = 0; j < 9; j++)
        //     {
        //         if (board[i][j] != '.')
        //         {
        //             if (m.count(board[i][j]) == 0)
        //                 m.insert(make_pair(board[i][j], 1));
        //             else                 
        //                 return false;
        //         } 
        //     }
        // }

        // //* 2.每列
        // for (int j = 0; j < 9; j++)
        // {
        //     unordered_map<char, int> m;
        //     for (int i = 0; i < 9; i++)
        //     {
        //         if (board[i][j] != '.')
        //         {
        //             if (m.count(board[i][j]) == 0)
        //                 m.insert(make_pair(board[i][j], 1));
        //             else                 
        //                 return false;
        //         } 
        //     }
        // }

        // //* 3.3x3九宫格
        // for (int k = 0; k < 3; k++)
        // {
        //     for (int n = 0; n < 3; n++)
        //     {
        //         unordered_map<char, int> m;
        //         for (int i = 0; i < 3; i++)
        //         {   
        //             for (int j = 0; j < 3; j++)
        //             {
        //                 if (board[3*k+i][3*n+j] != '.')
        //                 {
        //                     if (m.count(board[3*k+i][3*n+j]) == 0)
        //                         m.insert(make_pair(board[3*k+i][3*n+j], 1));
        //                     else                 
        //                         return false;
        //                 }
        //             }
        //         }
        //     }
        // }

        // return true;
    }
};
// @lc code=end


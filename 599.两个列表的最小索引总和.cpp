/*
 * @Author: HouCong
 * @Date: 2020-01-03 10:42:03
 * @LastEditTime : 2020-01-03 11:35:59
 * @Description: file content
 * @FilePath: \LeetCode_exercise\599.两个列表的最小索引总和.cpp
 */

/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /*
     * 建立map，key为餐厅名称，value为索引
     */
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        #define INDEX_MAX 2000
        unordered_map<string, int> m;
        for (int i=0; i<list1.size(); i++)
        {
            m.insert(make_pair(list1[i], i));
        }

        int minsum_index = INDEX_MAX;
        vector<string> target;
        for (int i=0; i<list2.size(); i++)
        {
            if (m.count(list2[i]) == 1)
            {
                int temp = m[list2[i]] + i;
                // minsum_index = minsum_index < temp ? minsum_index:temp;
                if (minsum_index > temp)
                {
                    minsum_index = temp;
                    target.clear();
                    target.push_back(list2[i]);
                }
                else if (minsum_index == temp)
                {
                    target.push_back(list2[i]);
                }                
            }
        }

        return target;
    }
};
// @lc code=end


/*
 * @Author: HouCong
 * @Date: 2020-01-11 14:44:15
 * @LastEditTime : 2020-01-11 20:38:27
 * @Description: file content
 * @FilePath: \LeetCode_exercise\347.前-k-个高频元素.cpp
 */
/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;

// bool operator<(pair<int, int> a, pair<int, int> b)
// {
//     //* 返回true,说明a的优先级低于b --- 大顶堆，用vecotr表达为降序
//     return a.second < b.second;
// }

class cmp {
public:
	bool operator ()(pair<int, int>&a, pair<int, int>&b) {
		return a.second > b.second;
	}
};

class Solution {
public:
    /*
     * 1. 利用哈希表保存每个元素值及出现次数
     * 2. 利用优先级队列对次数进行排序
     ! 优先级队列本质是堆（完全二叉树），插入排序 O(klogk) 
     ! 将map直接作为元素放进优先级队列，因此需要重载>
     * 将优先级队列内的信息以vector方式输出
     */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //* 1. 得到每个元素出现次数
        unordered_map<int, int> m;
        for (int num:nums)        
            m[num]++;
        
        //* 2. 遍历加入优先级队列，只保留前k个
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        for (auto i = m.begin(); i != m.end(); i++)
        {
            q.push(make_pair(i->first, i->second));
            if (q.size() > k)
                q.pop();
        }
        
        //* 3. 用vector表达最终结果
        vector<int> result;
        while (!q.empty())
        {
            result.push_back(q.top().first);            
            q.pop();
        }

        return result;        
    }
};
// @lc code=end


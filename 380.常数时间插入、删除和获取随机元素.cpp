/*
 * @Author: HouCong
 * @Date: 2020-01-12 09:43:12
 * @LastEditTime : 2020-01-12 11:32:06
 * @Description: file content
 * @FilePath: \LeetCode_exercise\380.常数时间插入、删除和获取随机元素.cpp
 */
/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] 常数时间插入、删除和获取随机元素
 */

// @lc code=start

/*
 * 1. insert ：要求平均时间复杂度为O(1)，则基本就是hash table。
 *    getRandom : 利用索引查找值，这种方式的话hash还是需要线性查找。因此这部分需要利用动态数组
 *    remove: 动态数组删除的话需要线性查找到再删除。为了O(1),需要先将要删除的数索引移植最后，直接弹出
 ! Hash Table 查找和插入操作平均时间复杂度为O(1) 
 * 2. rand()获取随机数，但由于随机数种子为1，不够随机，因此需要改变随机数种子
 * 3. srand(time(0))根据系统时间获取随机数种子
 *  
 */
#include <ctime>
#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> m; // key --> 元素值， val --> 索引 
    vector<int> a;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.count(val) == 1)
            return false;
        else
        {   
            m.insert(make_pair(val, a.size()));
            a.push_back(val);
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        //* 为了保证索引一一对应，先找到val的索引，然后将index改为最后一个，同时更改vector相关，最后删除
        if (m.count(val) == 1)
        {   
            int index = m[val];
            int size = a.size();
            
            //* 调换map
            //!其实不算调换，应该是保留原本vector最后的元素
            m[a[size-1]] = index;

            //* 调换vector
            a[index] = a[size-1];

            a.pop_back();
            m.erase(val);

            return true;
        }
        else
            return false;        
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if (a.size() == 0)
            return 0;
        
        int index = rand()%(a.size());        
        return a[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end


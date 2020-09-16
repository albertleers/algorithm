//给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值
// 至多为 k。 
//
// 
//
// 示例 1: 
//
// 输入: nums = [1,2,3,1], k = 3
//输出: true 
//
// 示例 2: 
//
// 输入: nums = [1,0,1,1], k = 1
//输出: true 
//
// 示例 3: 
//
// 输入: nums = [1,2,3,1,2,3], k = 2
//输出: false 
// Related Topics 数组 哈希表 
// 👍 201 👎 0
#include <unordered_map>
#include <unordered_set>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/*
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>>my_map;
        for(int i=0; i<nums.size(); i++){
            my_map[nums[i]].push_back(i);
        }
        auto iter = my_map.begin();
        while(iter != my_map.end()){
            if((iter->second).size()>=2){
                auto vec = iter->second;
                sort(vec.begin(), vec.end());
                for(int i=1; i<vec.size(); i++){
                    if(vec[i]-vec[i-1]<=k)return true;
                }
            }
            iter++;
        }
        return false;
    }
};
*/
// 维护一个k大小的散列表
/*
遍历数组，对于每个元素做以下操作：
在散列表中搜索当前元素，如果找到了就返回 true。
在散列表中插入当前元素。
如果当前散列表的大小超过了 kk， 删除散列表中最旧的元素
 * */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        int n = nums.size();
        unordered_set<int> s;
        for (int i = 0 ;i < n; ++i) {
            if (s.find(nums[i]) != s.end()) return true;
            s.insert(nums[i]);
            if (s.size() > k) s.erase(nums[i - k]);
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
bool result(){
    vector<int>nums = {1, 2, 3, 1};
    int k = 3;
    Solution s;
    return s.containsNearbyDuplicate(nums, k);
}
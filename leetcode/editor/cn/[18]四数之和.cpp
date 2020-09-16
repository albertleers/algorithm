//给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c +
// d 的值与 target 相等？找出所有满足条件且不重复的四元组。 
//
// 注意： 
//
// 答案中不可以包含重复的四元组。 
//
// 示例： 
//
// 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
//
//满足要求的四元组集合为：
//[
//  [-1,  0, 0, 1],
//  [-2, -1, 1, 2],
//  [-2,  0, 0, 2]
//]
// 
// Related Topics 数组 哈希表 双指针 
// 👍 565 👎 0

// 先排序，然后左右夹逼，复杂度 O(n)，会超时。 可以用一个hashmap先缓存两个数的和，最终复杂度O(n)。这个策略也适用于 3Sum
#include <unordered_map>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        if(nums.size()<4)return res;
        sort(nums.begin(), nums.end());

        unordered_map<int, vector<pair<int, int>>>my_map;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                my_map[nums[i]+nums[j]].push_back(pair<int,int>(i,j));
            }
        }

        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                int key = target - nums[i] - nums[j];
                if(my_map.find(key) == my_map.end())continue;

                auto vec = my_map[key];
                for(int k=0; k<vec.size(); k++){
                    if(i<=vec[k].second)continue;

                    res.push_back({nums[vec[k].first], nums[vec[k].second], nums[i], nums[j]});
                }
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


vector<vector<int>>result(){
    Solution s;
    vector<int>nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    return s.fourSum(nums, target);
}
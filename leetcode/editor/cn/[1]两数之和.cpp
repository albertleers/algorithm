//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。 
//
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。 
//
// 
//
// 示例: 
//
// 给定 nums = [2, 7, 11, 15], target = 9
//
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回 [0, 1]
// 
// Related Topics 数组 哈希表 
// 👍 9107 👎 0
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//algorithm submit region begin(Prohibit modification and deletion)
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        int i,j;
//        for(i=0;i<nums.size()-1;i++)
//        {
//            for(j=i+1;j<nums.size();j++)
//            {
//                if(nums[i]+nums[j]==target)
//                {
//                    return {i,j};
//                }
//            }
//        }
//        return {i,j};
//    };
//};
//algorithm submit region end(Prohibit modification and deletion)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>my_map;
        for(int i=0; i<nums.size(); i++){
            auto iter = my_map.find(target - nums[i]);
            if(iter != my_map.end()){
                return {iter->second, i};
            } else {
                my_map[nums[i]] = i;
            }
        }
    }
};

vector<int> result(){
    Solution s;
    int a[] = {2, 7, 11, 15};
    vector<int> nums(a, a + 4);
    return s.twoSum(nums, 9);
}
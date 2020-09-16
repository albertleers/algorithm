//给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复
//的三元组。 
//
// 注意：答案中不可以包含重复的三元组。 
//
// 
//
// 示例： 
//
// 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
//
//满足要求的三元组集合为：
//[
//  [-1, 0, 1],
//  [-1, -1, 2]
//]
// 
// Related Topics 数组 双指针 
// 👍 2574 👎 0

// Time Complexity: O(n^2)，Space Complexity: O(1)
using  namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        if(nums.size()<3)return res;
        sort(nums.begin(), nums.end());
        const int target = 0;

        auto last = nums.end();
        for(auto i = nums.begin(); i<nums.end()-2; i++){
            if(i>nums.begin() && *i==*(i-1))continue;
            auto j = i+1;
            auto k = last-1;
            while(j<k){
                if(*i + *j + *k < target){
                    j++;
                    while(*j == *(j - 1) && j < k) ++j;
                }else if(*i + *j + *k > target){
                    --k;
                    while(*k == *(k + 1) && j < k) --k;
                }else {
                    res.push_back({*i, *j, *k});
                    ++j;
                    --k;
                    while(*j == *(j - 1) && j < k) ++j;
                    while(*k == *(k + 1) && j < k) --k;
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
vector<vector<int>>result(){
    Solution s;
    vector<int>nums = {-1, 0, 1, 2, -1, -4};
    return s.threeSum(nums);
}
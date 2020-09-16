//给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和
//。假定每组输入只存在唯一答案。 
//
// 
//
// 示例： 
//
// 输入：nums = [-1,2,1,-4], target = 1
//输出：2
//解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
// 
//
// 
//
// 提示： 
//
// 
// 3 <= nums.length <= 10^3 
// -10^3 <= nums[i] <= 10^3 
// -10^4 <= target <= 10^4 
// 
// Related Topics 数组 双指针 
// 👍 569 👎 0
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3)return 0;
        sort(nums.begin(), nums.end());
        int delta = INT_MAX, last = nums.size();
        int res = 0;
        for(int i=0; i<last-2; i++){
            int j = i+1;
            int k = last-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                int gap = abs(target - sum);

                if(gap < delta){
                    res = sum;
                    delta = gap;
                }
                if(sum<target) j++;
                else k--;
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int result(){
    Solution s;
    vector<int>nums = {-1,2,1,-4};
    return s.threeSumClosest(nums, 1);
}
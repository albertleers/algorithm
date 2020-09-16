//给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之
//外其余各元素的乘积。 
//
// 
//
// 示例: 
//
// 输入: [1,2,3,4]
//输出: [24,12,8,6] 
//
// 
//
// 提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。 
//
// 说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。 
//
// 进阶： 
//你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。） 
// Related Topics 数组 
// 👍 586 👎 0
using namespace std;
/*
 我们以一个4个元素的数组为例， nums=[a1,a2,a3,a4] ，要想在 O(n) 的时间内输出结果，比较好的解
决方法是提前构造好两个数组：
[1, a1, a1*a2, a1*a2*a3]
[a2*a3*a4, a3*a4, a4, 1]
然后两个数组一一对应相乘，即可得到最终结果 [a2*a3*a4, a1*a3*a4, a1*a2*a4, a1*a2*a3]
 */
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>res1(n,1);
        vector<int>res2(n,1);
        for(int i=1; i<nums.size(); i++){
            res1[i] = res1[i-1]*nums[i-1];
        }
        for(int j=n-2; j>=0; j--){
            res2[j] = res2[j+1]*nums[j+1];
        }
        for(int k=0; k<nums.size(); k++){
            res1[k] *= res2[k];
        }
        return res1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
vector<int>result(){
    vector<int> nums({1,2,3,4});
    Solution s;
    return s.productExceptSelf(nums);
}
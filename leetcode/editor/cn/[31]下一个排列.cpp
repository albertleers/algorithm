//实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。 
//
// 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。 
//
// 必须原地修改，只允许使用额外常数空间。 
//
// 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。 
//1,2,3 → 1,3,2 
//3,2,1 → 1,2,3 
//1,1,5 → 1,5,1 
// Related Topics 数组 
// 👍 660 👎 0
#include <algorithm>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pos = nums.size()-1;
        while(pos>0 && nums[pos]<=nums[pos-1]) pos--;
        reverse(nums.begin()+pos, nums.end());
        if(pos>0){
            for(int start=pos; start<nums.size(); start++){
                if(nums[start]>nums[pos-1]){
                    swap(nums[start], nums[pos-1]);
                    break;
                }
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

vector<int>result(){
    vector<int>res = {1, 2, 3};
    Solution s;
    s.nextPermutation(res);
    return res;
}
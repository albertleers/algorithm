//给定一个未排序的数组，判断这个数组中是否存在长度为 3 的递增子序列。 
//
// 数学表达式如下: 
//
// 如果存在这样的 i, j, k, 且满足 0 ≤ i < j < k ≤ n-1， 
//使得 arr[i] < arr[j] < arr[k] ，返回 true ; 否则返回 false 。 
//
// 说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1) 。 
//
// 示例 1: 
//
// 输入: [1,2,3,4,5]
//输出: true
// 
//
// 示例 2: 
//
// 输入: [5,4,3,2,1]
//输出: false 
// 👍 211 👎 0
#include <limits.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/*
 定义两个数组forward[i]和backward[i]，forward[i]从前向后遍历，保存[0, i]之间最小元素值，
 backward[i]从后向前遍历，保存[i, size - 1]间最大元素值。
 然后从前向后遍历，如果找到一个数满足forward[i] < nums[i] < backward[i]，则表示三元子序列存在
 */
/*
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int size = nums.size();
        vector<int> f(size, nums[0]), b(size, nums.back());
        for (int i = 1; i < size; ++i) {
            f[i] = min(f[i - 1], nums[i]);
        }
        for (int i = size - 2; i >= 0; --i) {
            b[i] = max(b[i + 1], nums[i]);
        }
        for (int i = 0; i < size; ++i) {
            if (f[i] < nums[i] && nums[i] < b[i]) return true;
        }
        return false;
    }
};
*/

//扫描一遍数组，用变量 x1 保存当前最小的值，变量 x2 保存当前第二小的值。如果右面能碰到一个数大
//于 x2 ，说明必然存在一个递增的三元组
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX, b = INT_MAX;
        for (int n : nums) {
            if (n <= a) a = n;
            else if (n <= b) b = n;
            else return true;
        }
        return false;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
bool result(){
    vector<int>nums = {3,5,1,6};
    Solution s;
    return s.increasingTriplet(nums);
}
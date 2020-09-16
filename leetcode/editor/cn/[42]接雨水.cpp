//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。 
//
// 
//
// 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Mar
//cos 贡献此图。 
//
// 示例: 
//
// 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
//输出: 6 
// Related Topics 栈 数组 双指针 
// 👍 1649 👎 0
/*
对于每个柱子，找到其左右两边最高的柱子，该柱子能容纳的面积就是 min(max_left, max_right) -height 。所以，
1. 从左往右扫描一遍，对于每个柱子，求取左边最大值；
2. 从右往左扫描一遍，对于每个柱子，求最大右值；
3. 再扫描一遍，把每个柱子的面积并累加。
 时间复杂度O(n)，空间复杂度O(n)
 * */
#include <algorithm>
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
/*
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        for(int i=1; i<n; i++){
            left[i] = max(left[i-1], height[i-1]);
        }
        for(int j=n-2; j>=0; j--){
            right[j] = max(right[j+1], height[j+1]);
        }
        int sum = 0;
        for(int i=0; i<n; i++){
            int high = min(left[i], right[i]);
            if(high > height[i]){
                sum += high - height[i];
            }
        }
        return sum;
    }
};
 */
// 思路2，时间复杂度O(n)，空间复杂度O(1)
//1.扫描一遍，找到最高的柱子，这个柱子将数组分为两半；
//2. 处理左边一半；
//3. 处理右边一半。
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int index = 0;
        for(int i=0; i<n; i++){
            if(height[i]>height[index])index = i;
        }
        int sum = 0;
        for(int i=0, left=0; i<index; i++){
            if(height[i]>left){
                left = height[i];
            }else sum += left - height[i];
        }
        for(int i=n-1, right=0; i>index; i--){
            if(height[i]>right){
                right = height[i];
            }else sum += right - height[i];
        }
        return sum;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
int result(){
    vector<int>height={0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    return s.trap(height);
}
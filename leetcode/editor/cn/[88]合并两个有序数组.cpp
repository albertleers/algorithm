//给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。 
//
// 
//
// 说明: 
//
// 
// 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。 
// 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。 
// 
//
// 
//
// 示例: 
//
// 输入:
//nums1 = [1,2,3,0,0,0], m = 3
//nums2 = [2,5,6],       n = 3
//
//输出: [1,2,2,3,5,6] 
// Related Topics 数组 双指针 
// 👍 621 👎 0
#include <iostream>
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
//class Solution {
//public:
//    void swap(int &a, int &b){
//        int tmp;
//        tmp = a;
//        a = b;
//        b= tmp;
//    }
//    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//        if(n==0)return;
//        for(int i=0; i<n; i++){
//            int k = m+i;
//            nums1[k] = nums2[i];
//            while(nums1[k] < nums1[k-1] && k>0){
//                swap(nums1[k], nums1[k-1]);
//                k--;
//            }
//        }
//    }
//};

class Solution {
public:
    void swap(int &a, int &b){
        int tmp;
        tmp = a;
        a = b;
        b= tmp;
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m+n-1;
        m--;
        n--;
        while(n>=0){
            while(m>=0 && nums1[m]>nums2[n]){
                swap(nums1[i--], nums1[m--]);
            }
            swap(nums1[i--], nums2[n--]);
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

vector<int> result(){
    Solution s;
    int a1[] = {1,2,3,0,0,0}, m = 3;
    int a2[] = {2,5,6}, n = 3;
//    int a1[] = {0}, m = 0;
//    int a2[] = {1}, n = 1;
    vector<int> nums1(a1, a1 + 6);
    vector<int> nums2(a2, a2 + 3);
    s.merge(nums1, m, nums2, n);
    return nums1;
}
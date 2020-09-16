//给定一个未排序的整数数组，找出最长连续序列的长度。 
//
// 要求算法的时间复杂度为 O(n)。 
//
// 示例: 
//
// 输入: [100, 4, 200, 1, 3, 2]
//输出: 4
//解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。 
// Related Topics 并查集 数组 
// 👍 543 👎 0
#include <unordered_set>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>my_set;
        for(auto i:nums)my_set.insert(i);

        int longest = 0;
        for(auto i:nums){
            int length = 1;
            for(int j=i-1; my_set.find(j) != my_set.end(); j--){
                my_set.erase(j);
                ++length;
            }
            for(int j=i+1; my_set.find(j) != my_set.end(); j++){
                my_set.erase(j);
                ++length;
            }
            longest = max(longest, length);
        }
        return longest;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int result(){
    vector<int>nums = {100, 4, 200, 1, 3, 2};
    Solution s;
    return s.longestConsecutive(nums);
}
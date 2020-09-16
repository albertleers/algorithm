//在整数数组 nums 中，是否存在两个下标 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值小于等于 t ，且满足 i 和 j 的差的
//绝对值也小于等于 ķ 。 
//
// 如果存在则返回 true，不存在返回 false。 
//
// 
//
// 示例 1: 
//
// 输入: nums = [1,2,3,1], k = 3, t = 0
//输出: true 
//
// 示例 2: 
//
// 输入: nums = [1,0,1,1], k = 1, t = 2
//输出: true 
//
// 示例 3: 
//
// 输入: nums = [1,5,9,1,5,9], k = 2, t = 3
//输出: false 
// Related Topics 排序 Ordered Map 
// 👍 228 👎 0
#include <set>
#include <unordered_map>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/*

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int size = nums.size();
        if(size<=1)return false;
        if(k==0)return t==0;
        multiset<long>window;
        //construct the first window
        for(int i=0; i<min(size, k+1); i++){
            bool tmp = updateWindow(window, nums[i], t); if(tmp) return true;
            window.insert(nums[i]);
        }
        //slide the window
        for(int i=1; i+k<size; i++){
            auto itPrev = window.find(nums[i-1]);
            window.erase(itPrev);
            bool tmp = updateWindow(window, nums[i+k], t);
            if(tmp) return true;
            window.insert(nums[i+k]);
        }
        return false;
    }

    bool updateWindow(multiset<long>& window, int val, int t) {
        auto itlower = window.lower_bound(val);
        if(itlower != window.end() && (*itlower)-val <= t) return true;
        if(itlower != window.begin()) {
            --itlower;
            if(val - (*itlower) <= t) return true;
        }
        return false;
    }
};
*/
class Solution{
private:
    long getBucket(long x, long w){
        return x<0 ? (x+1)/w-1 : x/w;
    }

public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t<0)return false;
        unordered_map<long, long>my_map;
        long w = (long)t+1;
        for(int i=0; i<nums.size(); i++){
            long b = getBucket(nums[i], w);

            if(my_map.find(b) != my_map.end()) return true;
            if(my_map.find(b-1)!= my_map.end() && abs(nums[i]-my_map[b-1]) < w) return true;
            if(my_map.find(b+1)!= my_map.end() && abs(nums[i]-my_map[b+1]) < w) return true;

            my_map[b] = (long)nums[i];
            if(i>=k)my_map.erase(getBucket(nums[i-k], w));
        }
        return false;
    }
};


//leetcode submit region end(Prohibit modification and deletion)
bool result(){
    vector<int>nums = {1,0,1,1};
    int k = 1;
    int t = 2;
    Solution s;
    return s.containsNearbyAlmostDuplicate(nums, k, t);
}
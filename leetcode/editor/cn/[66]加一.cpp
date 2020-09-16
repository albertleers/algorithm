//给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。 
//
// 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。 
//
// 你可以假设除了整数 0 之外，这个整数不会以零开头。 
//
// 示例 1: 
//
// 输入: [1,2,3]
//输出: [1,2,4]
//解释: 输入数组表示数字 123。
// 
//
// 示例 2: 
//
// 输入: [4,3,2,1]
//输出: [4,3,2,2]
//解释: 输入数组表示数字 4321。
// 
// Related Topics 数组 
// 👍 541 👎 0
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/*
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int>res;
        digits[n-1] += 1;
        for(int i=0; i<n-1; i++){
            res.push_back(digits[n-1-i]%10);
            digits[n-i-2] += digits[n-1-i] / 10;
        }
        if(digits[0]>9){
            res.push_back(digits[0]%10);
            digits[0] = digits[0] / 10;
        }
        res.push_back(digits[0]);
        reverse(res.begin(), res.end());
        return res;
    }
};
*/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int c = 1;
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            *it += c;
            c = *it / 10;
            *it %= 10;
        }
        if (c > 0) digits.insert(digits.begin(), 1);
        return digits;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
vector<int>result(){
    vector<int>digits = {4,3,2,1};
    Solution s;
    s.plusOne(digits);
    return digits;
}
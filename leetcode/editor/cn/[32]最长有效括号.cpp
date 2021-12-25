//给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。 
//
// 
//
// 
// 
// 示例 1： 
//
// 
//输入：s = "(()"
//输出：2
//解释：最长有效括号子串是 "()"
// 
//
// 示例 2： 
//
// 
//输入：s = ")()())"
//输出：4
//解释：最长有效括号子串是 "()()"
// 
//
// 示例 3： 
//
// 
//输入：s = ""
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 3 * 104 
// s[i] 为 '(' 或 ')' 
// 
// 
// 
// Related Topics 字符串 动态规划 
// 👍 1242 👎 0
using namespace std;

#include "string"
#include "vector"
#include "stack"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0, n = s.length();
        vector<int> dp(n, 0);)
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxans = max(maxans, dp[i]);
            }
        }
        return maxans;
    }
//    int longestValidParentheses(string s) {
//        int maxans = 0;
//        stack<int> stk;
//        stk.push(-1);
//        for (int i = 0; i < s.length(); i++) {
//            if (s[i] == '(') {
//                stk.push(i);
//            } else {
//                stk.pop();
//                if (stk.empty()) {
//                    stk.push(i);
//                } else {
//                    maxans = max(maxans, i - stk.top());
//                }
//            }
//        }
//        return maxans;
//    }
//    int longestValidParentheses(string s) {
//        int left = 0, right = 0, maxlength = 0;
//        for (int i = 0; i < s.length(); i++) {
//            if (s[i] == '(') {
//                left++;
//            } else {
//                right++;
//            }
//            if (left == right) {
//                maxlength = max(maxlength, 2 * right);
//            } else if (right > left) {
//                left = right = 0;
//            }
//        }
//        left = right = 0;
//        for (int i = (int)s.length() - 1; i >= 0; i--) {
//            if (s[i] == '(') {
//                left++;
//            } else {
//                right++;
//            }
//            if (left == right) {
//                maxlength = max(maxlength, 2 * left);
//            } else if (left > right) {
//                left = right = 0;
//            }
//        }
//        return maxlength;
//    }
};
//leetcode submit region end(Prohibit modification and deletion)

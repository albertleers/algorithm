//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。 
//
// 有效字符串需满足： 
//
// 
// 左括号必须用相同类型的右括号闭合。 
// 左括号必须以正确的顺序闭合。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "()"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：s = "()[]{}"
//输出：true
// 
//
// 示例 3： 
//
// 
//输入：s = "(]"
//输出：false
// 
//
// 示例 4： 
//
// 
//输入：s = "([)]"
//输出：false
// 
//
// 示例 5： 
//
// 
//输入：s = "{[]}"
//输出：true 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 104 
// s 仅由括号 '()[]{}' 组成 
// 
// Related Topics 栈 字符串 
// 👍 2285 👎 0
using namespace std;

#include "stack"
#include "map"
#include "string"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
//    bool isValid(string s) {
//        map<char, char>map1 = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
//        string hs = "([{";
//        stack<char> sk;
//        for(auto c:s){
//            if(hs.find(c) != string::npos){
//                sk.push(c);
//            } else {
//                if (sk.empty() || c != map1[sk.top()]) {
//                    return false;
//                } else {
//                    sk.pop();
//                }
//            }
//        }
//        return sk.empty();
//    }
    bool isValid(string s) {
        string left = "([{";
        string right = ")]}";
        stack<char> stk;
        for (auto c : s) {
            if (left.find(c) != string::npos) {
                stk.push(c);
            } else {
                if (stk.empty() || stk.top() != left[right.find(c)]) {
                    return false;
                } else {
                    stk.pop();
                }
            }
        }
        return stk.empty();
    }
};
//leetcode submit region end(Prohibit modification and deletion)

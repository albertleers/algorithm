//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。 
//
// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？ 
//
// 注意：给定 n 是一个正整数。 
//
// 示例 1： 
//
// 输入： 2
//输出： 2
//解释： 有两种方法可以爬到楼顶。
//1.  1 阶 + 1 阶
//2.  2 阶 
//
// 示例 2： 
//
// 输入： 3
//输出： 3
//解释： 有三种方法可以爬到楼顶。
//1.  1 阶 + 1 阶 + 1 阶
//2.  1 阶 + 2 阶
//3.  2 阶 + 1 阶
// 
// Related Topics 动态规划 
// 👍 1233 👎 0
#include <cmath>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/*
class Solution {
public:
    int climbStairs(int n) {
        vector<int>number(n+1,0);
        if(n<=2)return n;
        number[0]=0;
        number[1]=1;
        number[2]=2;
        for(int i=3; i<=n; i++){
            number[i] = number[i-1] + number[i-2];
        }
        return number[n];
    }
};
*/
/*

class Solution {
public:
    int climbStairs(int n) {
        int pre=0, cur=1;
        for(int i=1; i<=n; i++){
            int tmp=cur;
            cur = cur+pre;
            pre = tmp;
        }
        return cur;
    }
};
*/
// 斐波那契数列通项公式
class Solution {
public:
    int climbStairs(int n) {
        const double s = sqrt(5);
        return floor((pow((1+s)/2, n+1) +pow((1-s)/2, n+1))/s + 0.5);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int result(){
    int n=10;
    Solution s;
    return s.climbStairs(n);
}
//给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。 
//
// 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下： 
//
// 
// "123" 
// "132" 
// "213" 
// "231" 
// "312" 
// "321" 
// 
//
// 给定 n 和 k，返回第 k 个排列。 
//
// 说明： 
//
// 
// 给定 n 的范围是 [1, 9]。 
// 给定 k 的范围是[1, n!]。 
// 
//
// 示例 1: 
//
// 输入: n = 3, k = 3
//输出: "213"
// 
//
// 示例 2: 
//
// 输入: n = 4, k = 9
//输出: "2314"
// 
// Related Topics 数学 回溯算法 
// 👍 382 👎 0
#include <string>
#include <algorithm>
using namespace std;

// 康托展开和逆康托展开 https://blog.csdn.net/wbin233/article/details/72998375
//  X=a[n]*(n-1)!+a[n-1]*(n-2)!+...+a[i]*(i-1)!+...+a[1]*0!
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<int> Factorial(int n){
        vector<int>res;
        res.push_back(1);
        for(int i=1; i<=n; i++){
            res.push_back(i*res[i-1]);
        }
        return res;
    }

    // 康托展开表示的就是在n个不同元素的全排列中, 比当前排列组合小的个数
    int Cantor(vector<int>a, int n){
        vector<int>fac = Factorial(n-1);
        reverse(fac.begin(), fac.end());
        int k=0;
        for(int i=0; i<n; i++){
            int smaller = 0;
            for(int j=i+1; j<n; j++){
                if(a[j]<a[i]) ++smaller;
            }
            cout<< smaller << " " << fac[i] << endl;
            k += fac[i]*smaller;
        }
        return k;
    };

    // 逆康托展开
    vector<int> Decantor(int k, int n){
        vector<int>v;// 存放当前可选数，有序
        for(int i=1; i<=n; i++){
            v.push_back(i);
        }

        vector<int>fac = Factorial(n-1);
        reverse(fac.begin(), fac.end());

        k--;//要先 -1 才是其康托展开的值
        vector<int>res;
        for(int i=0; i<n; i++){
            int r = k % fac[i];
            int t = k / fac[i];
            k = r;
            res.push_back(v[t]);
            v.erase(v.begin()+t);
        }
        return res;
    };

public:
    string getPermutation(int n, int k) {
        vector<int>res = Decantor(k, n);
        string rest = "";
        for(auto i:res){
            cout << i << endl;
            rest += to_string(i);
        }
        return rest;
    };
};
//leetcode submit region end(Prohibit modification and deletion)

string result(){
    Solution s;
    return s.getPermutation(4,9);
}
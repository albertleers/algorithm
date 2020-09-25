//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//
// 
//
// 示例： 
//
// 输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4
// 
// Related Topics 链表 
// 👍 1274 👎 0
#include "utils.cpp"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(-1);
        ListNode *cur = res;
        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }
        while(l1){
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
        }
        while(l2){
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
        }
        cur->next = nullptr;
        return res->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

ListNode *result(){
    vector<int>v1 = {1,2,4};
    vector<int>v2 = {1,3,4};
    LinkedList l;
    ListNode *l1 = l.vectorToListNode(v1);
    ListNode *l2 = l.vectorToListNode(v2);
    Solution s;
    return s.mergeTwoLists(l1, l2);
}
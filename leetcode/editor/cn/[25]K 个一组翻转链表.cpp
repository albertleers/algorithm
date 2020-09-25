//给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。 
//
// k 是一个正整数，它的值小于或等于链表的长度。 
//
// 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。 
//
// 
//
// 示例： 
//
// 给你这个链表：1->2->3->4->5 
//
// 当 k = 2 时，应当返回: 2->1->4->3->5 
//
// 当 k = 3 时，应当返回: 3->2->1->4->5 
//
// 
//
// 说明： 
//
// 
// 你的算法只能使用常数的额外空间。 
// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。 
// 
// Related Topics 链表 
// 👍 736 👎 0
#include "utils.cpp"
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    pair<ListNode*, ListNode*> Reverse(ListNode *head, ListNode *tail){
        ListNode *pre = tail->next;
        ListNode *cur = head;

        while(pre != tail){
            ListNode *nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *res = new ListNode(-1);
        res->next = head;
        ListNode *pre = res;

        while(head){
            ListNode *tail = pre;
            for(int i=0; i<k; i++){
                tail = tail->next;
                if(!tail){
                    return res->next;
                }
            }
            ListNode *nex = tail->next;

            pair<ListNode*, ListNode*>result = Reverse(head, tail);
            head = result.first;
            tail = result.second;
            pre->next = head;
            tail->next = nex;

            pre = tail;
            head = tail->next;
        }
        return res->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
ListNode* result(){
    vector<int>a = {1,2,3,4,5};
    int k=2;
    LinkedList l;
    ListNode * h = l.vectorToListNode(a);
    Solution s;
    return s.reverseKGroup(h, k);
}
//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。 
//
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。 
//
// 
//
// 示例: 
//
// 给定 1->2->3->4, 你应该返回 2->1->4->3.
// 
// Related Topics 链表 
// 👍 628 👎 0
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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode * res = new ListNode(-1);
        res->next = head;

        ListNode *pre = res, *cur = res->next, *next = cur->next;
        while(next){
            pre->next = next;
            cur->next = next->next;
            next->next = cur;

            pre = pre->next->next;
            cur = pre->next;
            next = cur ? cur->next : nullptr;
        }
        return res->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
ListNode* result(){
    vector<int>a = {1,2,3,4};
    LinkedList l;
    ListNode * h = l.vectorToListNode(a);
    Solution s;
    return s.swapPairs(h);
}
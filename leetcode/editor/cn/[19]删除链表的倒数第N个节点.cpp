//给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。 
//
// 示例： 
//
// 给定一个链表: 1->2->3->4->5, 和 n = 2.
//
//当删除了倒数第二个节点后，链表变为 1->2->3->5.
// 
//
// 说明： 
//
// 给定的 n 保证是有效的。 
//
// 进阶： 
//
// 你能尝试使用一趟扫描实现吗？ 
// Related Topics 链表 双指针 
// 👍 991 👎 0
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *res = new ListNode(-1);
        res->next = head;
        ListNode *pre = res, *cur = res;
        while(n>0){
            cur = cur->next;
            n--;
        }
        while(cur->next){
            cur = cur->next;
            pre = pre->next;
        }
        pre->next = pre->next->next;

        return res->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
ListNode *result(){
    vector<int>a = {1,2,3,4,5};
    int n=2;
    LinkedList l;
    ListNode *h = l.vectorToListNode(a);
    Solution s;
    return s.removeNthFromEnd(h, n);
}
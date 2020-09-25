//给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。 
//
// 你应当保留两个分区中每个节点的初始相对位置。 
//
// 
//
// 示例: 
//
// 输入: head = 1->4->3->2->5->2, x = 3
//输出: 1->2->2->4->3->5
// 
// Related Topics 链表 双指针 
// 👍 254 👎 0
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head)return head;
        ListNode *less = new ListNode(-1);
        ListNode *more = new ListNode(-1);
        ListNode *p = less, *q = more;
        while(head){
            if(head->val < x) {
                p->next = head;
                p = p->next;
            } else{
                q->next = head;
                q = q->next;
            }
            head = head->next;
        }

        q->next = nullptr; // 内存溢出
        p->next = more->next;
        return less->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
ListNode* result(){
    ListNode *h = new ListNode(5);
    h->next = new ListNode(4);
    h->next->next = new ListNode(2);
    h->next->next->next = new ListNode(6);
    h->next->next->next->next = new ListNode(1);
    Solution s;
    return s.partition(h, 3);
}
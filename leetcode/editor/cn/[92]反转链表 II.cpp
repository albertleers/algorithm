//反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。 
//
// 说明: 
//1 ≤ m ≤ n ≤ 链表长度。 
//
// 示例: 
//
// 输入: 1->2->3->4->5->NULL, m = 2, n = 4
//输出: 1->4->3->2->5->NULL 
// Related Topics 链表 
// 👍 511 👎 0
using  namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(n==1 || !head)return head;
        ListNode *pre = nullptr, *cur = head;
        while(m>1){
            pre = cur;
            cur = cur->next;
            m--;
            n--;
        }

        ListNode *before = pre, *after = cur;
        while(n>0){
            ListNode *nextptr = cur->next;
            cur->next  = pre;
            pre = cur;
            cur = nextptr;
            n--;
        }

        if(before) before->next = pre;
        else head = pre;
        after->next = cur;

        return head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
ListNode* result(){
    ListNode *h = new ListNode(1);
    h->next = new ListNode(2);
    h->next->next = new ListNode(3);
    h->next->next->next = new ListNode(4);
    h->next->next->next->next = new ListNode(5);
    Solution s;
    return s.reverseBetween(h, 2, 4);
}
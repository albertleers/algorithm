//给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。 
//
// 示例 1: 
//
// 输入: 1->1->2
//输出: 1->2
// 
//
// 示例 2: 
//
// 输入: 1->1->2->3->3
//输出: 1->2->3 
// Related Topics 链表 
// 👍 392 👎 0
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode *pre = head;
        ListNode *cur = head->next;
        while(pre && pre->next){
            if(pre->val == cur->val) {
                pre->next = cur->next;
                cur = cur->next;
            }
            else pre = pre->next;
        }
        return head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
ListNode* result(){
    ListNode *h = new ListNode(1);
    h->next = new ListNode(1);
    h->next->next = new ListNode(2);
    h->next->next->next = new ListNode(3);
    h->next->next->next->next = new ListNode(3);
    Solution s;
    return s.deleteDuplicates(h);
}
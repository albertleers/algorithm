//给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。 
//
// 示例 1: 
//
// 输入: 1->2->3->3->4->4->5
//输出: 1->2->5
// 
//
// 示例 2: 
//
// 输入: 1->1->1->2->3
//输出: 2->3 
// Related Topics 链表 
// 👍 365 👎 0
#include "utils.cpp"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode *res = new ListNode(-1);
        res->next = head;
        ListNode *pre=res;
        while(pre && pre->next){
            ListNode *cur = pre->next;
            if(!cur->next || cur->next->val != cur->val) pre = cur;
            else {
                while(cur->next && cur->next->val == cur->val) cur = cur->next;
                pre->next = cur->next;
            }
        }
        return res->next;
    }
};

/*
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        if(head->next->val != head->val)
        {
            // 如果head后面一位的元素的值不等于head的值，就从head->next开始接着处理后面的链表
            head -> next = deleteDuplicates(head -> next);
            return head;
        }
        else
        {
            // 如果head后面一位的元素的值等于head的值，就跳过所有与head的值相等的元素，从第一个不等于head值的元素开始处理
            ListNode *curr = head;
            while(curr->next && curr->next->val==curr->val) curr = curr -> next;
            return deleteDuplicates(curr -> next);
        }
    }
};
*/

//leetcode submit region end(Prohibit modification and deletion)
ListNode* result(){
    vector<int>a = {1,2,3,3,4,4,5};
    LinkedList l;
    ListNode * h = l.vectorToListNode(a);
    Solution s;
    return s.deleteDuplicates(h);
}
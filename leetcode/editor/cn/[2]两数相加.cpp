//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。 
//
// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。 
//
// 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。 
//
// 示例： 
//
// 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807
// 
// Related Topics 链表 数学 
// 👍 4904 👎 0
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(-1);
        ListNode *cur = res;
        int multi = 0, sum = 0;
        while(l1 && l2){
            sum = l1->val + l2->val + multi;
            cur->next = new ListNode(sum % 10);
            multi = sum / 10;
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode *other = nullptr;
        if(l1) other = l1;
        else other = l2;

        while(other){
            sum = other->val + multi;
            cur->next = new ListNode(sum % 10);
            multi = sum / 10;
            cur = cur->next;
            other = other->next;
        }
        if(multi) cur->next = new ListNode(multi);

        return res->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
ListNode* result(){
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution s;
    return s.addTwoNumbers(l1, l2);
}
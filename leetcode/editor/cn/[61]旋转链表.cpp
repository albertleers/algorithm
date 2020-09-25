//给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。 
//
// 示例 1: 
//
// 输入: 1->2->3->4->5->NULL, k = 2
//输出: 4->5->1->2->3->NULL
//解释:
//向右旋转 1 步: 5->1->2->3->4->NULL
//向右旋转 2 步: 4->5->1->2->3->NULL
// 
//
// 示例 2: 
//
// 输入: 0->1->2->NULL, k = 4
//输出: 2->0->1->NULL
//解释:
//向右旋转 1 步: 2->0->1->NULL
//向右旋转 2 步: 1->2->0->NULL
//向右旋转 3 步: 0->1->2->NULL
//向右旋转 4 步: 2->0->1->NULL 
// Related Topics 链表 双指针 
// 👍 335 👎 0
#include "utils.cpp"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        int count = 1;
        ListNode *node = head;
        while(node && node->next){
            count++;
            node = node->next;
        }
        node->next = head;
        int p = count-k%count;
        while(p>0){
            node = node->next;
            p--;
        }
        ListNode *res = new ListNode(-1);
        res->next = node->next;
        node->next = nullptr;
        return res->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

ListNode *result(){
    vector<int>a = {0,1,2};
    int k=2;
    LinkedList l;
    ListNode *h = l.vectorToListNode(a);
    Solution s;
    return s.rotateRight(h, k);
}
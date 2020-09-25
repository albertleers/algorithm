#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class LinkedList{
public:
    ListNode *vectorToListNode(vector<int>a){
        ListNode *res = new ListNode(-1);
        ListNode *cur = res;
        for(auto i:a){
            cur->next = new ListNode(i);
            cur = cur->next;
        }
        return res->next;
    }

};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Tree {

};

class Print{
public:
    template<class TV>
    void print(vector<TV> v) {
        for (auto it = v.begin(); it != v.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    };

    template<class TVV>
    void print(vector<vector<TVV>> v) {
        for (auto it = v.begin(); it != v.end(); ++it) {
            print(*it);
        }
        cout << endl;
    };

    template<class T>
    void print(T v){
        cout << v << endl;
    };

    void print(ListNode* node){
        while(node){
            cout << node->val << "\t" ;
            node = node->next;
        }
        cout << endl;
    };

    void print(){
        cout << "Hello, World!" << endl;
    };
};


#include <iostream>
#include <vector>

using namespace std;

// leetcode 2. 两数相加

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        return dummy->next;
    }
};

// 构造示例链表的函数形式
ListNode* build(const vector<int>& vals) {
    ListNode* dummy = new ListNode();
    ListNode* cur = dummy;
    for (int v : vals) {
        cur->next = new ListNode(v);
        cur = cur->next;
    }
    return dummy->next;
}
// 链表打印函数
void printList(const ListNode* node) {
    while (node) {
        cout << node->val;
        if (node->next) cout << " -> ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    ListNode* l1 = build({2,4,3});
    ListNode* l2 = build({5,6,4});

    cout << "l1: "; printList(l1);
    cout << "l2: "; printList(l2);

    ListNode* res = solution.addTwoNumbers(l1, l2);
    cout << "输出: "; printList(res);

    return 0;
}
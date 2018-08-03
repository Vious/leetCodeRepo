#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *res = head;
        ListNode *first = head, *second = head->next;
        if (second == NULL) return res;
        first->next = second->next;
        second->next = first;
        res = second;
        second = first->next;
        while (first && second && second->next) {
            first->next = second->next;;
            first = first->next;
            second->next = first->next;
            first->next = second;
            first = first->next;
            second = second->next;
        }

        return res;

    }
};


int main(int argc, char const *argv[])
{
    Solution sl;
    ListNode *p1 = new ListNode(1);
    ListNode *pt = p1;
    for (int i = 2; i <= 10; i++) {
        ListNode *tmp = new ListNode(i);
        pt->next = tmp;
        pt = pt->next;
        tmp = tmp->next;
        delete tmp;
    }
    ListNode *res = sl.swapPairs(p1);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << '\n';


    return 0;
}

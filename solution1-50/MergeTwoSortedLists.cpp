#include <iostream>
#include <algorithm>

using namespace std;


/* Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 != NULL) {
            return l2;
        } else if (l1 != NULL && l2 == NULL) {
            return l1;
        } else if (l1 == NULL && l2 == NULL){
            return l1;
        }
        ListNode *result = new ListNode(0);
        ListNode *pt = result;
        if (l1->val >= l2->val) {
            pt->val = l2->val;
            l2 = l2->next;
        } else {
            pt->val = l1->val;
            l1 = l1->next;
        }
        while (l1 != NULL || l2 != NULL) {
            if (l1 != NULL && l2 != NULL) {
                    cout << 0;
                if (l1->val >= l2->val) {
                    cout << 1;
                    ListNode *tmp = new ListNode(0);
                    pt->next = tmp;
                    pt = pt->next;
                    pt->val = l2->val;
                    l2 = l2->next;
                    //delete tmp;
                } else {
                    cout << 2;
                    ListNode *tmp = new ListNode(0);
                    pt->next = tmp;
                    pt = pt->next;
                    pt->val = l1->val;
                    l1 = l1->next;
                    //delete tmp;
                }
            } 
            else if (l1 != NULL) {
                    cout << 3;
                ListNode *tmp = new ListNode(0);
                pt->next = tmp;
                pt = pt->next;
                pt->val = l1->val;
                l1 = l1->next;
                //delete tmp;
            } 
            else if (l2 != NULL) {
                    cout << 4;
                ListNode *tmp = new ListNode(0);
                pt->next = tmp;
                pt = pt->next;
                pt->val = l2->val;
                l2 = l2->next;
                //delete tmp;
            }
        }
        return result;
    }
};




int main(int argc, char const *argv[])
{
    /* [1], 1 */
    Solution sl;
    ListNode *p1 = new ListNode(1);
    ListNode *pt = p1;
    for (int i = 2; i <= 10; i++) {
        ListNode *tmp = new ListNode(i);
        pt->next = tmp;
        pt = pt->next;
        //delete tmp;
    }
    
    ListNode *p2 = new ListNode(1);
    pt = p2;
    for (int i = 2; i <= 10; i++) {
        ListNode *tmp = new ListNode(i);
        pt->next = tmp;
        pt = pt->next;
        //delete tmp;
    }
    ListNode *p3 = new ListNode(1);
    pt = p3;
    for (int i = 2; i <= 10; i++) {
        ListNode *tmp = new ListNode(i);
        pt->next = tmp;
        pt = pt->next;
        //delete tmp;
    }
    ListNode *res = sl.mergeTwoLists(p1, p2);
    while(res->next != NULL) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}

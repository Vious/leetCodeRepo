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
    // first count length, O(2n)
    /* ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pt = head;
        if (pt == NULL) return pt;
        unsigned int len = 0;
        while (pt != NULL) {
            pt = pt->next;
            len++;
        }
        if (len < n) {
            return head;
        }
        if (len == n) {
            head = head->next;
            return head;
        }
        pt = head;
        for (unsigned int i = 0; i < len - n - 1; i++) {
            pt = pt->next;
        }
        ListNode *pNew = pt->next;
        pt->next = pNew->next;
        delete pNew;
        return head;
    } */

    //one pass way
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pt = head, *pt2 = head;
        if (pt == NULL) return head;
        for (unsigned int i = 0; i < n; i++) {
            if (pt->next != NULL)
                pt = pt->next;
        }
        if (n == 1 && pt->next == NULL) {
            return pt->next;
        }
        else if (pt->next == NULL) {
            pt2->next = pt2->next->next;
            return pt2;
        } 
        while(pt->next != NULL) {
            pt = pt->next;
            pt2 = pt2->next;
        }
        pt2->next = pt2->next->next;

        return head;

    }


};





int main(int argc, char const *argv[])
{
    /* [1], 1 */
    Solution sl;
    ListNode *p = new ListNode(1);
    p->next = new ListNode(2);
    sl.removeNthFromEnd(p, 1);

    return 0;
}

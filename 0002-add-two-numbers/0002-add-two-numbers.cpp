/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0);
        ListNode* tail = &dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sumVal = carry;
            if (l1 != nullptr) {
                sumVal += l1->val;
                l1 = l1->next;
                }
                if (l2 != nullptr) {
                    sumVal += l2->val;
                    l2 = l2->next;
                }
                carry = sumVal / 10;
                tail->next = new ListNode(sumVal % 10);
                tail = tail->next;
        }
        return dummyHead.next;
    }
};
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
    ListNode *reverse(ListNode *start , ListNode *end)
    {
        ListNode *previous = NULL;
        ListNode *curr = start;
        while(curr != end)
        {
            ListNode *temp = curr->next;
            curr->next = previous;
            previous = curr;
            curr = temp;
        }
        return previous;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *ptr = head;
        int count = 0;
        while(ptr != NULL && count < k)
        {
            ptr = ptr->next;
            count++;
        }
        if(count < k) return head;

        ListNode *newHead = reverse(head,ptr);
        head->next = reverseKGroup(ptr , k);
        return newHead;
    }
};
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
    int length(ListNode *head)
    {
        ListNode *temp = head;
        int count = 0;
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        if(head->next == NULL && n == 1) return NULL;

        int len = length(head);
        if(len == n)
        {
            return head->next;
        }
        ListNode *temp = head;
        for(int i=1 ; i<len-n ; i++)
        {
            temp = temp->next;
        }
        ListNode *backup = temp->next->next;
        delete (temp->next);
        temp->next = backup;
    
        return head;
    }
};
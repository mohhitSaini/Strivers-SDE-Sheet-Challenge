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
    private:
    int getLength(ListNode* head)
    {
        if(head->next==NULL)
        return 1;
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        return count;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=getLength(head);
        if(n==length)
        return head->next;
        int count=length-n-1;
        ListNode* temp=head;
        while(count--&&temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;

    }
};
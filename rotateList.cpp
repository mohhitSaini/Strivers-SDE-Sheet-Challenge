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
        if(head==NULL)
        return 0;
        if(head->next==NULL)
        return 1;
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        return count;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {

        int length=getLength(head);
        cout<<length;
        if(length==0)
        return head;
        if(k%length==0)
        return head;
        int p1=length-(k%length)-1;
        ListNode* prev=head;
        while(p1--&&prev->next!=NULL)
        {
            prev=prev->next;
        }
        ListNode* newHead=prev->next;
        prev->next=NULL;
        if(newHead->next==NULL)
        newHead->next=head;
        else
        {
        ListNode* tail=newHead;
        int p2=k-1;
        while(p2--&&tail->next!=NULL)
        {
            tail=tail->next;
        }

        tail->next=head;
        }

        return newHead;

    }
};
#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/



Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first==NULL)
    return second;
    if(second==NULL)
    return first;
    Node<int>* l1=NULL;
    Node<int>* l2=NULL;
    if (first->data < second->data) {
      l1 = first;
      l2 = second;
    }
    else{
        l1=second;
        l2=first;
    }
    Node<int>*head=l1;
    while(l1!=NULL&&l2!=NULL)
    {
        Node<int>* temp=NULL;
        while(l1!=NULL&&l1->data<=l2->data)
        {
            temp=l1;
            l1=l1->next;
        }
        temp->next=l2;
        swap(l1,l2);

    }
    return head;
}

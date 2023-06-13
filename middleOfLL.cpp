/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *findMiddle(Node *head) {
    Node* mid=head;
    Node* hop=head;
    if(head==NULL||head->next==NULL)
    return head;
    while(hop!=NULL&&hop->next!=NULL)
    {
        mid=mid->next;
        hop=hop->next->next;
    }
    return mid;
}


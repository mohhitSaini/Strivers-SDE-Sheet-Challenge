#include<bits/stdc++.h>

struct Node {

    int val, key;

    Node* next, * prev;

 

    Node(int key, int val) : val(val), key(key), next(nullptr), prev(nullptr) {}

};

 

class LRUCache {

private:

    unordered_map<int,Node*> cache;

    int size , cap;

    Node*head, *tail;

public:

    LRUCache(int capacity) {

        cap = capacity;

        size = 0;

        head = new Node(-1,-1);

        tail = new Node(-1,-1);

        tail->prev = head;

        head->next = tail;

    }

    

    int get(int key) {

        if(!cache.count(key)) return -1;

        Node*temp = cache[key];

        updateAsRecent(temp);

        return temp->val;

    }

    

    void put(int key, int value) {

        Node*temp = nullptr;

        if(cache.count(key)){

            temp = cache[key];

            temp->val = value;

            updateAsRecent(temp);

        }else{

            temp = new Node(key,value);

            insertNewNode(temp);

        }

    }

 

private:

    void updateAsRecent(Node* curr){

        curr->prev->next = curr->next;

        curr->next->prev = curr->prev;

 

        curr->prev = tail->prev;

        curr->next = tail;

        tail->prev = curr;

        curr->prev->next = curr;

    }

 

    void deleteLeastRecent(){

        Node* temp = head->next;

        head->next = head->next->next;

        head->next->prev = head;

        cache.erase(temp->key);

        size--;

        delete temp;

    }

 

    void insertNewNode(Node* temp){

        if(++size > cap) deleteLeastRecent();

        cache[temp->key] = temp;

        

        temp->prev = tail->prev;

        temp->next = tail;

        tail->prev = temp;

        temp->prev->next = temp;   

    }

};

 
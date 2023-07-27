class Queue {
    stack<int>pushing;
    stack<int>popping;
    
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        while(!popping.empty())
        {
            pushing.push(popping.top());
            popping.pop();
        }
        pushing.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        while(!pushing.empty())
        {
            popping.push(pushing.top());
            pushing.pop();
        }
        if(popping.empty())
        return -1;
        int val=popping.top();
        popping.pop();
        return val;
    }

    int peek() {
        // Implement the peek() function here.
        while(!pushing.empty())
        {
            popping.push(pushing.top());
            pushing.pop();
        }
        if(popping.empty())
        return -1;
        int val=popping.top();
        return val;
    }

    bool isEmpty() {
        if(popping.empty()&&pushing.empty())
        return true;
        return false;
    }
};
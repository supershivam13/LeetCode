class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1,q2;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        swap(q1,q2);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x=q2.front();
        q2.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return q2.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
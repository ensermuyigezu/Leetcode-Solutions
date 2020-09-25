class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
        int sz = q1.size();
        while(sz > 1){
            int a = q1.front();
            q1.pop();
            q1.push(a);
            sz--;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int a = q1.front();
        q1.pop();
        return a;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.size() == 0;
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
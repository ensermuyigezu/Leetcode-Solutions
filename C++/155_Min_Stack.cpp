class MinStack {
   
public:
    /** initialize your data structure here. */
    vector<int> a;
    multiset<int> b;
    void push(int x) {
        a.push_back(x);
        b.insert(x);
    }
    
    void pop() {
        auto itr = b.find(a[a.size()-1]);
        if(itr != b.end()){
            b.erase(itr);
        }
        a.pop_back();
    }
    
    int top() {
        return a[a.size()-1];
    }
    
    int getMin() {
        return *b.begin();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
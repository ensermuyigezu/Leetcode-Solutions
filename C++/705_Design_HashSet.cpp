class MyHashSet {
public:
    /** Initialize your data structure here. */
    unordered_set<int> a;
    MyHashSet() {
        
    }
    
    void add(int key) {
        a.insert(key);
    }
    
    void remove(int key) {
        a.erase(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return a.count(key) == 1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
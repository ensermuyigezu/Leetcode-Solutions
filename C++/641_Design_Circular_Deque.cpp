class MyCircularDeque {
    class Node {
    public:
        int val;
        Node* next = NULL;
        Node* prev = NULL;
        Node(int v){
            val = v;
        }
    };
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    Node* head;
    Node* tail;
    int size = 0;
    int K;
    MyCircularDeque(int k) {
        K = k;
        Node* prev = new Node(0);
        head = prev;
        auto temp = prev; 
        for(int i = 1; i < k; i++){
            Node* current = new Node(0);
            temp->next = current;
            current->prev = temp;
            temp = current;
        }
        temp->next = head;
        head->prev = temp;
        tail = NULL;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(size == K) return false;
        if(tail == NULL){
            head->val = value;
            tail = head;
        } else {
            head->prev->val = value;
            head = head->prev;
        }
        size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(size == K) return false;
        if(tail == NULL){
            head->val = value;
            tail = head;
        } else {
            tail->next->val = value;
            tail = tail->next;
        }
        size++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(size == 0) return false;
        head = head->next;
        size--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(size == 0) return false;
        tail = tail->prev;
        size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(size == 0) return -1;
        return head->val;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(size == 0) return -1;
        return tail->val;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == K;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
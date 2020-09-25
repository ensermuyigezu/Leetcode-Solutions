class MyCircularQueue {
    class Node {
    public:
        int val;
        Node *next = NULL;
        Node(int v){
            val = v;
        }
    };
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    Node* head;
    Node* tail;
    int size = 0;
    int K;
    MyCircularQueue(int k) {
        K = k;
        Node* prev = new Node(0);
        head = prev;
        auto temp = prev;
        for(int i = 1; i < k; i++){
            Node* current = new Node(0);
            temp->next = current;
            temp = current;
        }
        temp->next = head;
        tail = NULL;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(size == K) return false;
        if(tail == NULL){
            head->val = value;
            tail = head;
        } else {
            tail->next->val = value;
            tail = tail->next;
        }
        size += 1;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(size == 0) return false;
        head = head->next;
        size--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(size == 0) return -1;
        return head->val;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(size == 0) return -1;
        return tail->val;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size == K;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
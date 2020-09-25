class MyLinkedList {
    class Node {
    public:
        int val;
        Node* next = NULL;
        Node(int v){
            val = v;
        }
        Node(int v, Node* n){
            val = v;
            next = n;
        }
    };
public:
    /** Initialize your data structure here. */
    Node* head;
    MyLinkedList() {
        head = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        auto current = head;
        while(true){
            if(current == NULL) return -1;
            if(index == 0) return current->val;
            current = current->next;
            index -= 1;
        }
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if(head == NULL){
            Node* node = new Node(val);
            head = node;
        } else {
            Node*node = new Node(val, head);
            head = node;
        }
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        auto current = head;
        if(current == NULL) {
            addAtHead(val);
            return;
        }
        while(current->next != NULL){
            current = current->next;
        }
        Node* node = new Node(val);
        current->next = node;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        auto current = head;
        if(current == NULL || index == 0){
            addAtHead(val);
            return;
        }
        for(int i = 0; i < index - 1; i++){
            current = current->next;
            if(current == NULL) return;
        }
        auto temp = current->next;
        Node* node = new Node(val);
        current->next = node;
        node->next = temp;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        auto current = head;
        if(current == NULL) return;
        if(index == 0){
            head = current->next;
            return;
        }
        for(int i = 0; i < index - 1; i++){
            current = current->next;
            if(current == NULL) return;
        }
        if(current->next == NULL) return;
        current->next = current->next->next;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
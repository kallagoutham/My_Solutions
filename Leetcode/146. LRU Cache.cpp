class LRUCache {
public:

    class Node{
        public : 
            int key, val;
            Node* next;
            Node* prev;

            Node(int key, int val){
                this->key = key;
                this->val = val;
                next = NULL;
                prev = NULL; 
            }

    };

    int capacity;
    map<int, Node*> mp;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode){
        newNode->next = head->next;
        head->next->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
    }

    int deleteLastNode(){
        Node* node = tail->prev;
        int deletedKey = node->key;
        node->prev->next = tail;
        tail->prev = node->prev;
        return deletedKey;
    }

    void deleteNode(Node* node){
        Node* prevv = node->prev;
        Node* nextt = node->next;

        prevv->next = nextt;
        nextt->prev = prevv;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            int vall =  mp[key]->val;
            deleteNode(mp[key]);
            Node* nodeToBeAdded = new Node(key,vall);
            addNode(nodeToBeAdded);
            mp[key] = nodeToBeAdded;
            return vall;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            deleteNode(mp[key]);
        }
        else if(mp.size() == this->capacity){
            int deletedKey = deleteLastNode();
            mp.erase(deletedKey);
            cout<< "Deleted Key because of capacity : " << deletedKey<<endl;
        }
        Node* nodeToBeAdded = new Node(key,value);
        addNode(nodeToBeAdded);
        mp[key] = nodeToBeAdded;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

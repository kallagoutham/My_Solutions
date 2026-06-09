class LFUCache {
public:
    class Node {
    public:
        int key, value, freq;
        Node* next;
        Node* prev;

        Node(int key, int value) {
            this->key = key;
            this->value = value;
            this->freq = 1;
            next = nullptr;
            prev = nullptr;
        }
    };

    class List {
    public:
        Node* head;
        Node* tail;
        int size;

        List() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void addNode(Node* nodeToBeAdded) {
            nodeToBeAdded->next = head->next;
            head->next->prev = nodeToBeAdded;
            head->next = nodeToBeAdded;
            nodeToBeAdded->prev = head;
            size++;
        }

        void deleteNode(Node* node) {
            Node* prevv = node->prev;
            Node* nextt = node->next;

            prevv->next = nextt;
            nextt->prev = prevv;

            size--;
        }

        Node* removeLRUNode() {
            Node* node = tail->prev;
            deleteNode(node);
            return node;
        }
    };

    int capacity;
    int minFreq;
    int currentSize;

    unordered_map<int, Node*> mp;          // key -> node
    unordered_map<int, List*> freqList;    // freq -> DLL of nodes

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
        currentSize = 0;
    }

    void updateFreq(Node* node) {
        int oldFreq = node->freq;

        freqList[oldFreq]->deleteNode(node);

        if (oldFreq == minFreq && freqList[oldFreq]->size == 0) {
            minFreq++;
        }

        node->freq++;

        int newFreq = node->freq;

        if (freqList.find(newFreq) == freqList.end()) {
            freqList[newFreq] = new List();
        }

        freqList[newFreq]->addNode(node);
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];
        updateFreq(node);

        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }

        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            updateFreq(node);
            return;
        }

        if (currentSize == capacity) {
            Node* nodeToDelete = freqList[minFreq]->removeLRUNode();

            mp.erase(nodeToDelete->key);
            delete nodeToDelete;

            currentSize--;
        }

        Node* newNode = new Node(key, value);

        if (freqList.find(1) == freqList.end()) {
            freqList[1] = new List();
        }

        freqList[1]->addNode(newNode);
        mp[key] = newNode;

        minFreq = 1;
        currentSize++;
    }
};

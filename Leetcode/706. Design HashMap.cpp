class MyHashMap {
    vector<int> res;
public:
    MyHashMap() {
        res.resize(1e+6+1,-1);
    }
    
    void put(int key, int value) {
        res[key]=value;
    }
    
    int get(int key) {
        return res[key];
    }
    
    void remove(int key) {
        res[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

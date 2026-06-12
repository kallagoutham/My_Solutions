class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> mp;
    vector<int> v;

    RandomizedCollection() {}

    bool insert(int val) {
        bool isNew = mp.find(val) == mp.end();

        v.push_back(val);
        mp[val].insert(v.size() - 1);

        return isNew;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end()) {
            return false;
        }

        int idxToRemove = *mp[val].begin();
        int lastIdx = v.size() - 1;
        int lastVal = v.back();
        mp[val].erase(idxToRemove);
        if (idxToRemove != lastIdx) {
            v[idxToRemove] = lastVal;
            mp[lastVal].erase(lastIdx);
            mp[lastVal].insert(idxToRemove);
        }
        v.pop_back();

        if (mp[val].empty()) {
            mp.erase(val);
        }

        return true;
    }

    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

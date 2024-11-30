class Solution {
public:
    static bool compare(const string& a, const string& b) {
        return a.size() < b.size();
    }
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char,int> m;
        string s="";
        for(char c : licensePlate){
            if(c-'0'  > 9){
                m[tolower(c)]++;
            }
        }
        stable_sort(words.begin(), words.end(), compare);
        unordered_map<char,int> t;
        for(auto i : words){
            for(char j : i){
                t[tolower(j)]++;
            }
            for(auto p=m.begin();p!=m.end();p++){
                if(t.find(p->first)!=t.end()){
                    if(p->second > t[p->first]){
                        t.clear();
                        goto l;
                    }
                }else{
                    t.clear();
                    goto l;
                }
            }
            t.clear();
            return i;
            l:;
        }
        return s;
    }
};

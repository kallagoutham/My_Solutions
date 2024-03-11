class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> m;
        for(char c:s){
            m[c]++;
        }
        string res;
        for(int i=0;i<order.size();i++){
            if(m.find(order[i])!=m.end()){
                while(m[order[i]]--){
                    res.push_back(order[i]);
                }
                m.erase(order[i]);
            }
        }
        for(auto i=m.begin();i!=m.end();i++){
            while((i->second)--){
                res.push_back(i->first);
            }
        }
        return res;
    }
};

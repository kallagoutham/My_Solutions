class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string,int> m;
        int n=s.size();
        if(n<11){
            return res;
        }
        string str="";
        for(int i=0;i<10;i++){
            str.push_back(s[i]);
        }
        m[str]++;
        for(int i=10;i<n;i++){
            str.erase(0, 1);
            str.push_back(s[i]);
            m[str]++;
        }
        for(auto i=m.begin();i!=m.end();i++){
            if(i->second > 1){
                res.push_back(i->first);
            }
        }
        return res;
    }
};

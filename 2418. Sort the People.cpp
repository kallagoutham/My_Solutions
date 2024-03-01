class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> m;
        vector<string> res;
        for(int i=0;i<names.size();i++){
            m[heights[i]]=names[i];
        }
        for(auto i=m.begin();i!=m.end();i++){
            res.push_back(i->second);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

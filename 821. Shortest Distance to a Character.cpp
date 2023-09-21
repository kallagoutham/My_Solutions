class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> idx;
        vector<int> res;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == c){
                idx.push_back(i);
            }
        }
        for(int i = 0; i < s.size(); i++){
            int m = 10000;
            for(int j : idx){
                m = min(m,abs(j-i));
            }
            res.push_back(m);
        }
        return res;
    }
};

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        set<char> st={'b','a','l','o','n'};
        int res = INT_MAX;
        unordered_map<char,int> mp;
        for(char i:text){
            if(st.count(i)){
                mp[i]++;
            }
        }
        if(mp.size()!=5){
            return 0;
        }
        for(auto i=mp.begin();i!=mp.end();i++){
            if(i->first == 'l' || i->first=='o'){
                res = min(res,i->second/2);
            }else{
                res = min(res,i->second);
            }
        }
        return res;
    }
};

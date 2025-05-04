class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>,int> m;
        int res=0;
        for(vector<int> i:dominoes){
            sort(i.begin(),i.end());
            m[i]++;
        }
        for(auto i=m.begin();i!=m.end();i++){
            res+=((i->second*(i->second -1))/2);
        }
        return res;
    }
};

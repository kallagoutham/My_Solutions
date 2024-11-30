class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int> m;
        vector<int> f;
        for(char c:word){m[c]++;}
        int res=INT_MAX;
        for(auto i=m.begin();i!=m.end();i++){
            f.push_back(i->second);
        }
        sort(f.begin(),f.end(),greater<int>());
        for(int i=0;i<f.size();i++){
            int tmp=f[i];
            int t=0;
            for(int j:f){
                if(j>tmp+k){t+=(j-(tmp+k));}
                else if(j<tmp){t+=j;}
            }
            res=min(res,t);
        }
        if(res==INT_MAX){
            return 0;
        }
        return res;
    }
};

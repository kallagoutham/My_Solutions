class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long res=0;
        sort(skill.begin(),skill.end());
        int n=skill.size();
        int t=skill[0]+skill[n-1];
        res+=(skill[0]*skill[n-1]);
        for(int i=1;i<n/2;++i){
            if(t==skill[i]+skill[n-1-i]){
                res+=(skill[i]*skill[n-1-i]);
            }else{
                return -1;
            }
        }
        return res;
    }
};

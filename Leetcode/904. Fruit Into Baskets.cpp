class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> m;
        int res=0,n=fruits.size(),i=0,j=0;
        while(i<n){
            if(m.size() > 2){
                if(--m[fruits[j]]==0){
                    m.erase(fruits[j]);
                }
                j++;
            }
            m[fruits[i]]++;
            if(m.size() <= 2){
                res = max(res,i-j+1);
            }
            i++;
        }
        return res;
    }
};å

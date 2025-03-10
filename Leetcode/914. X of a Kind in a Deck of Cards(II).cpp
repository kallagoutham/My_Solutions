class Solution {
private:
        int f(int a,int b){ 
        if(a == 0){
            return b;
        }
        
        return f(b%a,a);
    }
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> mp;
        int n = deck.size();
        
        for(int i=0;i<n;i++){
            mp[deck[i]]++;
        }
        
        int gcd = 0;
        
        for(auto it=mp.begin();it!=mp.end();it++){
            gcd = f(gcd,(*it).second);
        }
        
        if(gcd > 1){
            return true;
        }

        return false;
    }
};

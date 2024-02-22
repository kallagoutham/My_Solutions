/* Using Vectors */
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustcount(n + 1, 0); 
        for (const auto& relation : trust) {
            trustcount[relation[0]]--;  
            trustcount[relation[1]]++;  
        }
        for (int i = 1; i <= n; ++i) {       
            if (trustcount[i] == n - 1) {
                return i;
            }
        }
        return -1;   
    }
};


/* Using sets approach */
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1){return 1;}
        unordered_map<int,set<int>> m;
        set<int> trustingPeople;
        for(int i=0;i<trust.size();i++){
            m[trust[i][1]].insert(trust[i][0]);
            trustingPeople.insert(trust[i][0]);
        }
        for(auto i=m.begin();i!=m.end();i++){
            if(i->second.size()>=n-1 && trustingPeople.find(i->first)==trustingPeople.end()){
                return i->first;
            }
        }
        return -1;
    }
};

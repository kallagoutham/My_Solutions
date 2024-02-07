class Solution {
public:
    vector<int> combination;
    vector<vector<int>> res;
    void combinations(vector<int>& combination,int n,int k,int max){
        if(n>max){return;}
        combination.push_back(n);
        if(combination.size()==k){res.push_back(combination);}
        combinations(combination,n+1,k,max);
        combination.pop_back();
        combinations(combination,n+1,k,max);
    }
    vector<vector<int>> combine(int n, int k) {
        combinations(combination,1,k,n);
        return res;
    }
};

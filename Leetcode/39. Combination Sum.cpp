class Solution {
public:
    set<vector<int>> set;
    vector<int> combination;
    void combinationsSum(vector<int>& candidates,int target,int idx,int currentsum){
        if(currentsum > target || candidates.size()-1<idx){return;}
        if(currentsum==target){set.insert(combination);}
        combinationsSum(candidates,target,idx+1,currentsum);
        combination.push_back(candidates[idx]);
        combinationsSum(candidates,target,idx,currentsum+candidates[idx]);
        combinationsSum(candidates,target,idx+1,currentsum+candidates[idx]);
        combination.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        combinationsSum(candidates,target,0,0);
        vector<vector<int>> res(set.begin(),set.end());
        return res;
    }
};

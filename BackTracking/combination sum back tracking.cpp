class Solution {
public:
    set<vector<int>> resSet;
    vector<int> temp;
    void generatecombinationSum(vector<int>& candidates,vector<int>& combination,int sum,int target,int idx){
        if(sum==target){
            temp.resize(combination.size());
            copy(combination.begin(),combination.end(),temp.begin());
            sort(temp.begin(),temp.end());
            resSet.insert(temp);
            temp.clear();
            return;
        }
        if(idx==candidates.size() || sum > target){return;}
        combination.push_back(candidates[idx]);
        generatecombinationSum(candidates,combination,sum+candidates[idx],target,idx+1);
        combination.pop_back();
        generatecombinationSum(candidates,combination,sum,target,idx+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combination;
        generatecombinationSum(candidates,combination,0,target,0);
        vector<vector<int>> res(resSet.size());
        copy(resSet.begin(), resSet.end(), res.begin());
        return res;
    }
};

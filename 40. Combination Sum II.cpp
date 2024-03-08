class Solution {
private:
    vector<vector<int>> res;

public:
    void solve(vector<int>& candidates, int target, int idx, vector<int>& combination) {
        if (target == 0) {
            res.push_back(combination);
            return;
        }
        if (idx == candidates.size() || target < candidates[idx]) {
            return;
        }
        int temp = candidates[idx];
        combination.push_back(candidates[idx]); 
        solve(candidates, target - candidates[idx], idx + 1, combination); 
        combination.pop_back(); 
        int i = 1;
        while (idx + i < candidates.size() && candidates[idx + i] == temp) {
            i++; 
        }
        solve(candidates, target, idx + i, combination); 
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combination;
        sort(candidates.begin(), candidates.end()); 
        solve(candidates, target, 0, combination); 
        return res; 
    }
};

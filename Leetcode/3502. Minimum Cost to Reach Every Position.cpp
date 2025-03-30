class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int> answer;
        answer.push_back(cost[0]);
        int n=cost.size();
        int mini=cost[0];
        for(int i=1;i<n;i++){
            mini=min(mini,cost[i]);
            answer.push_back(mini);
        }
        return answer;
    }
};

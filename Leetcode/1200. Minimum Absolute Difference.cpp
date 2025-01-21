class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int mini=INT_MAX;
        int n=arr.size();
        unordered_map<int,vector<vector<int>>> m;
        for(int i=0;i<n-1;i++){
            mini=min(mini,arr[i+1]-arr[i]);
            vector<int> t(2);
            t={arr[i],arr[i+1]};
            m[arr[i+1]-arr[i]].push_back(t);
        }
        return m[mini];
    }
};

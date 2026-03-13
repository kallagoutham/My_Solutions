class Solution {
public:
    bool isValid(int pos,int n,vector<bool>& visited){
        if (pos < 0 || pos >= n) {
            return false;
        }
        if (visited[pos]) {
            return false;
        }
        return true;
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int t=q.front();
            q.pop();
            if(arr[t]==0){
                return true;
            }
            if(isValid(t+arr[t],n,visited)){
                q.push(t+arr[t]);
            }
            if(isValid(t-arr[t],n,visited)){
                q.push(t-arr[t]);
            }
            visited[t]=true;
        }
        return false;
    }
};

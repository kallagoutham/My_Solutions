class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> dependency(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto& p:prerequisites){
            adj[p[1]].push_back(p[0]);
            dependency[p[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(dependency[i]==0)    q.push(i);
        }
        while(!q.empty()){
            int t=q.front();
            q.pop();
            for(int i:adj[t]){
                dependency[i]--;
                if(dependency[i]==0)   q.push(i);
            }
        }
        for(int i:dependency){
            if(i!=0)    return false;
        }
        return true;
    }
};

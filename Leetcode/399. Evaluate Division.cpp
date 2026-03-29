class Solution {
public:
    double BFS(string src,string target,map<string, vector<pair<string,double>>>& adj){
        if(adj.find(src) == adj.end() || adj.find(target)==adj.end()){
            return -1.0;
        }
        if(src == target){
            return 1.0;
        }
        set<string> visited;
        queue<pair<string,double>> q;
        q.push(make_pair(src,1.0));
        visited.insert(src);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                pair<string,double> node = q.front();
                q.pop();
                if(node.first == target){
                    return node.second;
                }
                for(auto it : adj[node.first]){
                    if(!visited.count(it.first)){
                        visited.insert(it.first);
                        q.push(make_pair(it.first,node.second*it.second));
                    }
                }
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string,double>>> adj;
        int n=equations.size();
        for(int i=0;i<n;i++){
            adj[equations[i][0]].push_back(make_pair(equations[i][1],values[i]));
            adj[equations[i][1]].push_back(make_pair(equations[i][0],1/values[i]));
        }
        vector<double> res;
        for(vector<string> query:queries){
            res.push_back(BFS(query[0],query[1],adj));
        }
        return res;
    }
};

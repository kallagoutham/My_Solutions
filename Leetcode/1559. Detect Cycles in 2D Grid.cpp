using p = std::pair<std::pair<int,int>, std::pair<int,int>>;

class Solution {
public:
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
    bool isValid(int i,int j,int m, int n){
        return i>=0 && i<m && j>=0 && j<n;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                if(visited[i][j]) continue;
                
                queue<p> q;
                q.push({{i,j},{-1,-1}});
                visited[i][j] = true;
                
                while(!q.empty()){
                    auto curr = q.front(); q.pop();
                    
                    auto point = curr.first;
                    auto parent = curr.second;
                    
                    for(auto dir : dirs){
                        int ni = point.first + dir.first;
                        int nj = point.second + dir.second;
                        
                        if(!isValid(ni,nj,m,n)) continue;
                        if(grid[ni][nj] != grid[i][j]) continue;
                        
                        if(!visited[ni][nj]){
                            visited[ni][nj] = true;
                            q.push({{ni,nj}, point});
                        } else {
                            if(make_pair(ni,nj) != parent){
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};

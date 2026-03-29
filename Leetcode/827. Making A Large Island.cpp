class DisjointSet {
public:
    vector<int> parent;
    vector<int> size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n);
        for (int node = 0; node < n; node++) {
            parent[node] = node;
            size[node] = 1;
        }
    }

    int findUParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionNodes(int x, int y) {
        int ulp_x = findUParent(x);
        int ulp_y = findUParent(y);

        if (ulp_x == ulp_y) return;

        if (size[ulp_x] < size[ulp_y]) {
            parent[ulp_x] = ulp_y;
            size[ulp_y] += size[ulp_x];
        } else {
            parent[ulp_y] = ulp_x;
            size[ulp_x] += size[ulp_y];
        }
    }
};

class Solution {
public:
    bool isValid(int row,int col,int m,int n){
        return (row>=0 && row<n && col>=0 && col<n);
    }

    int largestIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        DisjointSet ds(row * col);

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col;j++) {
                if (grid[i][j] == 1) {
                    int currentNode = (col * i) + j;

                    for (int d = 0; d < 4; d++) {
                        int ni = i + dx[d];
                        int nj = j + dy[d];

                        if (isValid(ni,nj,row,col) && grid[ni][nj] == 1) {
                            int neighborNode = col * ni + nj;
                            ds.unionNodes(currentNode, neighborNode);
                        }
                    }
                }
            }
        }

        int maxIslandSize = 0;
        bool hasZero = false;
        unordered_set<int> uniqueRoots;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col;j++) {
                if (grid[i][j] == 0) {
                    hasZero = true;
                    int currentIslandSize = 1;

                    for (int d = 0; d < 4; d++) {
                        int ni = i + dx[d];
                        int nj = j + dy[d];

                        if (isValid(ni,nj,row,col) &&grid[ni][nj] == 1) {
                            int neighborNode = col * ni + nj;
                            int root = ds.findUParent(neighborNode);
                            uniqueRoots.insert(root);
                        }
                    }

                    for (int root : uniqueRoots) {
                        currentIslandSize += ds.size[root];
                    }

                    uniqueRoots.clear();
                    maxIslandSize = max(maxIslandSize, currentIslandSize);
                }
            }
        }
        if (!hasZero) return row * col;
        return maxIslandSize;
    }
};

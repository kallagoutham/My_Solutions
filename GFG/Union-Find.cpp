// User function Template for C++

class Solution {
  public:
    // Function to merge two nodes a and b.
    
    int find(int par[], int node){
        if(node == par[node]){
            return node;
        }
        return par[node] = find(par,par[node]);
    }
    
    void union_(int a, int b, int par[], int rank[]) {
        // code here
        int ulp_a = find(par,a);
        int ulp_b = find(par,b);
        if(ulp_a == ulp_b){return;}
        if(rank[ulp_a] < rank[ulp_b]){
            par[ulp_a] = ulp_b;
        }else if(rank[ulp_a] > rank[ulp_b]){
            par[ulp_b] = ulp_a;
        }else{
            par[ulp_b] = ulp_a;
            rank[ulp_a]++;
        }
    }

    // Function to check whether 2 nodes are connected or not.
    bool isConnected(int x, int y, int par[], int rank[]) {
        
        // code here
        int ulp_x = find(par,x);
        int ulp_y = find(par,y);
        return ulp_x == ulp_y;
    }
};

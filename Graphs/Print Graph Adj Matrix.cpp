#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void printGraph(vector<vector<int>> adjMatrix){
    int i=1;
    for(int i=0;i<adjMatrix.size();i++){
        cout<<"Node : "<<i <<" Neighbours : ";
        for(int j=0;j<adjMatrix[i].size();j++){
            if(adjMatrix[i][j]==1){
                cout<<" "<<j;
            }
        }
        cout<<endl;
    }
}

int main() {
    vector<vector<int>> edgeList = { {1,2},{2,3},{3,4},{1,4},{4,2}};
    int n=5;
    vector<vector<int>> adjMatrix(n,vector<int>(n,0));
    for(vector<int> edge:edgeList){
        adjMatrix[edge[0]][edge[1]]=1;
        adjMatrix[edge[1]][edge[0]]=1;
    }
    printGraph(adjMatrix);
    return 0;
}
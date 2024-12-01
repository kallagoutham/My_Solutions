#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void printGraph(unordered_map<int,vector<int>> adjList){
    for(auto i=adjList.begin();i!=adjList.end();i++){
        cout<<"Node : "<<i->first <<" Neighbours : ";
        for(int j=0;j<i->second.size();j++){
            cout<<i->second[j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    vector<vector<int>> edgeList = { {1,2},{2,3},{3,4},{1,4},{4,2}};
    int n=5;
    unordered_map<int,vector<int>> adjList;
    for(vector<int> edge:edgeList){
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }
    printGraph(adjList);
    return 0;
}
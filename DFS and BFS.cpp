
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        map<int,bool> visited;
        map<int,list<int>> adj;
        void addEdge(int v,int w);
        void DFS(int v);
        void BFS(int v);
};

void Graph::addEdge(int v,int w){
    adj[v].push_back(w);
}

void Graph::DFS(int v){
    visited[v]=true;
    cout<<v<<" ";
    for(auto i=adj[v].begin();i!=adj[v].end();i++){
        if(!visited[*i]){
            DFS(*i);
        }
    }
}

void Graph::BFS(int v){
    queue<int> q;
    visited[v] = true;
    q.push(v);
     while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";
         for (auto i = adj[currentNode].begin();i!=adj[currentNode].end();i++) {
            if (!visited[*i]) {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
}

int main()
{
    Graph g;
    g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	//Comment the Method which is not required as it makes the visited vector false
	cout<<"The Depth First Search Traversal Starting from the Node 1 is : "<<endl;
 	g.DFS(1);
	cout<<endl;
	cout<<"The Breadth First Search Traversal Starting from the Node 1 is : "<<endl;
	g.BFS(2);
	return 0;
}

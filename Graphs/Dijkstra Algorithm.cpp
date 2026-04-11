class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adjList(V);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        vector<int> distance(V, INT_MAX);
        distance[src] = 0;

        // {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Skip outdated entries
            if (dis > distance[node]) continue;

            for (auto &neighbor : adjList[node]) {
                int adjNode = neighbor.first;
                int adjDistance = neighbor.second;

                if (dis + adjDistance < distance[adjNode]) {
                    distance[adjNode] = dis + adjDistance;
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }

        return distance;
    }
};

class Solution {
public:
    using Graph = unordered_map<int, vector<pair<int, double>>>;

    double maximumProbability(int n, const vector<vector<int>>& edges, const vector<double>& succProb, int start, int end) {
    Graph graph;
    for (int i = 0; i < edges.size(); ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        double prob = succProb[i];
        graph[u].emplace_back(v, prob);
        graph[v].emplace_back(u, prob); 
    }
    priority_queue<pair<double, int>> pq;
    vector<double> maxProb(n, 0.0);
    maxProb[start] = 1.0;
    pq.emplace(1.0, start);
    
    while (!pq.empty()) {
        double currProb = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (u == end) {
            return currProb;
        }
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            double prob = neighbor.second;

            double newProb = currProb * prob;
            if (newProb > maxProb[v]) {
                maxProb[v] = newProb;
                pq.emplace(newProb, v);
            }
        }
    }
    return 0.0;
}
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        double result = maximumProbability(n, edges, succProb, start_node, end_node);
        return result;
    }
};

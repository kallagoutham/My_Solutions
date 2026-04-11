using p = pair<int,int>;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // The intuition here is the signal has to reach the every other node 
        // means it has to traverse all nodes. 
        // My pick here is to find the respective shortest time to reach every node and the maximum of all such things is equal to our answer. 

        vector<vector<p>> adjList(n+1);
        // create a adjList
        for(vector<int> t : times){
            adjList[t[0]].push_back({t[1],t[2]});
        }

        vector<int> time(n+1,INT_MAX);
        // time for the signal to reach the same node is 0
        time[k] = 0;
        // create a min-heap {time,node}
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,k});

        // actual traversal
        while(!pq.empty()){
            int node = pq.top().second;
            int t = pq.top().first;
            pq.pop();
            //traverse through the neighbours
            for(auto neighbor:adjList[node]){
                int adjNode = neighbor.first;
                int adjTime = neighbor.second;

                if(t > time[node]) continue;

                if(t + adjTime < time[adjNode]){
                    time[adjNode] = t + adjTime;
                    pq.push({time[adjNode],adjNode});
                }
            }
        }

        // returning the max element from the array
        // for(int t:time){
        //     cout<< t<< "  ";
        // }
        int ans = *max_element(time.begin() + 1, time.end());
        return ans == INT_MAX ? -1 : ans;    
    }
};

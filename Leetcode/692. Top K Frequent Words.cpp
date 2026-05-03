using p = pair<int,string>;

class comperator{
    public :
        bool operator()(p &a, p&b){
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for(string word:words){
            m[word]++;
        }
        // min-heap 
        priority_queue<p,vector<p>,comperator> pq;
        for(auto i=m.begin();i!=m.end();i++){
            pq.push({i->second,i->first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<string> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

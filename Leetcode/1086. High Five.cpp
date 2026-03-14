class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> res;
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>> m;
        for(vector<int> item:items){
            m[item[0]].push(item[1]);
            if(m[item[0]].size()>5){
                m[item[0]].pop();
            }
        }
        for(auto i=m.begin();i!=m.end();i++){
            int t=i->first;
            int avg=0;
            while(!i->second.empty()){
                avg+=i->second.top();
                i->second.pop();
            }
            avg/=5;
            res.push_back({i->first,avg});
        }
        sort(res.begin(),res.end());
        return res;
    }
};

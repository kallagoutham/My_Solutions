class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> m1;
        unordered_map<string,int> m2;
        int i=0;
        for(string s1:list1){
            m1[s1]=i;
            i++;
        }
        i=0;
        for(string s2:list2){
            m2[s2]=i;
            i++;
        }
        i=INT_MAX;
        for(auto j=m1.begin();j!=m1.end();j++){
            if(m2.find(j->first)!=m2.end()){
                i=min(i,j->second+m2[j->first]);
            }
        }
        vector<string> res;
        if(i==INT_MAX){
            return res;
        }
        for(auto j=m1.begin();j!=m1.end();j++){
            if(m2.find(j->first)!=m2.end()){
                if((j->second+m2[j->first])==i){
                    res.push_back(j->first);
                }
            }
        }
        return res;
    }
};

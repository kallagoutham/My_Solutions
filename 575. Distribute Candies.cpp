class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int> m;
        for(int i=0;i<candyType.size();i++){
            m[candyType[i]]++;
        }
        return min(m.size(),candyType.size()/2);
    }
};

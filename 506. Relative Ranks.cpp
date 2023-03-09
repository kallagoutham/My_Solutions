class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sortedscores=score;
        vector<string> ranks;
        sort(sortedscores.begin(),sortedscores.end(),greater<int>());
        for(int i=0;i<score.size();i++){
            auto pos=find(sortedscores.begin(),sortedscores.end(),score[i]);
            int idx=pos-sortedscores.begin();
            switch(idx){
                case 0:ranks.push_back("Gold Medal");break;
                case 1:ranks.push_back("Silver Medal");break;
                case 2:ranks.push_back("Bronze Medal");break;
                default:ranks.push_back(to_string(idx+1));
            }
        }
        return ranks;
    }
};

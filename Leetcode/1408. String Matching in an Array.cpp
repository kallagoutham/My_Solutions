class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        for(string word:words){
            for(string check:words){
                if( (word!=check) && check.find(word) != string::npos){
                    res.push_back(word);
                    break;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq(26, 0);
        vector<int> t(26, 0);
        vector<string> res;
        for (string word : words2) {
            t.assign(26, 0);
            for (char i : word) t[i - 'a']++;
            for(int i=0;i<26;++i) freq[i]=max(freq[i],t[i]);
        }
        for(string word:words1){
            t.assign(26,0);
            for(char i:word){
                t[i-'a']++;
            }
            bool isUniversal=true;
            for(int i=0;i<26;++i){
                if(t[i]<freq[i]){
                    isUniversal=false; 
                    break;
                }
            }
            if(isUniversal) res.push_back(word);
        }
        return res;
    }
};

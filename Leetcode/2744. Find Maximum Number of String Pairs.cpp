class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        set<string> wordsSet;
        int pairs=0;
        for(string word:words){
            reverse(word.begin(),word.end());
            if(wordsSet.find(word) != wordsSet.end()){
                pairs++;
            }else{
                reverse(word.begin(),word.end());
                wordsSet.insert(word);
            }
        }
        return pairs;
    }
};

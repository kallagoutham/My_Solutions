// Brute Force 

class Solution {
public:
    bool checkisValidSubstring(string& substring,int noOfWords,int wordSize,unordered_map<string,int> frequencyMap){
        unordered_map<string,int> currentMap=frequencyMap;
        int n=substring.size();
        for(int i=0;i<n;i=i+wordSize){
            string currentWord = substring.substr(i,wordSize);
            if(!currentMap.count(currentWord) || currentMap[currentWord]==0){
                return false;
            }
            currentMap[currentWord]--;
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> frequencyMap;
        for(string& word : words){
            frequencyMap[word]++;
        }
        int n = s.size(), noOfWords = words.size(), wordSize = words[0].size();
        vector<int> res;
        int subStrSize = noOfWords * wordSize;

        for(int i=0;i<n-(noOfWords*wordSize)+1;i++){
            string temp = s.substr(i,subStrSize);
            if(checkisValidSubstring(temp, noOfWords, wordSize,frequencyMap)){
                res.push_back(i);
            }

        }
        return res;
    }
};

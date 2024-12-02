class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int counter=1;
        while(ss>>word){
            auto it=word.find(searchWord);
            if(it!=string::npos && it==0){
                return counter;
            }
            counter++;
        }
        return -1;
    }
};

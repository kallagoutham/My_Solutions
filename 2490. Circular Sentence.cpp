class Solution {
public:
    bool isCircularSentence(string sentence) {
        char firstword = sentence[0];
        stringstream ss(sentence);
        char lastword='0';
        while(ss>>sentence){
            if(lastword=='0'){
                lastword=sentence[sentence.size()-1];
                continue;
            }
            if(lastword != sentence[0]){
                return false;
            }
            lastword = sentence[sentence.size()-1];
        }
        if(lastword==firstword)
            return true;
        return false;
    }
};

class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char,int> m;
        for(char ch:moves){
            m[ch]++;
        }
        if((m['U']==m['D']) && (m['R']==m['L'])){return true;}
        return false;
    }
};

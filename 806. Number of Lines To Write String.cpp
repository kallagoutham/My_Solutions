class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int> res;
        int lines=1,lastRowLength=0;
        for(int i=0;i<s.size();i++){   // for(char c : s)
            if(lastRowLength+widths[s[i]-'a'] <=100){
                lastRowLength+=widths[s[i]-'a']; // can use widths[c-'a'];
            }else{lastRowLength=widths[s[i]-'a'];lines++;}
        }
        res.push_back(lines);
        res.push_back(lastRowLength);
        return res;
    }
};

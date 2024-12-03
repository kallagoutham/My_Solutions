class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        res += s.substr(0, spaces[0]); 
        res += " ";
        for (int i = 1; i <spaces.size(); i++) {
        res += s.substr(spaces[i - 1], spaces[i] - spaces[i - 1]); 
        res += " "; 
    }
    res += s.substr(spaces.back());
    return res;

    }
};

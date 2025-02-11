class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part) != string::npos) {
            int idx = s.find(part);
            s = s.substr(0, idx) + s.substr(idx + part.length());
        }
        return s;
    }
};

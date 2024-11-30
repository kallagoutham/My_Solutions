#include<bits/stdc++.h>
class Solution {
public:
    string toLowerCase(string s) {
        string res;
        for(int i=0;i<s.length();i++){
            res.push_back(tolower(s[i]));
        }
        return res;
    }
};

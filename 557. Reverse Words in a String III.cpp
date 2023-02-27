#include<bits/stdc++.h>
class Solution {
public:
    string reverseWords(string s) {
        string res;
        stringstream ss(s);
        stringstream sss(s);
        int c=0;
        string word;
        while(sss>>word){
            c++;
        }
        while(ss>>word){
            for(int i=word.length()-1;i>=0;i--){
                res.push_back(word[i]);
            }
            if(c!=1){
                res.push_back(' ');
                c--;
            }
        }
        return res;
    }
};

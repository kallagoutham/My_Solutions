#include <sstream>

class Solution {
public:
    string compressedString(string word) {
        int c = 1;
        char ch = word[0];
        std::ostringstream res;
        for (int i = 1; i < word.length(); i++) {
            if (word[i] == ch) {
                c++;
                if (c == 9) {
                    res << c << ch;
                    c = 0; 
                }
            } else {
                if(c>0){
                res << c << ch;}
                c = 1;
                ch = word[i];
            }
        }
        if(c>0){
        res << c << ch;}
        return res.str();
    }
};

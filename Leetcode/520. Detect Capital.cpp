1st Method:
-------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  class Solution {
public:
    bool detectCapitalUse(string word) {
        int num_capitals = 0;
        for(char c : word) {
            if(isupper(c)) {
                num_capitals++;
            }
        }
        return num_capitals == 0 || (num_capitals == 1 && isupper(word.at(0))) || num_capitals == word.size();     
    }
};
  
  
-------------------------------------------------------------------------------------------------------------------------------------------------------------
2nd Method:
--------------------------------------------------------------------------------------------------------------------------------------------------------------
#include<bits/stdc++.h>
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool res;
        int flag=(islower(word[0])?0:1);
        if(flag==0){
        for(int i=1;i<word.length();i++){
            if(isupper(word[i])){
                return false;
            }
        }
        }
        else{
            flag=(islower(word[1])?0:1);
            if(flag==0){
            for(int i=2;i<word.length();i++){
            if(isupper(word[i])){
                return false;
            }
            }
            }
            else{
                for(int i=2;i<word.length();i++){
            if(islower(word[i])){
                return false;
            }
            }
        }
        }
        return true;
    }
};


----------------------------------------------------------------------------------------------------------------------------------------------------

class Solution {
  public:
    string encode(string &s) {
        // code here
        string res = "";
        int freq=0;
        char prevChar='\0';
        for(char c:s){
            if(prevChar == '\0'){
                prevChar = c;
                freq++;
                continue;
            }
            if(prevChar == c){
                freq++;
            }else{
                res += prevChar + to_string(freq);
                prevChar = c;
                freq=1;
            }
        }
        res += prevChar + to_string(freq);
        return res;
    }
};

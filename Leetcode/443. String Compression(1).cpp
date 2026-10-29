class Solution {
public:
    int compress(vector<char>& chars) {
        int freq=1;
        int j=0;
        char prevChar=chars[0];
        for(int i=1;i<chars.size();i++){
            if(chars[i]==prevChar){
                freq++;
            }else{
                chars[j++]=prevChar;
                if (freq > 1) {
                    string count = to_string(freq);
                    for (char c : count) {
                        chars[j++] = c;
                    }
                }
                freq=1;
                prevChar=chars[i];
            }
        }
        chars[j++]=prevChar;
        if(freq>1){
            if (freq > 1) {
                string count = to_string(freq);

                for (char c : count) {
                    chars[j++] = c;
                }
            }       
        }
        return j;
    }
};

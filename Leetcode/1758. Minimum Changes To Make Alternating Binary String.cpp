class Solution {
public:
    int minOperations(string s) {
        const int len = s.size();
        int ops1 = 0;int ops2 = 0;
        for(int i=0;i<len;++i){
            if(i&1){
                ops1+=s[i]!='1';
                ops2+=s[i]!='0';
            }
            else{
                ops1+=s[i]!='0';
                ops2+=s[i]!='1';
            }
        }
        return min(ops1,ops2);
    }
};

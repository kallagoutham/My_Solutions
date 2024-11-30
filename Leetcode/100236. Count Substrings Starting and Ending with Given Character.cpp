class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long cnt=0;
        for(char t:s){
            if(t==c){cnt++;}
        }
        return (cnt*(cnt+1))/2;
    }
};

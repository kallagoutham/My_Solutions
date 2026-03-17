class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char,int> freqMap;
        int i=0,j=0;
        int res = 0;
        int n=s.size();
        while(i<n){
            freqMap[s[i]]++;
            if(freqMap.size()<=2){
                res=max(res,i-j+1);
            }else{
                while(freqMap.size()>2){
                    if(--freqMap[s[j]]==0){
                        freqMap.erase(s[j]);
                    };
                    j++;
                }
            }
            i++;
        }
        return res;
    }
};

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n=s.size();
        int i=0,j=0, res=0;
        unordered_map<char,int> m;
        while(i<n){
            m[s[i]]++;
            if(m.size()<=k){
                res = max(res,i-j+1);
            }
            while(m.size()>k && j<=i){
                if(--m[s[j]] == 0){
                    m.erase(s[j]);
                }
                j++;
            }
            i++;
        }
        return res;
    }
};

class Solution {
public:
    int minimumKeypresses(string s) {
        vector<int> count(26,0);
        for(char c:s){
            count[c-'a']++;
        }
        sort(count.begin(),count.end(),greater<int>());
        int res=0;
        for(int i=0;i<26;i++){
            // cout << count[i] << " ";
            res += (count[i] * (i/9 + 1));
        }
        return res;
    }
};

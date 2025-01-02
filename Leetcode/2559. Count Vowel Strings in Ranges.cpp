class Solution {
public:
    string str = "aeiou";
    bool isVowel(char ch)
    {
        return (str.find(ch) != string::npos);
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> prefix(n+1,0);
        int sum=0;
        prefix[0]=0;
        for(int i=0;i<n;i++){
            if(isVowel(words[i][0]) && isVowel(words[i][words[i].size()-1])){
                sum++;
            }
            prefix[i+1]=sum;
        }
        n=queries.size();
        vector<int> res(queries.size(),0);
        for(int i=0;i<n;i++){
            if(queries[i][0]==0){
                res[i]=prefix[queries[i][1] + 1];
            }else{
                res[i]=prefix[queries[i][1]+1]-prefix[queries[i][0]];
            }
        }
        return res;
    }
};

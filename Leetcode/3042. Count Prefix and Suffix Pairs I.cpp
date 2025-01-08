class Solution {
public:
    bool isPrefixAndSuffix(string& str1,string& str2){
        return str2.find(str1)==0 && str2.find(str1,str2.size()-str1.size())!=string::npos;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isPrefixAndSuffix(words[i],words[j]))    res++;
            }
        }
        return res;
    }
};

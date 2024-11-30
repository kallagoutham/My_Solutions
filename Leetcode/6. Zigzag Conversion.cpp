class Solution {
public:
    string convert(string s, int numRows) {
       if(numRows==1)return s;
        vector<string> vec(numRows,"");
        bool inc = true;
        int i=0,j=0;
        while(i<s.size()){
            inc?vec[j++]+=s[i++]:vec[j--]+=s[i++];
            if(j==0)inc=true;
            if(j==numRows-1)inc=false;
        }
        string ans;
        for(string x : vec)ans+=x;
        return ans;
    }
};

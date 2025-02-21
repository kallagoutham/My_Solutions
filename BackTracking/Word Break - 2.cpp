class Solution {
  public:
    vector<string> res;
    void backtrack(string s,int index,vector<string>& temp,vector<string>& words){
        if(index==s.size()){
            string tt="";
            for(int i=0;i<temp.size();i++){
                tt+=temp[i];
                if(i!=temp.size()-1){
                    tt+=" ";
                }
            }
            res.push_back(tt);
            return;
        }
        string t="";
        for(int i=index;i<s.size();i++){
            t+=s[i];
            if(find(words.begin(),words.end(),t)!=words.end()){
                temp.push_back(t);
                backtrack(s,i+1,temp,words);
                temp.pop_back();
            }
        }
        return;
    }
    vector<string> wordBreak(vector<string>& dict, string s) {
        // code here
        vector<string> temp;
        backtrack(s,0,temp,dict);
        return res;
    }
};

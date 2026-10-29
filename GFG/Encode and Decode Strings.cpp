class Solution {
  public:
    string encode(vector<string>& arr) {
        // write your logic to encode the strings
        string res="";
        for(string str:arr){
            int size = str.size();
            res += to_string(size) +  "/:" + str;
        }
        return res;
    }

    vector<string> decode(string& s) {
        // write your logic to decode the string
        vector<string> res;
        string size="";
        int sz=0;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                size += s[i];
            }else{
                if(s[i]=='/'){
                    i++;
                    sz=stoi(size);
                    res.push_back(s.substr(i+1,sz));
                    size="";
                    i=i+sz;
                }
            }
        }
        return res;
    }
};

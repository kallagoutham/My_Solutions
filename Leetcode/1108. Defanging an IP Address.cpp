class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        for(char ch:address){
            if(ch=='.'){
                res.push_back('[');
                res.push_back(ch);
                res.push_back(']');
            }else{
                res.push_back(ch);
            }
        }
        return res;
    }
};

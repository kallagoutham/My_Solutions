class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res=0;
        for(string i:details){
            if(stoi(i.substr(11,2))>60){
                res++;
            }
        }
        return res;
    }
};

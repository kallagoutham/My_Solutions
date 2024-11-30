class Solution {
public:
    char kthCharacter(int k) {
        string temp="a";
        while(temp.size()<k){
            string t="";
            for(char i:temp){
                char j= (i=='z'?'a':i+1);
                t.push_back(j);
            }
            temp+=t;
        }
        // cout<<temp<<endl;
        return temp[k-1];
    }
};

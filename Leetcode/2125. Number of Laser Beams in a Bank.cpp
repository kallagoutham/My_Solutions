class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int nob = 0;
        int previous=0;
        int c=0;
        for(int i=0;i<bank.size();i++){
            c=0;
            for(int j=0;j<bank[0].size();j++){
                if(bank[i][j]=='1'){
                    c++;
                }
            }
            nob = nob + (previous*c);
            if(c>0){
            previous = c;
            }
        }
        return nob;
    }
};

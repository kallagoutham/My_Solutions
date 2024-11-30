class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        bool flag;
        for(int i=0;i<n;i++){
            if(bits[i]==0){
                flag=true;
            }
            if(bits[i]==1){
                i++;
                flag=false;
            }
        }
        return flag;
    }
};

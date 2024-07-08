class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> b(n,false);
        int ptr=0;
        int c=0;
        int tmp=0;
        while(true){
            if(tmp==n-1){
                break;
            }
            if(!b[ptr]){
                c++;
                if(c==k){
                    b[ptr]=true;
                    tmp++;
                    c=0;
                }
            }
            ptr=(ptr+1)%n;
        }
        for(int i=0;i<n;i++){
            if(!b[i]){
                return i+1;
            }
        }
        return 0;
    }
};

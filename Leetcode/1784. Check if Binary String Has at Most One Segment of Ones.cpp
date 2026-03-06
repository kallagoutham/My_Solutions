class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt=0,segments=0;
        for(char c:s){
            if(c=='1'){
                cnt+=1;
                if(segments>=2){return false;}
            }else{
                if(cnt>0){segments+=1;}
                cnt=0;
            }
        }
        if(cnt>0){segments+=1;}
        return segments==1;
    }
};

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int res=0;
        sort(tokens.begin(),tokens.end());
        while((power>0 || res>0) && tokens.size()>0){
            if(tokens[0]<=power){
                res++;
                power-=tokens[0];
                tokens.erase(tokens.begin());
                continue;
            }
            if((tokens[tokens.size()-1]+power >= tokens[0])&& (tokens.size()>1) && (res>=1) ){
                res--;
                power+=tokens[tokens.size()-1];
                auto it=tokens.end();
                it--;
                tokens.erase(it);
                continue;
            }
            break;
        }
        return res;
    }
};

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> frequency;
        int mx= INT_MIN;
        for(int num:deck){
            frequency[num]++;
            mx=max(mx,frequency[num]);
        }
        bool same=false;
        int t=2;
        while(t<=mx){
        same = true;   
        for(auto i=frequency.begin();i!=frequency.end();i++){
                if(i->second==1){return false;}
                if(i->second%t!=0){same=false;break;}
            }
            if(same == true){return true;}
            t++;
        }
        return false;
    }
};

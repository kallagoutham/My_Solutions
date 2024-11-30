class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> m;
        for(int i:bills){
            if(i==5){
                m[i]++;
            }
            if(i==10){
                if(m[5]>=1){
                    m[i]++;
                    m[5]--;
                    continue;
                }
                return false;
            }
            if(i==20){
                if((m[5]>=1 && m[10]>=1)||(m[5]>=3)){
                    if(m[10]==0){
                        m[5]-=3;
                    }else{
                        m[5]--;
                        m[10]--;
                    }
                    continue;
                }
                return false;
            }
        }
        return true;
    }
};

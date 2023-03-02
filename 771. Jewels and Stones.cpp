class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,int> jew;
        for(int i=0;i<jewels.length();i++){
            jew[jewels[i]]++;
        }
        int c=0;
        for(int i=0;i<stones.length();i++){
            if(jew.find(stones[i])!=jew.end()){
                c++;
            }
        }
        return c;
    }
};

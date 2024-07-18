class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> res(2,0);
        int d=INT_MAX;
        for(int i=area;i>=1;i--){
            if(area%i==0){
                if(d>(abs(i-area/i))){
                    res[0]=max(i,area/i);
                    res[1]=min(i,area/i);
                    d=abs(i-area/i);
                }
            }
        }
        return res;
    }
};

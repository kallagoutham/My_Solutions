class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
        if(a[1]==b[1]){
            return a[0]>b[0];
        }
        return a[1]<b[1];
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int Last=-1,secondLast=-1,ans=0;
        for(auto i:intervals){
            if(i[0]<=secondLast){
                //all two are included in the interval so no problem.
                //nothing to do
                continue;
            }else if(i[0]>secondLast && i[0]<=Last){
                //one included need another one 
                secondLast=Last;
                Last=i[1];
                ans++;
            }else{
                //no one is included two numbers have to be included
                ans+=2;
                Last=i[1];
                secondLast=i[1]-1;
            }
        }
        return ans;
    }
};

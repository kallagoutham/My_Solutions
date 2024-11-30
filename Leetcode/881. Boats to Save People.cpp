class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int l=0;
        int r=people.size()-1;
        int res=0;
        while(l<=r){
            int left=limit-people[r];
            r-=1;
            res+=1;
            if(l<=r && left>=people[l]){
                //left-=people[l];  //changing the if condition to while loop makes the question variation accepting not only atmost two people for boat
                l+=1;
            }
        }
        return res;
    }
};

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long sum=0;
        priority_queue<int> pq;
        if(nums.size()<3){return -1;}
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            pq.push(nums[i]);
        }
        while(sum>0){
        if(pq.top()<sum-pq.top()){
            return sum;
        }
        else{
            sum-=pq.top();
            pq.pop();
        }
        }
        return -1;
    }
};

class Solution {
public:
    int getDigitSum(int n){
        int res=0;
        while(n>0){
            res+=n%10;
            n/=10;
        }
        return res;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,priority_queue<int>> m;
        for(int i:nums){
            m[getDigitSum(i)].push(i);
        }
        int res=-1;
        for(auto i:m){
            if(i.second.size()>=2){
                int p=i.second.top();
                // cout<<p<<"    ";
                i.second.pop();
                // cout<<i.second.top()<<"   "<<endl;
                p+=i.second.top();
                res=max(res,p);
            }
        }
        return res;
    }
};

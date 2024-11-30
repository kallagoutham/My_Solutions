class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int p=(n*5)/100;
        double sum=0;
        for(int i=p;i<n-p;i++){
            sum+=static_cast<double>(arr[i]);
        }
        return sum/(n-(2*p));
    }
};

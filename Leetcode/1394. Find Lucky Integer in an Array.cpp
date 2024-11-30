/* In the constraints mentioned in the problem the i<=arr[i]<=500 and 1<=arr.length()<=500 as it was short using count array helps */
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int countArray[501]={0};
        for(int i=0;i<arr.size();i++){
            countArray[arr[i]]++;
        }
        for(int i=500;i>0;i--){
            if(countArray[i]==i){return i;}
        }
        return -1;
    }
};
/* If the array is of big size and the element range is also big then using map is the approach */
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]]++;
        }
        int ans=-1;
        for(auto it:m)
        {
            if(it.first==it.second)
            {
                ans=max(ans,it.first);
                
            }
        }
        return ans;

    }
};

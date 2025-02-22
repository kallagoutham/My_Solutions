class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        int l = 0, h = n - 1;
        
        while (l < h) {
            if (a[l] < a[h]) return a[l]; 
            int mid = l + (h - l) / 2;
            if (mid > 0 && a[mid] < a[mid - 1]) {
                return a[mid];  
            }
            if (a[mid] >= a[l]) {
                l = mid + 1;
            } else {
                h = mid;
            }
        }
        return a[l];  
    }
};

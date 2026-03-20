class Solution {
public:
    long long check(vector<int>& piles, int rate) {
        long long hours = 0;
        for (int pile : piles) {
            hours += (pile + rate - 1LL) / rate;  
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int res = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long hours = check(piles, mid);

            if (hours <= h) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res;
    }
};

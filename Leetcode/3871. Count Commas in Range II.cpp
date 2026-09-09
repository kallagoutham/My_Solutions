class Solution {
public:
    long long countCommas(long long n) {
        long long res = 0;
        for (long long i = 1000; i <= n; i *= 1000)
            res += n - i + 1;

        return res;
    }
};

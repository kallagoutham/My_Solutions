class Solution {
public:
    long long coloredCells(int n) {
        return 2LL * static_cast<long long>(n) * n - 2LL * n + 1LL;
    }
};

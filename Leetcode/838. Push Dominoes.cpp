class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> prefix_right(n, 0);
        vector<int> prefix_left(n, 0);
        
        // Initialize first and last positions
        prefix_right[0] = dominoes[0] == 'L' ? -1 : (dominoes[0] == 'R' ? 1 : 0);
        prefix_left[n - 1] = dominoes[n - 1] == 'L' ? -1 : (dominoes[n - 1] == 'R' ? 1 : 0);

        // Rightward force
        for (int i = 1; i < n; ++i) {
            if (dominoes[i] == 'L') {
                prefix_right[i] = -1;
            } else if (dominoes[i] == 'R') {
                prefix_right[i] = 1;
            } else {
                if (prefix_right[i - 1] > 0)
                    prefix_right[i] = prefix_right[i - 1] + 1;
            }
        }

        // Leftward force
        for (int i = n - 2; i >= 0; --i) {
            if (dominoes[i] == 'R') {
                prefix_left[i] = 1;
            } else if (dominoes[i] == 'L') {
                prefix_left[i] = -1;
            } else {
                if (prefix_left[i + 1] < 0)
                    prefix_left[i] = prefix_left[i + 1] - 1;
            }
        }

        // Build result
        string res;
        for (int i = 0; i < n; ++i) {
            if (prefix_right[i] == 0 && prefix_left[i] == 0) {
                res += '.';
            } else if (prefix_right[i] == -1 && prefix_left[i] == -1) {
                res += 'L';
            } else if (prefix_right[i] == 1 && prefix_left[i] == 1) {
                res += 'R';
            } else if (prefix_right[i] == 0) {
                res += 'L';
            } else if (prefix_left[i] == 0) {
                res += 'R';
            } else {
                if (abs(prefix_right[i]) < abs(prefix_left[i])) {
                    res += 'R';
                } else if (abs(prefix_right[i]) > abs(prefix_left[i])) {
                    res += 'L';
                } else {
                    res += '.';
                }
            }
        }

        return res;
    }
};

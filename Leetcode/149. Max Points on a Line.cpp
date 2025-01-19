class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int i = 0, j, n, count = 0, x1, x2, y1, y2;
        n = points.size();
        if (n == 1) {
            return 1;
        }
        for (i = 0; i < n; i++) {
            unordered_map<float, int> hash;
            x1 = points[i][0];
            y1 = points[i][1];
            for (j = n - 1; j > i; j--) {
                x2 = points[j][0];
                y2 = points[j][1];
                if (x2 - x1 == 0) {
                    hash[FLT_MAX]++;
                } else if (y2 - y1 == 0) {
                    hash[0]++;
                } else {
                    float slope = (float)(y2 - y1) / (x2 - x1);
                    hash[slope]++;
                }
            }
            for (auto& entry : hash) {
                count = max(count, entry.second);
            }
        }
        return count + 1;
    }
};class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int i = 0, j, n, count = 0, x1, x2, y1, y2;
        n = points.size();
        if (n == 1) {
            return 1;
        }
        for (i = 0; i < n; i++) {
            unordered_map<float, int> hash;
            x1 = points[i][0];
            y1 = points[i][1];
            for (j = n - 1; j > i; j--) {
                x2 = points[j][0];
                y2 = points[j][1];
                if (x2 - x1 == 0) {
                    hash[FLT_MAX]++;
                } else if (y2 - y1 == 0) {
                    hash[0]++;
                } else {
                    float slope = (float)(y2 - y1) / (x2 - x1);
                    hash[slope]++;
                }
            }
            for (auto& entry : hash) {
                count = max(count, entry.second);
            }
        }
        return count + 1;
    }
};

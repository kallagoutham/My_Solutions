class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        bool first = true;
        int c = 0, res = 0;

        for (int x : flowerbed) {
            if (x == 1) {
                if (c > 0) {
                    if (first) {
                        res += c / 2;            
                    } else {
                        res += (c - 1) / 2;        
                    }
                }
                c = 0;
                first = false;
            } else {
                c++;
            }
        }

        if (c > 0) {
            if (first) {
                res += (c + 1) / 2;
            } else {
                res += c / 2;
            }
        }

        return res >= n;
    }
};

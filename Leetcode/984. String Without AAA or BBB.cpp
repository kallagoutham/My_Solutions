class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string result;
        while (a > 0 || b > 0) {
            if (result.size() >= 2 && result.back() == result[result.size() - 2]) {
                if (result.back() == 'a') {
                    result += 'b';
                    b--;
                } else {
                    result += 'a';
                    a--;
                }
            } else {
                if (a >= b) {
                    result += 'a';
                    a--;
                } else {
                    result += 'b';
                    b--;
                }
            }
        }
        return result;
    }
};

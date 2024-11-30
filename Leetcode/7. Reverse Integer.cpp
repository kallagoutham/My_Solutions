class Solution {
public:
    int reverse(int x) {
        long r = 0;
        while (x != 0) {
            int d = x % 10;  
            r = r * 10 + d;  
            x /= 10;         
            if (r > INT_MAX || r < INT_MIN) {
                return 0;  
            }
        }
        return (int)r; 
    }
};

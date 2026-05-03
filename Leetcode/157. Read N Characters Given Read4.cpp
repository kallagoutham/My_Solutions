/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int total = 0;
        char buf4[4];

        int count = read4(buf4);
        while (count != 0) {
            for (int i = 0; i < count && total < n; i++) {
                buf[total++] = buf4[i];
            }
            count = read4(buf4);
        }
        return total;
    }
};

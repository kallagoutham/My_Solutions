class Solution {
public:
    vector<int> constructRectangle(int area) {
        int width = static_cast<int>(sqrt(area));
        while (area % width != 0) {
            width--;
        }
        int length = area / width;
        return {length, width};
    }
};

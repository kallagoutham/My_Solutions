class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size();
        int x=points[0][0], y=points[0][1], res=0;
        for(int i=1;i<n;i++){
            res += max(abs(points[i][0]-x),abs(points[i][1]-y));
            x=points[i][0];
            y=points[i][1];
        }
        return res;
    }
};

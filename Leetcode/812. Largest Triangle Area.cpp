class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double res=0;
        for(int i=0;i<points.size()-2;i++){
            for(int j=0;j<points.size()-1;j++){
                for(int k=0;k<points.size();k++){
                    double t =static_cast<double>(abs(points[i][0]*(points[j][1]-points[k][1])+points[j][0]*(points[k][1]-points[i][1])+points[k][0]*(points[i][1]-points[j][1])));
                    res=max(res,t);
                }
            }
        }
        return res/2;
    }
};

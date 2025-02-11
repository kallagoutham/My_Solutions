class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;
        
        vector<pair<int, double>> v;  
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];  
            v.push_back({position[i], time});
        }
        
        sort(v.rbegin(), v.rend());  

        int res = 0;
        double prevTime = 0;
        for (auto& car : v) {
            double currentTime = car.second;
            if (currentTime > prevTime) {  
                res++;  
                prevTime = currentTime;  
            }
        }
        
        return res;
    }
};

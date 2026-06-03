class Solution {
public:
    struct RideHelper {
        vector<int> start;
        vector<int> prefixMinDuration;
        vector<int> suffixMinFinish;

        RideHelper(vector<int>& starts, vector<int>& durations) {
            int n = starts.size();

            vector<pair<int, int>> rides;
            for (int i = 0; i < n; i++) {
                rides.push_back({starts[i], durations[i]});
            }

            sort(rides.begin(), rides.end());

            start.resize(n);
            prefixMinDuration.resize(n);
            suffixMinFinish.resize(n);

            for (int i = 0; i < n; i++) {
                start[i] = rides[i].first;
            }

            prefixMinDuration[0] = rides[0].second;
            for (int i = 1; i < n; i++) {
                prefixMinDuration[i] = min(prefixMinDuration[i - 1], rides[i].second);
            }

            suffixMinFinish[n - 1] = rides[n - 1].first + rides[n - 1].second;
            for (int i = n - 2; i >= 0; i--) {
                suffixMinFinish[i] = min(
                    suffixMinFinish[i + 1],
                    rides[i].first + rides[i].second
                );
            }
        }

        int bestFinishAfter(int currentTime) {
            int n = start.size();
            int ans = INT_MAX;

            // Rides with start <= currentTime
            int idx = upper_bound(start.begin(), start.end(), currentTime) - start.begin() - 1;
            if (idx >= 0) {
                ans = min(ans, currentTime + prefixMinDuration[idx]);
            }

            // Rides with start > currentTime
            int nextIdx = upper_bound(start.begin(), start.end(), currentTime) - start.begin();
            if (nextIdx < n) {
                ans = min(ans, suffixMinFinish[nextIdx]);
            }

            return ans;
        }
    };

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        RideHelper landHelper(landStartTime, landDuration);
        RideHelper waterHelper(waterStartTime, waterDuration);

        int res = INT_MAX;

        // Land first, then best water ride
        for (int i = 0; i < n; i++) {
            int landFinish = landStartTime[i] + landDuration[i];
            res = min(res, waterHelper.bestFinishAfter(landFinish));
        }

        // Water first, then best land ride
        for (int j = 0; j < m; j++) {
            int waterFinish = waterStartTime[j] + waterDuration[j];
            res = min(res, landHelper.bestFinishAfter(waterFinish));
        }

        return res;
    }
};

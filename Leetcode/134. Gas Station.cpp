class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start=0,curGas=0,totalGas=0,totalCost=0;
        for(int i=0;i<n;i++){
            totalGas += gas[i];
            totalCost += cost[i];
            curGas += (gas[i]-cost[i]);
            if(curGas < 0){
                start = i+1;
                curGas=0;
            }
        }
        return totalGas<totalCost ? -1 : start;
    }
};

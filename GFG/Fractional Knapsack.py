#User function Template for python3
class Solution:
    # Function to get the maximum total value in the knapsack.
    def fractionalknapsack(self, val, wt, capacity):
        profit=list(zip(val,wt))
        profit.sort(key = lambda x:x[0]/x[1],reverse=True)
        # print(profit)
        totalVal=0
        for i in profit:
            if i[1]<=capacity:
                totalVal+=i[0]
                capacity-=i[1]
            else:
                totalVal += (i[0]/i[1])*capacity
                break
        return totalVal

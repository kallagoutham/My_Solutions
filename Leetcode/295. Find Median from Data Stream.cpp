class MedianFinder {
public:
    priority_queue<int> maxHeap; 
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {
    }
    
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } 
        else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int a = maxHeap.top(); maxHeap.pop();
            int b = minHeap.top(); minHeap.pop();
            maxHeap.push(b);
            minHeap.push(a);
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } 
        else if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } 
        else {
            return minHeap.top();
        }
    }
};

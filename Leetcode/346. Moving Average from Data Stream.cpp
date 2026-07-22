class MovingAverage {
private:
    queue<int> qu;
    int avergeSize;
    double sum;
public:
    MovingAverage(int size):avergeSize(size),sum(0) {}
    
    double next(int val) {
        sum += val;
        qu.push(val);
        int queueSize = (int)qu.size();
        if(queueSize <= avergeSize){
            return sum / queueSize;
        }
        else{
            sum -= qu.front();
            qu.pop();
            return sum / avergeSize;
        }
    }
};
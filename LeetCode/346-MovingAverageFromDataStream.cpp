class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sum = 0;
        this->size = size;
    }
    
    double next(int val) {
        if (q.size() >= size) {
            sum -= q.front();
            q.pop();
        }
        
        q.push(val);
        sum += val;
        return sum / q.size();
    }
private:
    queue<int> q;
    double sum;
    int size;
};

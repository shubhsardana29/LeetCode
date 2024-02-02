class MedianFinder {
public:
    MedianFinder() {
        
    }

    void solveForAddNum(double &median, priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int>> &mini, int element) {
        if (maxi.size() == mini.size()) {
            if (element > median) {
                mini.push(element);
                median = mini.top();
            } else {
                maxi.push(element);
                median = maxi.top();
            }
        } else if (maxi.size() == mini.size() + 1) {
            if (element > median) {
                mini.push(element);
            } else {
                int maxTop = maxi.top();
                maxi.pop();
                mini.push(maxTop);
                maxi.push(element);
            }
            median =( maxi.top() + mini.top() )/ 2.0;
        } else if (mini.size() == maxi.size() + 1) {
            if (element > median) {
                int minTop = mini.top();
                mini.pop();
                maxi.push(minTop);
                mini.push(element);
                
            } else {
                maxi.push(element);
            }
            median = ( maxi.top() + mini.top() ) / 2.0;
        }
    }

    void addNum(int num) {
        int element = num;
        solveForAddNum(median, maxi, mini, element);
    }

    double findMedian() {
        return median;
    }

private:
    double median;
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
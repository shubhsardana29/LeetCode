class MedianFinder {
public:
    MedianFinder() {
        
    }

    void solveForAddNum(double &median, priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int>> &mini, int element) {
        if (maxi.size() == mini.size()) {
            if (element > median) {
                mini.push(element);
                median = static_cast<double>(mini.top());
            } else {
                maxi.push(element);
                median = static_cast<double>(maxi.top());
            }
        } else if (maxi.size() == mini.size() + 1) {
            if (element > median) {
                mini.push(element);
            } else {
                maxi.push(element);
                mini.push(maxi.top());
                maxi.pop();
            }
            median = (static_cast<double>(maxi.top()) + static_cast<double>(mini.top())) / 2.0;
        } else if (mini.size() == maxi.size() + 1) {
            if (element < median) {
                maxi.push(element);
            } else {
                mini.push(element);
                maxi.push(mini.top());
                mini.pop();
            }
            median = (static_cast<double>(maxi.top()) + static_cast<double>(mini.top())) / 2.0;
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
    priority_queue<int, std::vector<int>, std::greater<int>> mini;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
int signum(int a, int b) {
    if (a == b) 
        return 0;
    if (a > b) 
        return 1;
    return -1;
}

void callMedian(double& median, priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap, int element) {

    switch (signum(minHeap.size(), maxHeap.size())) {
        case 0: 
            if (element > median) {
                minHeap.push(element);
                median = minHeap.top();
            } else {
                maxHeap.push(element);
                median = maxHeap.top();
            }
            break;

        case 1: 
            if (element > median) {
                int minTop = minHeap.top();
                minHeap.pop();
                maxHeap.push(minTop);
                minHeap.push(element);
                median = (minHeap.top() + maxHeap.top()) / 2.0;
            } else {
                maxHeap.push(element);
                median = (minHeap.top() + maxHeap.top()) / 2.0;
            }
            break;

        case -1:
            if (element > median) {
                minHeap.push(element);
                median = (minHeap.top() + maxHeap.top()) / 2.0;
            } else {
                int maxTop = maxHeap.top();
                maxHeap.pop();
                minHeap.push(maxTop);
                maxHeap.push(element);
                median = (minHeap.top() + maxHeap.top()) / 2.0;
            }
            break;
    }
}

class MedianFinder {
public:
    priority_queue<int> maxHeap;  // Max-heap for the lower half
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Min-heap for the upper half
    double median = 0;  // To store the current median
    // median = 0;  // Initialize median
    
    MedianFinder() {
    
    }
    
    void addNum(int num) {
        callMedian(median, maxHeap, minHeap, num);  // Use callMedian function for logic
    }
    
    double findMedian() {
        return median;  // Return the current median
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
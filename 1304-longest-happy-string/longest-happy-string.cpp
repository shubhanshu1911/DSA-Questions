class Node{
public :
    char data;
    int freq;

    Node(char c, int f){
        data = c;
        freq = f;
    }
};

class compare{
public :
    bool operator () (Node a, Node b){
        // max heap
        return a.freq < b.freq;
    }
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // maxheap 
        priority_queue<Node, vector<Node>, compare > maxHeap;

        if(a>0){
            Node temp('a', a);
            maxHeap.push(temp);
        }

        if(b>0){
            Node temp('b', b);
            maxHeap.push(temp);
        }

        if(c>0){
            Node temp('c', c);
            maxHeap.push(temp);
        }
        
        string ans = "";
        while(maxHeap.size() > 1){
            Node first = maxHeap.top();
            maxHeap.pop();
            Node second = maxHeap.top();
            maxHeap.pop();

            if(first.freq >=2){
                ans += first.data;
                ans += first.data;
                first.freq -= 2;
            }
            else {
                // 1 hi baar h 
                ans += first.data;
                first.freq --;
            }

            if(second.freq >=2 && second.freq >= first.freq){
                ans += second.data;
                ans += second.data;
                second.freq -= 2;
            }
            else {
                // 1 hi baar h 
                ans += second.data;
                second.freq --;
            }

            // freq aabi bi 0 nhi hui to vaps push 
            if(first.freq > 0){
                maxHeap.push(first);
            }
            if(second.freq > 0){
                maxHeap.push(second);
            }
        }

        // 1 element bacha hoga 
        if(maxHeap.size() == 1){
            Node temp = maxHeap.top();
            maxHeap.pop();

            if(temp.freq >=2){
                ans += temp.data;
                ans += temp.data;
                temp.freq -= 2;
            }
            else {
                // 1 hi baar h 
                ans += temp.data;
                temp.freq --;
            }
        }

        return ans;
    }
};
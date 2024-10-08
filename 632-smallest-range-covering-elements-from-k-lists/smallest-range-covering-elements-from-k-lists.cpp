class Node{
public : 
    int data;
    int row;
    int col;

    Node(int d, int r, int c){
        data = d;
        row = r; 
        col = c;
    }
};
class compare{
public : 
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node*, vector<Node*>, compare > minHeap;
        int k = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;

        // first k element ko heap me push krro 
        for(int i=0; i<k; i++){
            int element = nums[i][0];
            maxi = max(maxi, element);
            mini = min(mini, element);
            minHeap.push(new Node(element, i, 0));
        }

        int ansStart = mini;
        int ansEnd = maxi;

        while(!minHeap.empty()){
            Node* topElement = minHeap.top();
            int topData = topElement -> data;
            int topRow = topElement -> row;
            int topCol = topElement -> col;
            minHeap.pop();

            // mini update 
            mini = topData;

            // check for answer
            int currRange = maxi - mini;
            int ansRange = ansEnd - ansStart;
            if(currRange < ansRange){
                ansStart = mini;
                ansEnd = maxi;
            }

            // Check for new element in the list 
            if(topCol + 1 < nums[topRow].size()){
                maxi = max(maxi, nums[topRow][topCol+1]);
                Node* newNode = new Node(nums[topRow][topCol+1], topRow, topCol+1);
                minHeap.push(newNode);
            }else{
                // there is no element in the same array
                break;
            }
        }

        vector<int> ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};
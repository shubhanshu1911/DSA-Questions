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
    string reorganizeString(string s) {
        // This array containing only smallcase letters
        int hash[26] = {0};

        // mapping all the elements in string s 
        for(int i=0; i<s.size(); i++){
            hash[s[i] - 'a']++;
        }

        // maxheap 
        priority_queue<Node, vector<Node>, compare > maxHeap;

        for(int i=0; i<26; i++){
            if(hash[i] != 0){
                Node temp(i+'a', hash[i]);
                // Node temp = new Node(i+'a', hash[i]);
                maxHeap.push(temp);
            }
        }

        string ans = "";

        while(maxHeap.size() > 1){  // haar point me heap me atleast 2 element hone chahhiye
            Node first = maxHeap.top();
            maxHeap.pop();
            Node second = maxHeap.top();
            maxHeap.pop();

            ans += first.data;
            ans += second.data;

            first.freq--;
            second.freq--;

            if(first.freq != 0){
                maxHeap.push(first);
            }

            if(second.freq != 0){
                maxHeap.push(second);
            }
        }

        // 1 element bacha hoga 
        if(maxHeap.size() == 1){
            Node temp = maxHeap.top();
            maxHeap.pop();
            if(temp.freq == 1){
                ans+= temp.data;
            }
            else {
                return "";
            }
        }

        return ans;
        
    }
};
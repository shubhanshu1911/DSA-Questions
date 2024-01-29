class Solution {
public:

void mergeInPlace(vector<int>& arr, int s, int e){
    int totalSize = e - s + 1;
    // formula for finding ceil 
    int gap = (totalSize / 2) + (totalSize % 2);

    while(gap > 0){
        int i =s, j = s+gap;
        while(j <= e){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
            i++, j++;
        }
        gap = (gap <=1) ? 0 : (gap / 2)+(gap % 2);
    }
}

void mergeSort(vector<int>& arr, int s, int e){
    //! Base Case : Single element / invalid array
    if(s>=e){
        return;
    }
    int mid = s + (e-s)/2;
    //TODO 1 : left part ko sort krdo
    mergeSort(arr, s,mid); 

    // TODO 2 : Right Part ko sort krod 
    mergeSort(arr, mid+1, e);

    // TODO 3 : merge 2 sorted arrays 
    mergeInPlace(arr, s, e);
}

vector<int> sortArray(vector<int>& nums) {
    int n = nums.size();
    int s =0;
    int e =n-1;
    mergeSort(nums, s,e);  
    return nums;
    }
};
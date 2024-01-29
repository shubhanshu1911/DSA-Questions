class Solution {
public:

void merge(vector<int>& arr, vector<int>& temp, int s, int e, int mid){
    int i = s, j =mid+1, k=s;
    
    //  Sorting left part and right into temp vector
    while(i<=mid && j<=e){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];     
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    
    // Copy the remaining array into the temp 
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=e){
        temp[k++] = arr[j++];
    }
    
    // Copy the temp array into the main array
    while(s<=e){
        arr[s] = temp[s];
        ++s;
    }
}

void mergeSort(vector<int>& arr,vector<int>& temp, int s, int e){
    //! Base Case : Single element / invalid array
    if(s>=e){
        return;
    }
    int mid = s + (e-s)/2;
    //TODO 1 : left part ko sort krdo
    mergeSort(arr,temp, s,mid); 

    // TODO 2 : Right Part ko sort krod 
    mergeSort(arr,temp, mid+1, e);

    // TODO 3 : merge 2 sorted arrays 
    merge(arr, temp, s, e, mid);
}

vector<int> sortArray(vector<int>& nums) {
    int n = nums.size();
    int s =0;
    int e =n-1;
    vector<int> temp(n,0);
    mergeSort(nums, temp, s,e);  
    return nums;
    }
};
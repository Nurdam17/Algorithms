#include<bits/stdc++.h>
using namespace std;
int binarysearch(vector<int> vec, int low, int high, int target){
    // Recursive Binary Search function to find the index of an 
    // element 'x' in a sorted array 'arr' if elements is 
    // present, otherwise it return -1 
    while(low<=high){
        int middle=low+(high-low)/2; //calculate middle index
        if(vec[middle]==target){
            return middle; //If the middle element equals to target number, we return its index
        }
        else if(vec[middle]>target){
            return binarysearch(vec, low, middle-1, target); // If the middle element is greater than target number,
                                                             // we search element in the left half of the array
        }
        else{
            return binarysearch(vec, middle+1, high, target); // If the middle element is lower than target number,
                                                              // we search element in the right half of the array
        }
        return -1; // if target is not present in the array, we return -1
    }
}
int main(){
    //size of array
    int n; cin>>n;

    //creating vector/array
    vector<int> vec;
    for(int i=0;i<n;i++){
        int element; cin>>element;
        vec.push_back(element);
    }

    //element to be searched
    int target; cin>>target;

    //function searching position of target element
    cout<<binarysearch(vec, 0, n-1, target);
    return 0;
}
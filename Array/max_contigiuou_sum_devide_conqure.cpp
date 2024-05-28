// A Divide and Conquer based program for maximum subarray
// sum problem
#include <limits.h>
#include <stdio.h>
  
int max(int a, int b) { return (a > b) ? a : b; }
  

int max(int a, int b, int c) { return max(max(a, b), c); }


int crossing_sum(int arr[], int l, int m, int, r){
    int left_sum = INT_MIN;
    int sum = 0;
    for(int i=m; i>=l; i--){
        sum += arr[i];
        if(sum>left_sum) left_sum = sum
    }
    sum = 0;
    int r_sum = INT_MIN;
    for(int i=m; i<=r; i++){
        sum += arr[i];
        if(r_sum>sum) r_sum = sum;
    }

    return(left_sum + r_sum - arr[m], left_sum, r_sum)
}

int max_sub_arraySum(int arr[], int l, int r){
    if(l>r) return INT_MIN;
    if(l==r){
        return arr[l];
    }
    int mid = (l+r) / 2;

    return max(max_sub_arraySum(arr, l, mid), max_sub_arraySum(arr, mid, r), crossing_sum(arr, l, m, r))
}


int main(){
    int arr[] = {}
    int n = arr.size()/sizeof(arr[0]);
    int result = max_sub_arraySum(arr, 0, n-1);
}
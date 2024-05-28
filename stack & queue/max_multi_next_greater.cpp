//  Maximum product of indexes of next greater on left and right

int leftProduct(int arr[], int n){
    int l = 0, r = n-1;
    vector<int> ans;

    stack<int> st;
    for(int i=n-1; i>=0; i--){

        while(!st.empty() && a[i]>a[st.top()-1]){
            int r = st.top()-1;
            st.pop();
            ans[r] = i+1;
        }
        st.push(i+1);
    }
    return ans;





}
int rightProduct(int arr[], int n){


}


int LRProduct(int arr[], int n){
    vector<int> left = leftProduct(arr, n);
    vector<int> right = rightProduct(arr, n);
    int ans = -1;
    for(int i=0; i<n; i++){
        ans = max((left[i] * right[i]), ans);
    }
    return ans;

}




int main(){
    int arr[] = { 5, 4, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[1]);
 
    cout << LRProduct(arr, n);
 
    return 0;
}
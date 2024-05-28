//

void rotate(vector<int>& nums, int k) {
	for(int i=0; i<k; i++){
		int last = nums[nums.size()-1];
		for(int j=nums.size()-1; j>0; j--){
			nums[j]=nums[j-1];
		}
		nums[0]=last;
	}
}


//using stl

void rotate(vector<int>& nums, int k) {
	int n=nums.size();
	k = k % n;
	reverse(nums.begin(), nums.end()-k);
	reverse(nums.end()-k, nums.begin()+n);
	reverse(nums.begin(),nums.end());
}
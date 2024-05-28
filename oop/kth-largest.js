var KthLargest = function(k, nums) {
	this.k = k;
	if(nums.length===0) this.root = null;
	else {
		this.root = new TreeNode(nums[0]), len = nums.length;
		this.root.count=1;
		for(let i=1; i<len; i++){
			this.root = insertAndUpdateCount(this.root, nums[i]);
		}
	}
};

KthLargest.prototype.add = function(val) {
	this.root = insertAndUpdateCount(this.root, val);
	let curNode = this.root, k = this.k, curNodeRank = 0;
	while(true){
		if(!curNode.right) curNodeRank = 1;
		else curNodeRank = curNode.right.count+1;
		if(curNodeRank===k) return curNode.val;
		else if(curNodeRank>k){
			curNode = curNode.right;
		}
		else{
			k = k - curNodeRank;
			curNode = curNode.left;
		}
	}
};

 function insertAndUpdateCount(root, val){
 	if(root===null){
 		let newRoot = new TreeNode(val);
 		newRoot.count = 1;
 		return newRoot;
 	}
 	let curNode = root;
 	while(true){
		curNode.count++;
		if(val<=curNode.val && curNode.left===null){
			curNode.left = new TreeNode(val);
			curNode.left.count=1;
			break;
		}
		else if(val>=curNode.val && curNode.right===null){
			curNode.right = new TreeNode(val);
			curNode.right.count = 1;
			break;
		}
		else {
			if(val<=curNode.val) curNode = curNode.left;
			else curNode = curNode.right;
		}
	}
	return root;
 }
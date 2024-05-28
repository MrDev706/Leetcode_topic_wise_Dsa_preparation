//sliding window maximum


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        int max=INT_MIN;
        for(int i=0;i<k;i++){
            pq.push(make_pair(nums[i],i));
        }
        ans.push_back(pq.top().first);
        for(int i=k;i<n;i++) {
            pq.push(make_pair(nums[i],i));
            while(pq.top().second<i-k+1){
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};

/////Deque approach

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     deque<int>dq;
     vector<int>ans;
     for(int i=0;i<nums.size();i++)
     {
         if(!dq.empty()&& dq.front()==(i-k))
         {
             dq.pop_front();
         }
         while(!dq.empty() && nums[i]>nums[dq.back()])
         {
             dq.pop_back();
         }
         dq.push_back(i);
         if(i>=k-1)
         {
             ans.push_back(nums[dq.front()]);
         }
     }
   return ans;        
    }
};
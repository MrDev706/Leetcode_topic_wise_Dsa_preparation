class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int st = 0;
        int sum = 0;
        int res = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            while(sum>=target){
                res = min(res, i-st+1);
                sum -= nums[st];
                st++;
            }
        }
        return res==INT_MAX?0:res;
        
    }
};

//HARD

typedef long long ll;
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>> > pq;
        ll sum = 0;
        ll ans = 1e18;
        for( ll i = 0; i<A.size(); i++){
            sum += (ll)A[i];
            if( sum >= K ){
                ans = min(ans, i+1);
            }
            while( pq.size() && sum - pq.top().first >= K ){
                auto &p = pq.top();
                ans = min(ans, i-p.second);
                pq.pop();
            }
            pq.push({sum, i});
        }
        return ans == 1e18?-1:ans;
    }
};
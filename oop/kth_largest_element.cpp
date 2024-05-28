//LEETCODE: https://leetcode.com/problems/kth-largest-element-in-a-stream/solutions/135995/javascript-solution-runtime-264ms/

class KthLargest {
    set<pair<int,int>> st;
    int index;
    int n;
public:
    KthLargest(int k, vector<int> nums) {
        n = k;
        for(int i=0;i<nums.size();i++)
        {
            st.insert({nums[i],index++});
                if(st.size()==(k+1)) {
                    st.erase(st.begin());
                }
        }
    }
    
    int add(int val) {
        st.insert({val,index++});
        if(st.size()==(n+1)) // very important check this condition.
        st.erase(st.begin()); 
        int ans = (*st.begin()).first;
        
        for (auto it=st.begin(); it != st.end(); ++it){
            cout << ' ' << (*it).first;
        }
            
    
           
        return ans;
    }
};

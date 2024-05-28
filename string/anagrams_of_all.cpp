//LEETCODE: 49. Group Anagrams



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        vector<vector<string>> v;
        vector<string> vs;

        for(int i=0; i<strs.size(); i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(strs[i]);

        }
        for(auto x:mp){
            v.push_back(x.second);
        }
        return v;

        
    }
};

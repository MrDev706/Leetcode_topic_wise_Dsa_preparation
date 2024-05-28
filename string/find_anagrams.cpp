//Leetcode: https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

class Solution {
public:
vector<int> findAnagrams(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
        if(s_len<p_len) return {};

        vector<int> wd(26, 0);
        vector<int> fq(26, 0);

        for(int i=0; i<p_len; i++){
            wd[s[i] - 'a']++;
            fq[p[i] - 'a']++;
        }

        vector<int> ans;
        if(wd == fq) {
            ans.push_back(0);

        }
        for(int i=p_len; i<s_len; i++){
            wd[s[i] - 'a']++;
            wd[s[i - p_len] - 'a']--;
            if(wd == fq){
                ans.push_back(i-p_len+1);
            }
        }
        return ans;


        
        
    }
};
//Letcode : Leeter combination of a phone number


class Solution {
public:
    void solve(string &dg, vector<string> pd, string &temp, vector<string> &out, int index){
        if(index==dg.size()){
            out.push_back(temp);
            return;
        }
        
        string s = pd[dg[index] - '0'];
        for(int i=0; i<s.size(); i++){
            temp.push_back(s[i]);
            solve(dg, pd, temp, out, index+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> output;
        if(digits.size()==0) return output;
        string temp;
        solve(digits, pad, temp, output, 0);
        return output;
        
    }
};
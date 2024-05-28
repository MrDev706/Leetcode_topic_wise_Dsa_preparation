
//Cout total number of palindromic substring

class Solution {
public:
int counter=0;
    int countSubstrings(string s) {

        for(int i=0; i<s.size(); i++){
            expandCenter(s, i, i);
            expandCenter(s, i, i+1);
        }
        return counter;
        
    }
    void expandCenter(string s, int i, int j){
        if( i<0 || j>s.size()-1)return ;
        if(s[i]==s[j] && i>=0 && j<s.size()){
            cout<<s[j]<<endl;
            counter++;
            expandCenter(s, i-1, j+1);
        }
        
    }
};


// Longest palindrome substring


class Solution {
public:
    string longestPalindrome(string s) {
        int len=0;
        int start = 0;
        for(int i=0; i<s.size(); i++){
            int odd = expandCenter(s, i, i);
            int even = expandCenter(s, i, i+1);
            if(len< max(odd, even)){
                len = max(odd, even);
                start = i -((len-1)/2);
            }
        }
        return s.substr(start, len);
    }
    int expandCenter(string s, int i, int j){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--;
            j++;
        }
        return j-i-1;
       
    }
};



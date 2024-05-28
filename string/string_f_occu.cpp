//LEETCODE: 28. Find the Index of the First Occurrence in a String


class Solution {
public:
    int strStr(string h, string n) {
        for(int i=0; i<= (int)(h.length()-n.length()); i++){
            
                if(h.substr(i, n.size()) == n){
                    return i;
                }
            
        }
        return -1;
        
    }
};

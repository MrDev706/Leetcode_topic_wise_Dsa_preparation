class Solution {
public:
    int myAtoi(string s) {
        int flag=0;
        int i = 0;

        while(i<s.size()){
            if(s[i]==' ') i++;
            else break;
        }
        if(s[i]=='-'){
            flag = 1;
            i++;
        }
        else if(s[i]=='+'){
            i++;
        }
        long ans = 0;
        for(int j=i; j<s.size(); j++){
            if(s[j]>='0' && s[j]<='9'){
                ans = ans * 10 + (s[j]-'0');
                if(ans>INT_MAX){
                    break;
                }
            }
            else {

            break;
            }
        }
        if(flag == 1){
            ans *= -1;
        }
        if(ans<=INT_MIN){
            return INT_MIN;
        }else if(ans>=INT_MAX){
            return INT_MAX;
        }
        return ans;

    }
};
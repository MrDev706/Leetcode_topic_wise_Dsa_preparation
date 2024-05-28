

class Solution {
public:
    
    bool isValid(string s) {
        stack<char> lst;
        for(auto i=s.begin(); i!=s.end(); ++i){
            if(*i=='(')  lst.push(')');
            else if(*i=='{') lst.push('}');
            else if(*i=='[') lst.push(']');
            else if(lst.empty() || lst.top()!=*i) return false;
            else lst.pop();
        }
        return lst.empty();
    }
};



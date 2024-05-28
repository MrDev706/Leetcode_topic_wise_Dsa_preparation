
#include <bits/stdc++.h>
using namespace std;

void reverse(string str){
    if(str.size()==0){
        return;
    }
    reverse(str.substr(1))
    cout<<str[0]<<endl;
}


int main(){
    string str = "Debashish today is the last day"
    reverse(str);
    return 0;
}




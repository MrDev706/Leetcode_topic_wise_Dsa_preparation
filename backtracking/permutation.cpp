
#include <bits/stdc++.h>
using namespace std;


void permutation(string& a, int l, int r){
    if(l==r){
        cout<<a<<endl;
    }else{
        for(int i=0; i<=r; i++){
            swap(a[i], a[l]);
            permutation(a, l+1, r);
            swap(a[i], a[l]);
        }
    }
}


inta main(){
    string a = "ABC";
    int n = a.size();

    permutation(a, 0, n-1)
}



//////////////////////////////////////

// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

void permute(string s, string answer)
{
	if (s.length() == 0) {
		cout << answer << " ";
		return;
	}
	for (int i = 0; i < s.length(); i++) {
		char ch = s[i];
		string left_substr = s.substr(0, i);
		string right_substr = s.substr(i + 1);
		string rest = left_substr + right_substr;
		permute(rest, answer + ch);
	}
}

// Driver code
int main()
{
	string s = "ABC";
	string answer = "";

	cout << "\nAll possible strings are : ";
	permute(s, answer);
	return 0;
}

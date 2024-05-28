//Print all the permutaions of a string or array
//LEETCODE: https://leetcode.com/problems/permutations/submissions/865528603/


class Solution {
public:
  vector<vector<int>> v;
    vector<vector<int>> permute(vector<int>& nums, int st=0) {
        solve(nums, 0);
        return v;
        
    }
    void solve(vector<int>& nums, int st){
         if(st==nums.size()-1) {
             v.push_back(nums);
             return;

         }
        for(int i=st; i<nums.size(); i++){
            swap(nums[i], nums[st]);
            
            solve(nums, st+1);
            swap(nums[i], nums[st]);


        }

    }
};




///////////STRING APPOARCH GFG/////////////

// C++ program to print all
// permutations with duplicates allowed
#include <bits/stdc++.h>
using namespace std;

// Function to print permutations of string
// This function takes three parameters:
// 1. String
// 2. Starting index of the string
// 3. Ending index of the string.
void permute(string& a, int l, int r)
{
	// Base case
	if (l == r)
		cout << a << endl;
	else {
		// Permutations made
		for (int i = l; i <= r; i++) {

			// Swapping done
			swap(a[l], a[i]);

			// Recursion called
			permute(a, l + 1, r);

			// backtrack
			swap(a[l], a[i]);
		}
	}
}

// Driver Code
int main()
{
	string str = "ABC";
	int n = str.size();

	// Function call
	permute(str, 0, n - 1);
	return 0;
}

// This is code is contributed by rathbhupendra


//////////////////////////////////////////////////


//Recursion
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


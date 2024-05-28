// C++ implementation to print all the palindromic
// permutations alphabetically
#include <bits/stdc++.h>
using namespace std;

const char MAX_CHAR = 26;

// Function to count frequency of each char in the
// string. freq[0] for 'a', ...., freq[25] for 'z'
void countFreq(char str[], int freq[], int n)
{
	for (int i = 0; i < n; i++)
		freq[str[i] - 'a']++;
}

// Cases to check whether a palindromic
// string can be formed or not
bool canMakePalindrome(int freq[], int n)
{
	// count_odd to count no of
	// chars with odd frequency
	int count_odd = 0;
	for (int i = 0; i < MAX_CHAR; i++)
		if (freq[i] % 2 != 0)
			count_odd++;

	// For even length string
	// no odd freq character
	if (n % 2 == 0) {
		if (count_odd > 0)
			return false;
		else
			return true;
	}

	// For odd length string
	// one odd freq character
	if (count_odd != 1)
		return false;

	return true;
}

// Function to find odd freq char and reducing its
// freq by 1, returns garbage value if odd freq
// char is not present
char findOddAndRemoveItsFreq(int freq[])
{
	char odd_char;

	for (int i = 0; i < MAX_CHAR; i++) {
		if (freq[i] % 2 != 0) {
			freq[i]--;
			odd_char = (char)(i + 'a');
			break;
		}
	}

	return odd_char;
}

// To find lexicographically first palindromic
// string.
bool findPalindromicString(char str[], int n)
{
	int freq[MAX_CHAR] = { 0 };
	countFreq(str, freq, n);

	// check whether a palindromic string
	// can be formed or not with the
	// characters of 'str'
	if (!canMakePalindrome(freq, n))
		// cannot be formed
		return false;

	// Assigning odd freq character if present
	// else some garbage value
	char odd_char = findOddAndRemoveItsFreq(freq);

	// indexes to store characters from the front
	// and end
	int front_index = 0, rear_index = n - 1;

	// Traverse characters in alphabetical order
	for (int i = 0; i < MAX_CHAR; i++) {
		if (freq[i] != 0) {
			char ch = (char)(i + 'a');

			// store 'ch' to half its frequency times
			// from the front and rear end. Note that
			// odd character is removed by
			// findOddAndRemoveItsFreq()
			for (int j = 1; j <= freq[i] / 2; j++) {
				str[front_index++] = ch;
				str[rear_index--] = ch;
			}
		}
	}

	// if true then odd frequency char exists
	// store it to its corresponding index
	if (front_index == rear_index)
		str[front_index] = odd_char;

	// palindromic string can be formed
	return true;
}

// function to reverse the characters in the
// range i to j in 'str'
void reverse(char str[], int i, int j)
{
	while (i < j) {
		swap(str[i], str[j]);
		i++;
		j--;
	}
}

// function to find next higher palindromic
// string using the same set of characters
bool nextPalin(char str[], int n)
{
	// if length of 'str' is less than '3'
	// then no higher palindromic string
	// can be formed
	if (n <= 3)
		return false;

	// find the index of last character
	// in the 1st half of 'str'
	int mid = n / 2 - 1;
	int i, j;

	// Start from the (mid-1)th character and
	// find the first character that is
	// alphabetically smaller than the
	// character next to it.
	for (i = mid - 1; i >= 0; i--)
		if (str[i] < str[i + 1])
			break;

	// If no such character is found, then all characters
	// are in descending order (alphabetically) which
	// means there cannot be a higher palindromic string
	// with same set of characters
	if (i < 0)
		return false;

	// Find the alphabetically smallest character on
	// right side of ith character which is greater
	// than str[i] up to index 'mid'
	int smallest = i + 1;
	for (j = i + 2; j <= mid; j++)
		if (str[j] > str[i] && str[j] < str[smallest])
			smallest = j;

	// swap str[i] with str[smallest]
	swap(str[i], str[smallest]);

	// as the string is a palindrome, the same
	// swap of characters should be performed
	// in the 2nd half of 'str'
	swap(str[n - i - 1], str[n - smallest - 1]);

	// reverse characters in the range (i+1) to mid
	reverse(str, i + 1, mid);

	// if n is even, then reverse characters in the
	// range mid+1 to n-i-2
	if (n % 2 == 0)
		reverse(str, mid + 1, n - i - 2);

	// else if n is odd, then reverse characters
	// in the range mid+2 to n-i-2
	else
		reverse(str, mid + 2, n - i - 2);

	// next alphabetically higher palindromic
	// string can be formed
	return true;
}

// function to print all the palindromic permutations
// alphabetically
void printAllPalinPermutations(char str[], int n)
{
	// check if lexicographically first palindromic string
	// can be formed or not using the characters of 'str'
	if (!(findPalindromicString(str, n))) {
		// cannot be formed
		cout << "-1";
		return;
	}

	// print all palindromic permutations
	do {
		cout << str << endl;
	} while (nextPalin(str, n));
}

// Driver program to test above
int main()
{
	char str[] = "malayalam";
	int n = strlen(str);
	printAllPalinPermutations(str, n);
	return 0;
}

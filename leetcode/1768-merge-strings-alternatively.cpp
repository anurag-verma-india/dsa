#include <iostream>
using namespace std;

class Solution
{
public:
	string mergeAlternately(string word1, string word2)
	{
		return word1 + word2;
	}
};

int main()
{
	Solution sol;
	cout << sol.mergeAlternately("abc", "pqr") << endl;
	return 0;
}

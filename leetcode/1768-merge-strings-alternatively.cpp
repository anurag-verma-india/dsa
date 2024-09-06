#include <iostream>
using namespace std;

class Solution
{
public:
	string mergeAlternately(string word1, string word2)
	{
		int word1_len = word1.length();
		int word2_len = word2.length();
		int loop_through = -1;
		string final_string;
		if (word1_len > word2_len)
			loop_through = word2_len;
		else
			loop_through = word1_len;
		for (int i = 0; i < loop_through; i++)
			final_string = final_string + word1[i] + word2[i];
		if (word1_len > word2_len)
			final_string += word1.substr(word2_len);
		else
			final_string += word2.substr(word1_len);
		return final_string;
	}
};

int main()
{
	Solution sol;
	cout << sol.mergeAlternately("abcdef", "pq") << endl;
	return 0;
}

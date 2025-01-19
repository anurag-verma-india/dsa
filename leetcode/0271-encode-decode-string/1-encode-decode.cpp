// https://neetcode.io/problems/string-encode-and-decode
// https://github.com/neetcode-gh/leetcode/blob/main/cpp%2F0271-encode-and-decode-strings.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string encode(vector<string> &strs) {
    string ans = "";
    int n = strs.size();
    for (int i = 0; i < n; i++) {
      ans.append(to_string(strs[i].size()));
      ans.append("#");
      ans.append(strs[i]);
    }
    return ans;
  }

  // vector<string> decode(string s) {
  //     vector<string> ans;
  //     int n = s.size();

  //     int i = 0;
  //     while (i < n) {
  //         int j = i;
  //         while (s[j] != '#') j++;
  //         int len = stoi(s.substr(i, j - i));
  //         string it = s.substr(j + 1, len);
  //         ans.push_back(it);
  //         i = j + 1 + len;
  //     }
  //     return ans;
  // }

  vector<string> decode(string s) {
    vector<string> ans;
    int i = 0;
    while (i < (int)s.size()) {
      int j = i;
      while (s[j] != '#')
        j++;
      int len = stoi(s.substr(i, j - i));
      ans.push_back(s.append(j + 1, len));
      j = j + len + 1;
    }
    return ans;
  }
};

int main() {
  if (!freopen("input.txt", "r", stdin)) {
    cout << "There was a problem opening the input file";
    exit(1);
  }

  // Read strings of arrays
  int n = 0;
  vector<string> inp;
  cin >> n;
  // cout << "n: " << n << "\n";
  string temp;
  getline(cin, temp);
  while (n--) {
    getline(cin, temp);
    inp.push_back(temp);
  }

  Solution sol;
  string encoded = sol.encode(inp);
  cout << "\nEncoded string: " << encoded << "\n";

  vector<string> decoded = sol.decode(encoded);
  printf("Decoded string\n");
  for (auto st : decoded)
    cout << "\"" << st << "\"" << ", ";
  printf("\n");

  if (inp == decoded)
    cout << "Decoding success\n";
  else
    cout << "Decoding failed\n";

  // ---------------- Empty checks
  // Solution sol;
  // // vector<string> a = {};
  // vector<string> a = {""};
  // cout << "Encoded size: " << a.size() << "\n";
  // string encoded = sol.encode(a);
  // cout << "Encoded:" << encoded << "-\n";
  // vector<string> decoded = sol.decode(encoded);
  // cout << "Decoded size: " << decoded.size() << "\n";
  // printf("Decoded:");
  // for (auto st : decoded) cout << st << "-";
  // cout << "-\n";

  return 0;
}

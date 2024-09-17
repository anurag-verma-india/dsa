#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	    int bigger_array = n;
	    if(bigger_array < m) bigger_array = m;
	    vector<int> final_array = {};
	    cout << "Bigger array's length is: " << bigger_array <<endl;
	    for(int i = 0; i<m;i++){
		    cout << nums1.at(i) << " ";
	    }
	    cout << endl;
	    for(int i = 0; i<n;i++){
		    cout << nums2.at(i) << " ";
	    }
	    cout << endl;
	}
};

int main() {
	Solution sol = Solution();

	vector<int> vec1 = {1,2,3,0,0,0};
	vector<int> vec2 = {2,5,6};
	int len_vec1= 3;
	int len_vec2= 3;

	sol.merge(vec1,len_vec1, vec2, len_vec2);
	return 0;
}

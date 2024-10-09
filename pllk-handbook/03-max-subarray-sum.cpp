#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[8] = {-1, 2,4,-3,5,2,-5,2};
	int sum = 0, best = 0, n = sizeof(arr)/sizeof(arr[0]);
	for(int k=0; k < n; k++){
		sum = max(arr[k], sum+arr[k]);
		best = max(sum, best);
	}
	cout << "Best sum is "<< best << "\n";
	return 0;
}

// Tried for 30 min couldn't solve in that time
// https://leetcode.com/problems/car-fleet/

#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"

class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int ans = 0;

        /*
        Add the speed to each position
        on each step check if any of the positions
            if yes then remove the faster one
        check if any of the fleet's position is equal to target then eliminate them
        */
        int n = position.size();
        while (!position.empty()) {
            for (int i = 0; i < n; i++) {
            }
        }
        // for (int i = 0; i < n; i++) {
        // }

        return ans;
    }
};

int main() {
    file_as_stdin("input.txt");
    int n, target;
    cin >> n;  // n is the number of elements in the two arrays
    vector<int> position = read_int(n);
    vector<int> speed = read_int(n);
    cin >> target;

    cout << "Position: ";
    for (int p : position) cout << p << " ";
    cout << "\n";

    cout << "Speed: ";
    for (int s : speed) cout << s << " ";
    cout << "\n";

    cout << "Target: " << target << "\n";

    return 0;
}
// https://leetcode.com/problems/car-fleet/
// https://www.youtube.com/watch?v=Pr6T-3yB9RM
// https://github.com/neetcode-gh/leetcode/blob/main/cpp%2F0853-car-fleet.cpp

#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_int.cpp"
/*
If a car is faster behind a slower car it will catch up
but cannot pass the slower car

Make pairs of position and time remaining to reach destination
Sort the pair list by position

Initialize result, fleets by = 0;

Maximum time to reach target (for last car is it's minimum time)
Since there are no cars ahead of it slower than it

So, following the same logic for each car check (from the end)
If it's time to reach is smaller then maxTime
Add one to number of fleets
*/

class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;

        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
            // cout << cars[i].second << " ";
            // printf("%f ", cars[i].second);
        }
        // cout << "\n";
        sort(cars.begin(), cars.end());

        double maxTime = 0;
        int fleets = 0;

        for (int i = n - 1; i >= 0; i--) {
            double time = cars[i].second;
            if (time > maxTime) {
                fleets++;
                maxTime = time;
            }
        }

        return fleets;
    }
};

int main() {
    file_as_stdin("input.txt");
    int n, target;
    cin >> n;  // n is the number of elements in the two arrays
    vector<int> position = read_int(n);
    vector<int> speed = read_int(n);
    cin >> target;

    Solution sol;

    cout << sol.carFleet(target, position, speed) << "\n";

    return 0;
}
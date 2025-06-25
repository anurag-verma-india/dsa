#include <bits/stdc++.h>
using namespace std;

// ----- brief explanation -----
// select minimum and swap with the first index
// select minimum again from the remaining array and swap with next index
// repeat until the last second index (because the remaining array with only last index is already sorted)

int main() {
    if (!freopen("input.txt", "r", stdin)) cout << "There was an error opening input.txt";
    if (!freopen("output.txt", "w", stdout)) cout << "There was an error opening output.txt";
    // Solution sol;

    // reading the input from input.txt
    int num_of_inputs, temp;
    vector<int> arr;

    cin >> num_of_inputs;

    for (int i = 0; i < num_of_inputs; i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    // ---------- sorting starts here  ----------

    // initialize the smallest index with 0
    int index_smallest_num = 0;

    // starting from 0 go check upto n - 2 (i.e. while index < n -1 )
    for (int starting_index = 0; starting_index < (int)arr.size() - 1; starting_index++) {
        // assume that the array before the starting index is sorted
        // check from starting index upto last index
        for (int j = starting_index; j < (int)arr.size(); j++) {
            if (arr[index_smallest_num] > arr[j]) {
                // save the index of the smallest number
                index_smallest_num = j;
            }
        }

        // now that we have the smallest number, swap the smallest number in the array with the starting index
        swap(arr[starting_index], arr[index_smallest_num]);
        index_smallest_num = starting_index + 1;
        // now the array upto the smallest index is sorted
    }

    // ------- end sorting --------

    // printing the sorted array to standard output
    cout << num_of_inputs << "\n";
    for (int i = 0; i < num_of_inputs; i++) {
        cout << arr[i] << " ";
    }
    printf("\n");
    return 0;
}

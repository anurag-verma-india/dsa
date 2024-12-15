#include <bits/stdc++.h>
using namespace std;


// ----- brief explanation -----
// select minimum and swap with the first index
// select minimum again from the remaining array and swap with next index
// repeat until the last second index (because the remaining array with only last index is already sorted)

int main() {
    if (!freopen("input.txt", "r", stdin)) cout << "There was an error opening input.txt";
    // Solution sol;

    // reading the input from input.txt
    int num_of_inputs, temp;
    vector<int> vec;

    cin >> num_of_inputs;

    for (int i = 0; i < num_of_inputs; i++) {
        cin >> temp;
        vec.push_back(temp);
    }

    // ---------- sorting starts here  ----------

    // initialize the smallest index with 0
    int index_smallest_num = 0;

    // starting from 0 go check upto n - 2 (i.e. while index < n -1 )
    for (int starting_index = 0; starting_index < num_of_inputs - 1; starting_index++) {
        // assume that the array before the starting index is sorted
        // check from starting index upto last index
        for (int j = starting_index; j < num_of_inputs; j++) {
            if (vec[index_smallest_num] > vec[j]) {
                // save the index of the smallest number
                index_smallest_num = j;
            }
        }

        // now that we have the smallest number, swap the smallest number in the array with the starting index
        swap(vec[starting_index], vec[index_smallest_num]);
        // now the array upto the smallest index is sorted
    }

    // printing the sorted array to standard output
    cout << num_of_inputs << "\n";
    for (int i = 0; i < num_of_inputs; i++) {
        cout << vec[i] << " ";
    }
    printf("\n");
    return 0;
}

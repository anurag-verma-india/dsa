// Beats T 22, M 56
// https://leetcode.com/problems/time-based-key-value-store/
#include <bits/stdc++.h>

#include "./file_as_stdin.cpp"
#include "./read_string.cpp"

/*
input:
    vec str: vector of operations to perform

output:
    print out the values

approach:

    use hashmap
        key -> pair of value vectors (value, timestamp)

    set(key, value, timestamp):
        add the (value, timestamp) pair to the given key's mapping vector

    get:
        binary search to get the key
            save the found value in a temp variable for each iteration

--
complexity
time:

space:

*/

class TimeMap {
   public:
    unordered_map<string, vector<pair<string, int>>> dataMap;
    TimeMap() {
    }
    // ~TimeMap() {
    //     for (auto val : dataMap) {
    //         cout << val.first << " -> [ ";
    //         for (auto par : val.second) {
    //             cout << "(" << par.first << ", " << par.second << "), ";
    //         }
    //         cout << " ]\n";
    //     }
    // }

    void set(string key, string value, int timestamp) {
        dataMap[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {
        vector<pair<string, int>>& timeValues = dataMap[key];

        if (timeValues.empty()) {
            return "";
        }
        string value = "";
        if (timestamp < timeValues[0].second) return "";
        int n = timeValues.size();

        int l = 0;
        int r = n - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            int mtim = timeValues[m].second;

            if (mtim == timestamp) {
                // value = timeValues[m].first;
                // return value;
                return timeValues[m].first;
            } else if (mtim < timestamp) {
                l = m + 1;
                value = timeValues[m].first;
            } else {
                r = m - 1;
                // value = timeValues[m].first;
            }
        }
        return value;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main() {
    // file_as_stdin("input.txt");

    // int n = 0;
    // vector<string> operation;
    // vector<vector<string>> content;
    // cin >> n;

    // string temp;
    // getline(cin, temp);
    // // while (n--) {
    // for (int i = 0; i < n; i++) {
    //     getline(cin, temp);
    //     operation.push_back(temp);
    // }
    // // }
    // // Print
    // for (auto s : operation) cout << s << " ";
    // cout << "\n";

    // // Get subsequent inputs

    // for (int i = 0; i < n; i++) {
    //     int k;
    //     cin >> k;
    //     vector<string> tempvec;

    //     while (k--) {
    //         getline(cin, temp);
    //         tempvec.push_back(temp);
    //     }
    //     content.push_back(tempvec);
    // }

    // for (auto ct : content) {
    //     for (auto it : ct) {
    //         cout << it << " ";
    //     }
    //     cout << "\n---\n";
    // }
    // ---------------------------------

    // vector<string> operations({"TimeMap",
    //                            "set",
    //                            "get",
    //                            "get",
    //                            "set",
    //                            "get",
    //                            "get"});
    // vector<vector<string>> data(
    //     {
    //         {""},
    //         {"foo", "bar", "1"},
    //         {"foo", "1"},
    //         {"foo", "3"},
    //         {"foo", "bar2", "4"},
    //         {"foo", "4"},
    //         {"foo", "5"},
    //     });

    vector<string> operations({"TimeMap", "set", "set", "get", "get", "get", "get", "get"});

    vector<vector<string>> data(
        {{""},
         {"love", "high", "10"},
         {"love", "low", "20"},
         {"love", "5"},
         {"love", "10"},
         {"love", "15"},
         {"love", "20"},
         {"love", "25"}});

    TimeMap* obj = new TimeMap();
    // obj->set(key, value, timestamp);
    // string param_2 = obj->get(key, timestamp);

    // for (string oper : operations) {
    cout << "\n";
    for (int i = 0; i < (int)operations.size(); i++) {
        if (operations[i] == "set") {
            obj->set(data[i][0], data[i][1], stoi(data[i][2]));

            printf("set: %s -> %s at %d\n",
                   data[i][0].c_str(), data[i][1].c_str(), stoi(data[i][2]));

        } else if (operations[i] == "get") {
            string param_2 = obj->get(data[i][0], stoi(data[i][1]));

            printf("get: %s at %d is %s\n", data[i][0].c_str(), stoi(data[i][1]), param_2.c_str());

        } else {
        }
    }

    printf("\n\nFinal Mapping was: \n");
    delete obj;
    return 0;
}
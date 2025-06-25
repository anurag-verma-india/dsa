#include <bits/stdc++.h>
using namespace std;

int main() {
    // there is also multiset (can have multiple instances of same value) 
    // This is unordered multiset which uses hashing instead of binary tree [O(1) instead of O(log n)]
    unordered_multiset<int> um_set;

    // Inserting 
    um_set.insert(2);
    um_set.insert(2);

    um_set.insert(3);
    um_set.insert(3);

    um_set.insert(4);
    um_set.insert(5);
    
    // Erase all instances  
    um_set.erase(2);
    
    // Erase first instance (though it is a UNORDERED multiset)
    um_set.erase(um_set.find(3));

    cout << "Size of um_set is " << um_set.size() << "\n";

}
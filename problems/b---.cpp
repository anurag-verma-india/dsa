#include<bits/stdc++.h>
using namespace std;

int main() {

    int* ptr = new int[10];

    int** pptr = new int *[5];

    for(int i = 0;i<5;i++) {
        pptr[i] = & ptr[i*2];
    }

    for(int i = 0;i<10;i++) {
        ptr[i] = i - 1;
    }

    for(int i = 0;i< 5;i++) {
        cout << **(pptr+i) << endl;
    }

    delete[]ptr;

    delete [] pptr;

    return 0;


}
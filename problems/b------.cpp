#include<bits/stdc++.h>
using namespace std;

void func(int *x,int * y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {

    int arr[5] = {3,4,5,1,2};

    int * ptr1 = & arr[3];

    int * ptr2 = &arr[1];

    func(ptr1, ptr2);

    cout<< arr[0] << arr[1]<< arr[2]<<arr[3]<<arr[4]<<endl;


    return 0;
}
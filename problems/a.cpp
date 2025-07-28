#include <stdio.h>
using namespace std;
void fun(int n) {
    if (n == 0) {
        return;
        fun(n - 1);
        printf("%d", n);
    }
}

int main() {
    fun(15);
    return 0;
}
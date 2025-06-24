# Armstrong Numbers, Palindrome Numbers, and Related Concepts

## Armstrong Numbers

**Armstrong number (also called narcissistic number) is a number equal to the sum of its digits raised to the power of the number of digits.**

### Concept:
- An n-digit number is an Armstrong number if the sum of each digit raised to the power n equals the original number
- Named after Michael F. Armstrong, though the mathematical concept predates the naming
- Also known as narcissistic numbers because they are "self-absorbed" - they reproduce themselves through their own digits
- Examples: 153 = 1³ + 5³ + 3³ = 1 + 125 + 27 = 153
- Single digit numbers (0-9) are trivially Armstrong numbers since each equals itself raised to power 1

### C++ Code Example:
```cpp
#include <iostream>
#include <cmath>
using namespace std;

int countDigits(int num) {
    int count = 0;
    while (num > 0) {
        count++;
        num /= 10;
    }
    return count;
}

bool isArmstrong(int num) {
    int original = num;
    int digits = countDigits(num);
    int sum = 0;
    
    while (num > 0) {
        int digit = num % 10;
        sum += pow(digit, digits);
        num /= 10;
    }
    
    return sum == original;
}

int main() {
    int number = 153;
    
    if (isArmstrong(number)) {
        cout << number << " is an Armstrong number" << endl;
    } else {
        cout << number << " is not an Armstrong number" << endl;
    }
    
    return 0;
}
```

## Palindrome Numbers

**Palindrome number reads the same forwards and backwards.**

### Concept:
- A number that remains unchanged when its digits are reversed
- Named after "palindrome" from Greek meaning "running back again" - just like the word concept, these numbers "run back" the same way
- Examples: 121, 1331, 7, 12321
- Single digit numbers are always palindromes
- Can be found in any base system, not just decimal

### C++ Code Example:
```cpp
#include <iostream>
using namespace std;

int reverseNumber(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

bool isPalindrome(int num) {
    return num == reverseNumber(num);
}

int main() {
    int number = 121;
    
    if (isPalindrome(number)) {
        cout << number << " is a palindrome number" << endl;
    } else {
        cout << number << " is not a palindrome number" << endl;
    }
    
    return 0;
}
```

## Related Mathematical Concepts

### Perfect Numbers

**Perfect number equals the sum of its proper positive divisors.**

### Concept:
- A positive integer equal to the sum of its proper divisors (excluding itself)
- Named "perfect" because they are exactly equal to their parts when added together - mathematically "complete"
- Examples: 6 = 1 + 2 + 3, 28 = 1 + 2 + 4 + 7 + 14
- Very rare - only 51 perfect numbers are known
- Connected to Mersenne primes in even perfect numbers

### C++ Code Example:
```cpp
#include <iostream>
using namespace std;

bool isPerfect(int num) {
    int sum = 1; // 1 is always a divisor
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i;
            if (i * i != num) { // Avoid adding square root twice
                sum += num / i;
            }
        }
    }
    
    return sum == num && num > 1;
}

int main() {
    int number = 28;
    
    if (isPerfect(number)) {
        cout << number << " is a perfect number" << endl;
    } else {
        cout << number << " is not a perfect number" << endl;
    }
    
    return 0;
}
```

### Happy Numbers

**Happy number eventually reaches 1 when replaced by sum of squares of its digits repeatedly.**

### Concept:
- Start with any positive integer and replace it with sum of squares of its digits
- Repeat until number equals 1 (happy) or loops endlessly in a cycle (sad)
- Named "happy" because reaching 1 represents a positive, satisfying mathematical outcome
- Example: 7 → 49 → 97 → 130 → 10 → 1 (happy)
- All numbers either become happy or enter the cycle: 4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4

### C++ Code Example:
```cpp
#include <iostream>
#include <unordered_set>
using namespace std;

int sumOfSquares(int num) {
    int sum = 0;
    while (num > 0) {
        int digit = num % 10;
        sum += digit * digit;
        num /= 10;
    }
    return sum;
}

bool isHappy(int num) {
    unordered_set<int> seen;
    
    while (num != 1 && seen.find(num) == seen.end()) {
        seen.insert(num);
        num = sumOfSquares(num);
    }
    
    return num == 1;
}

int main() {
    int number = 7;
    
    if (isHappy(number)) {
        cout << number << " is a happy number" << endl;
    } else {
        cout << number << " is a sad number" << endl;
    }
    
    return 0;
}
```

### Kaprekar Numbers

**Kaprekar number's square can be split into two parts that sum back to the original number.**

### Concept:
- Named after Indian mathematician D.R. Kaprekar who studied these in 1949
- The name honors the discoverer who found this elegant property of self-regeneration
- Split the square into two parts (left and right) such that their sum equals the original number
- Example: 297² = 88209, split as 88 + 209 = 297
- The split point can vary, and leading zeros are allowed in the left part

### C++ Code Example:
```cpp
#include <iostream>
#include <string>
using namespace std;

bool isKaprekar(int num) {
    if (num == 1) return true;
    
    long long square = (long long)num * num;
    string squareStr = to_string(square);
    int len = squareStr.length();
    
    for (int i = 1; i < len; i++) {
        string leftStr = squareStr.substr(0, i);
        string rightStr = squareStr.substr(i);
        
        int left = leftStr.empty() ? 0 : stoi(leftStr);
        int right = rightStr.empty() ? 0 : stoi(rightStr);
        
        if (right > 0 && left + right == num) {
            return true;
        }
    }
    
    return false;
}

int main() {
    int number = 297;
    
    if (isKaprekar(number)) {
        cout << number << " is a Kaprekar number" << endl;
        cout << "Verification: " << number << "² = " << number * number << endl;
    } else {
        cout << number << " is not a Kaprekar number" << endl;
    }
    
    return 0;
}
```
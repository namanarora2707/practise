#include <iostream>
using namespace std;

// Question 2: Check if string is palindrome
bool isPalindrome(string str) {
    int start = 0;
    int end = str.length() - 1;
    
    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main() {
    string str;
    cin >> str;
    
    if (isPalindrome(str)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}

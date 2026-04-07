#include <iostream>
using namespace std;

// Question 4: Count occurrences of a character in string
int countChar(string str, char ch) {
    int count = 0;
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    
    return count;
}

int main() {
    string str;
    char ch;
    
    getline(cin, str);
    cin >> ch;
    
    cout << countChar(str, ch) << endl;
    
    return 0;
}

#include <iostream>
using namespace std;

// Question 3: Find maximum element in array
int findMax(int arr[], int n) {
    int maxVal = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    
    return maxVal;
}

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << findMax(arr, n) << endl;
    
    return 0;
}

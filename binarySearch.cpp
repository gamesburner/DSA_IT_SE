#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == key) 
            return mid;
        
        if (arr[mid] > key) 
            right = mid - 1;
        
        else
            left = mid + 1;
    }
    
    return -1;
}

int main() {
    int n, key;
    
    cout << "Enter number of elements: ";
    cin >> n;
    
    int arr[n];
    
    cout << "Enter elements (sorted): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Enter key to search: ";
    cin >> key;
    
    int result = binarySearch(arr, n, key);
    
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in the array." << endl;
    
    return 0;
}

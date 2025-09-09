#include <iostream>
#include <vector>
using namespace std;

vector<int> findAllIndices(int arr[], int size, int key) {
    vector<int> indices;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            indices.push_back(i);
        }
    }
    return indices;
}

int main() {
    // Test case 1: Multiple occurrences
    int arr1[] = {3, 1, 3, 5, 3};
    vector<int> result1 = findAllIndices(arr1, 5, 3);
    cout << "Multiple occurrences - Indices: ";
    for (int i : result1) cout << i << " ";
    cout << endl;
    
    // Test case 2: Key not present
    int arr2[] = {1, 2, 4, 5};
    vector<int> result2 = findAllIndices(arr2, 4, 9);
    cout << "Key not present - Indices: ";
    for (int i : result2) cout << i << " ";
    cout << "(empty)" << endl;
    
    // Test case 3: Empty array
    int arr3[] = {};
    vector<int> result3 = findAllIndices(arr3, 0, 5);
    cout << "Empty array - Indices: ";
    for (int i : result3) cout << i << " ";
    cout << "(empty)" << endl;
    
    return 0;
}
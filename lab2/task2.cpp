#include <iostream>
using namespace std;

void calculateSumAndAverage() {
    int size;
    
    // get array size from user
    cout << "Enter the size of array: ";
    cin >> size;
    
    if (size <= 0) {
        cout << "Invalid size. Please enter a positive number." << endl;
        return;
    }
    
    // dynamically allocate memory for array
    int* arr = new int[size];
    
    // get array elements from user
    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    // calculate sum
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    
    // calculate average
    double average = static_cast<double>(sum) / size;
    
    // display results
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
    
    // deallocate memory
    delete[] arr;
    cout << "Memory deallocated successfully." << endl;
}

int main() {
    calculateSumAndAverage();
    return 0;
}
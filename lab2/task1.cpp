#include <iostream>
using namespace std;

void fill_array(){
    int size;
    cout << "Enter the size of array: ";
    cin >> size;  
    
    if (size <= 0) {
        cout << "Invalid size" << endl;
        return;
    }
    
    int* arr = new int[size];
    
    // fill array with values 
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
    
    // printing array
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    delete[] arr;
    cout << "Memory is cleared" << endl;
}

int main() {
    fill_array();
    return 0;
}
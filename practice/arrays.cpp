#include<iostream>
using namespace std;

void reversearray(int arr[], int n ){
    int start = 0;
    int end = n-1;
    while (start<end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main(){
    int arr[5] = {1,2,3,4,5};
    
    cout << "Original array: ";
    for (int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    reversearray(arr, 5);
    
    cout << "Reversed array: ";
    for (int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

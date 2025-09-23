#include <iostream>
using namespace std;
int binarysearch(int arr[],int left,int right, int key){
    if (left>right)
    {
       return -1;
    }
    int mid = left + (right-left)/2;
    if (arr[mid]==key)
    {
        return mid;
    }
    if (arr[mid]<key)
    {
        return binarysearch(arr,mid+1,right,key);
    }
    return binarysearch(arr,left,mid-1,key);
}
int main() {
   
    int n;
    do {
        cout << "Enter the size of array : ";
        cin >> n;
        if (n % 2 != 0) {
            cout << "Invalid size. Please enter a size that is a multiple of 2." << endl;
        }
    } while (n % 2 != 0);

    int array[n];
    cout << "Enter the elements of array in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    int key;
    cout << "Enter the element to be searched: ";
    cin >> key;
    int result = binarysearch(array, 0, n - 1, key);
    if (result == -1) {
        cout << "Element not found in the array." << endl;
    } else {
        cout << "Element found at index: " << result << endl;
    }

    return 0;
}
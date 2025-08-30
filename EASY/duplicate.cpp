#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n); // sort array

    int i = 0;
    for(int j = 1; j < n; j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }

    cout << "Array after removing duplicates:\n";
    for(int k = 0; k <= i; k++){
        cout << arr[k] << " ";
    }
}

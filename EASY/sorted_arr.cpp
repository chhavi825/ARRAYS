#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int main(){
    int n;
    cout<<"enter the number of elements";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"enter the elemnets of the array";
        cin>>arr[i];
    }
    bool issorted=true;

    for(int i=0;i<n;i++){
        if(arr[i]<arr[i-1]){
            issorted=false;
        }
    }
     if (issorted) {
        cout << "The array is sorted in ascending order." << endl;
    } else {
        cout << "The array is NOT sorted in ascending order." << endl;
    }
    

}
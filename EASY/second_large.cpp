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
    int largest=arr[0];
    int slargest=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            slargest=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>slargest){
            slargest=arr[i];
        }
    }
    cout<<slargest;

    int smallest=arr[0];
    int ssmallest=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<smallest){
            ssmallest=smallest;
            smallest=arr[i];
        }
        else if(arr[i]!=smallest && arr[i]<ssmallest){
            ssmallest=arr[i];
        }
    }
    cout<<ssmallest;

}
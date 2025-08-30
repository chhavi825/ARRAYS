#include<stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
//brute force 
/*
vector<int> findunion(int arr1[], int arr2[], int n, int m) {
    set<int> s;
    vector<int> unionVec;

    for (int i = 0; i < n; i++) {
        s.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++) {
        s.insert(arr2[i]);
    }

    for (auto &it : s) {
        unionVec.push_back(it);
    }
    return unionVec;
}

int main() {
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};

    vector<int> unionVec = findunion(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is  " << endl;
    for (auto &val : unionVec)
        cout << val << " ";
    cout << endl;
    return 0;
}
*/

//optimal approach 
//without using vectors 
/*
void unionOfArrays(int arr1[], int arr2[], int n, int m) {
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

    int i = 0, j = 0;
    int lastPrinted = INT_MIN; // to avoid duplicates

    cout << "Union of arr1 and arr2: ";

    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            if (arr1[i] != lastPrinted) {
                cout << arr1[i] << " ";
                lastPrinted = arr1[i];
            }
            i++;
        }
        else if (arr1[i] > arr2[j]) {
            if (arr2[j] != lastPrinted) {
                cout << arr2[j] << " ";
                lastPrinted = arr2[j];
            }
            j++;
        }
        else {
            // arr1[i] == arr2[j]
            if (arr1[i] != lastPrinted) {
                cout << arr1[i] << " ";
                lastPrinted = arr1[i];
            }
            i++; j++;
        }
    }

    // Remaining elements in arr1
    while (i < n) {
        if (arr1[i] != lastPrinted) {
            cout << arr1[i] << " ";
            lastPrinted = arr1[i];
        }
        i++;
    }

    // Remaining elements in arr2
    while (j < m) {
        if (arr2[j] != lastPrinted) {
            cout << arr2[j] << " ";
            lastPrinted = arr2[j];
        }
        j++;
    }

    cout << endl;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);

    unionOfArrays(arr1, arr2, n, m);
}
*/

// using vectors 

vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  int i = 0, j = 0; // pointers
  vector < int > Union; // Uninon vector
  while (i < n && j < m) {
    if (arr1[i] <= arr2[j]) // Case 1 and 2
    {
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(arr1[i]);
      i++;
    } else // case 3
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(arr2[j]);
      j++;
    }
  }
  while (i < n) // IF any element left in arr1
  {
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }
  while (j < m) // If any elements left in arr2
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }
  return Union;
}

int main()

{
  int n = 10, m = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12}; 
  vector < int > Union = FindUnion(arr1, arr2, n, m);
  cout << "Union of arr1 and arr2 is  " << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}
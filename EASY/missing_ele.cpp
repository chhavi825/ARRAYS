#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& a, int N) {
        int xor1 = 0, xor2 = 0;
        
        // XOR of all elements in the array
        for(int i = 0; i < N; i++) {
            xor2 = xor2 ^ a[i];
        }
        
        // XOR of all numbers from 0 to N
        for(int i = 0; i <= N; i++) {
            xor1 = xor1 ^ i;
        }
        
        // XOR of xor1 and xor2 gives the missing number
        return xor1 ^ xor2;
    }
};

int main() {
    vector<int> arr = {0, 1, 3, 4};  // example array
    int N = 4;  // highest number in the range (0..N)

    Solution sol;
    int missing = sol.missingNumber(arr, N);
    
    cout << "The missing number is: " << missing << endl;  // Output: 2

    return 0;
}

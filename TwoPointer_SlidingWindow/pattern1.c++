#include <bits/stdc++.h>
using namespace std;

// 1. constant window
// Ques -> find the maximum sum in a constant window
int main() {
    
    vector<int> a = {-1, 2, 3, 3, 4, 5, -1};
    int n = a.size();
    int k = 4; // size of the window 

    int l = 0;
    int r = k-1;

    int sum = 0;
    for(int i =  0; i <= r; i++){
        sum += a[i];
    }
    int maxSum = sum;
    while(r < n-1){
        sum -= a[l];
        l++;
        r++;
        sum += a[r];
        maxSum= max(maxSum, sum);
    }
    cout << maxSum;
    return 0;
}
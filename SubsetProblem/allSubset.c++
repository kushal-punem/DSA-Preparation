#include <bits/stdc++.h>
using namespace std;

void allSubset(vector<int> ip, vector<int> op){
    
    if (ip.size() == 0) {
        // print current subset
        cout << "{ ";
        for (auto &x : op)
            cout << x << " ";
        cout << "} ";
        return;
    }

    vector<int> op1 = op;
    vector<int> op2 = op;

    op2.push_back(ip[0]);
    ip.erase(ip.begin());  //[start, end)

    allSubset(ip,op1);
    allSubset(ip,op2);

    return;

}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n = 3;
    vector<int> ip(n);

    cout << "Enter string: ";
    // getline(cin, ip);
    for(int i = 0; i < n; i++){
        cin >> ip[i];
    }

    vector<int> op;
    allSubset(ip, op);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(void){
    vector<int> v(2);
    for(int i = 0; i < 2; i++) {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    if(v[0]*2 == v[1] || v[0]*2+1 == v[1]) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}

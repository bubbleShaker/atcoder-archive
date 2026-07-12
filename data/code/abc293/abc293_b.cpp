#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    set<int> sp;
    for(int i = 1; i <= n; i++) sp.insert(i);
    vector<int> A(n+1);
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }
    for(int i = 1; i <= n; i++){
        if(sp.count(i)){
            sp.erase(A[i]);
        }
    }
    
    cout << sp.size() << endl;
    
    int i = 0;
    
    for(int t : sp){
        cout << t << " \n"[i + 1 == sp.size()];
        i++;
    }
    return 0;
}
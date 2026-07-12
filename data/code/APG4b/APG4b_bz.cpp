#include <bits/stdc++.h>
using namespace std;

int main(){
    int i, a, ans, N;
    int max = 0;
    map<int, int> m;
    cin >> N;
    vector<int> s(N);
    
    for(i = 0; i < N; i++){
        cin >> a;
        s.at(i) = a;
        m[a] += 1;
    }
    
    for(i = 0; i < N; i++){
        if(max < m[s.at(i)]){
            ans = s.at(i);
            max = m[s.at(i)];
        }
    }
    
    cout << ans << " " << max << endl;
}
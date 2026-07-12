#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main(void){
    int N, Q;
    cin >> N >> Q;
    
    set<int> t1; //受付に呼ばれていない集合
    set<int> t2; //受付に呼ばれたが行っていない集合
    set<int> t3; //行った集合
    
    for(int i = 1; i <= N; i++){
        t1.insert(i);
    }
    
    for(int i = 0; i < Q; i++){
        int n;
        cin >> n;
        if(n == 1){
            int t = *begin(t1);
            t2.insert(t);
            t1.erase(t);
        }else if(n == 2){
            int x;
            cin >> x;
            t3.insert(x);
            t2.erase(x);
        }else{
            int t = *begin(t2);
            cout << t << endl;
        }
    }
    
    return 0;
}
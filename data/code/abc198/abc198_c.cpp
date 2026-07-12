#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    long double R, X, Y;
    cin >> R >> X >> Y;
    
    long double dist = sqrt(X*X + Y*Y);
    if(dist < R){
        cout << 2 << endl;
        return 0;
    }else{
        cout << ceil(dist/R) << endl;
        return 0;
    }
    return 0;
}

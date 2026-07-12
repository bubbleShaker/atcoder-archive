#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, Mx, Mn;
  cin >> A >> B >> C;
  
  Mx = max(max(A, B), C);
  Mn = min(min(A, B), C);
  
  cout << Mx - Mn << endl;
}

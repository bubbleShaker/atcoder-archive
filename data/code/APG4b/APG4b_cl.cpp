#include <bits/stdc++.h>
using namespace std;

int main() {
  int i, N, A, B;
  string op;
  cin >> N >> A;

  for(i = 0; i < N; i++){
    cin >> op >> B;
    if(op == "+")
      A += B;
    else if(op == "-")
      A -= B;
    else if(op == "*")
      A *= B;
    else if(op == "/"){
        if(B == 0){
          cout << "error" << endl;
          break;
        }
        else{
            A /= B;
        }
    }
    
    cout << i+1 << ":" << A << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  int i, sum = 1;
  cin >> S;
  
  for(i = 1; i < S.size(); i+=2){
      if(S[i] == '+'){
          sum += 1;
      }else if(S[i] == '-'){
          sum -= 1;
      }
  }
  
  printf("%d\n", sum);
}

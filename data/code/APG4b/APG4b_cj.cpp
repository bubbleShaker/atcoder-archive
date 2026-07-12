#include <bits/stdc++.h>
using namespace std;

int main() {
  int i, N, average = 0;
  cin >> N;
  vector<int> vec(N);
  
  for(i = 0; i < N; i++){
      cin >> vec.at(i);
      average += vec.at(i);
  }
  
  average /= vec.size();
  
  for(i = 0; i < N; i++){
      cout << abs(average - vec.at(i)) << endl;
  }
}

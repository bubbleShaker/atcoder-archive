#include <iostream>
#include <iomanip>
int main(){
  long long n,k;
  std::cin>>n>>k;
  std::cout<<std::fixed<<std::setprecision(10);
  long long cnt1=k-1+(n-k); //2つ同じ数字の組み合わせ数
  long long cnt2=(k-1)*(n-k); //全て異なる数字の組み合わせ数
  long long bunshi=cnt1*3+1+cnt2*6; //1は全て同じ数字の組み合わせ数
  long long bunbo=n*n*n;
  std::cout<<(double)bunshi/(double)bunbo<<'\n';
  return 0;
}
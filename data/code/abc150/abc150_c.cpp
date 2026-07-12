#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
int main(){
	int n;
	std::cin>>n;
	std::vector<int> p(n),q(n);
	for(int i=0;i<n;i++){
		std::cin>>p[i];
	}
	for(int i=0;i<n;i++){
		std::cin>>q[i];
	}
	std::vector<int> pp(n);
	// #include<numeric>
	std::iota(pp.begin(),pp.end(),1);
	int a,b;
	int idx=0;
	do{
		if(pp==p){
			a=idx;
		}
		if(pp==q){
			b=idx;
		}
		idx++;
	}while(std::next_permutation(pp.begin(),pp.end()));
	std::cout<<std::abs(a-b)<<'\n';
	return 0;
}
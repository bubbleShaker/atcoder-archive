#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <iomanip>
struct node{
	double x;
	double y;
};
int main(){
	int n;
	std::cin>>n;
	std::vector<node> city(n);
	for(int i=0;i<n;i++){
		std::cin>>city[i].x>>city[i].y;
	}
	std::vector<int> p(n);
	std::iota(p.begin(),p.end(),0);
	auto dist=[&](int a,int b){
		return std::sqrt((city[a].x-city[b].x)*(city[a].x-city[b].x)+(city[a].y-city[b].y)*(city[a].y-city[b].y));
	};
	double sum=0;
	do{
		for(int i=0;i<n-1;i++){
			sum+=dist(p[i],p[i+1]);
		}
	}while(std::next_permutation(p.begin(),p.end()));
	auto fact=[&](int n){
		int ret=1;
		while(n>0){
			ret*=n;
			n--;
		}
		return ret;
	};
	// #include <iomanip>
	std::cout<<std::fixed<<std::setprecision(10);
	std::cout<<sum/(double)fact(n)<<'\n';
	return 0;
}
#include <iostream>
int main(){
	int x,y;
	std::cin>>x>>y;
	auto ceili=[&](int a,int b){
		return (a+(b-1))/b;
	};
	std::cout<<((x<y)?ceili(y-x,10):0)<<'\n';
	return 0;
}
//CORECTO
#include <iostream>
#include <string>
#define N 50
unsigned long long int ways[N];
using namespace std;
int main(){
//length twice as long as hoeight 
	unsigned long long int km =1,k=2,tmp;
	ways[0] = 0;
	ways[1] =1;
	ways[2] = 2;
	for(int i = 3;i<N+1;i++){
		tmp = k;
		k += km;
		km =tmp;
		ways[i] = k;
	}
	int in;
	while(cin >> in && in != 0){
		cout << ways[in]<<endl;
	} 
return 0;
}

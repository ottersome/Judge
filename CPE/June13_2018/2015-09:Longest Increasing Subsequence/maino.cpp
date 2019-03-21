#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(){

    int inputo = 0;
    while(cin >> inputo){
        if(inputo==0)
            return 0;
        if(inputo !=1){
        cout << pow(2,inputo/2)+(inputo%2)<<endl;
        }else{
            cout << 1<<endl;
        }

    }
    return 0;
}

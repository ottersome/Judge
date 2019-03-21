#include<iostream>

using namespace std;

typedef long unsigned int trozo;

trozo trozos[100];
int main(){

    //Simpley do  fibonacci sequence
    trozos[0] = trozos[1] = 1;
    for(int i =2;i<100;i++){
        trozos[i] = trozos[i-1] + trozos[i-2];    
    }
    int inputo;
    while(cin >> inputo){
        if(inputo == 0) break;
        cout <<trozos[inputo]<<endl;
    }
    

    return 0;
}

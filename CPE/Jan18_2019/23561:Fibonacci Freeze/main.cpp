#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

#define N 5005
#define M 2010
using namespace std;
int arroyo[N][M];
int carry =0;
void fill(){
    arroyo[0][0] = 0;
    arroyo[1][0] = 1;
    for(int i =2;i<N-1;i++){
        //Dynamic Programming
        //Lets use base 10
        for(int j =0;j<M;j++){
           arroyo[i][j] += arroyo[i-1][j] + arroyo[i-2][j]; 
           arroyo[i][j+1] = (arroyo[i][j] /10);
           arroyo[i][j] %= 10;
        }

    }

}
int main(){

    memset(arroyo,0,N*M*sizeof(arroyo[0][0]));
    fill();
    int inp;
    int index;
    while(cin >>inp){
        index = M-1;
        printf("The Fibonacci number for %d is ",inp);
        while(arroyo[inp][index] == 0 && index>0){
            index--;
        }
        while(index >=0){
            cout << arroyo[inp][index];
            index--;
        }
        cout <<endl;

    }
    return 0;
}

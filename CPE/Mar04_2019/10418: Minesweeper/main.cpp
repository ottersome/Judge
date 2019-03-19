#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

#define N 101
#define M 101

char arrayo[N][M];

void createField(int n,int m){
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin >> arrayo[i][j];
        }
    }
}
int main(){

    int n,m;
    while(cin >> n>>m){
        if(n == 0 && m ==0)
            break;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                cin >> arrayo[i][j];
            }
        }
    }


    return 0;
}

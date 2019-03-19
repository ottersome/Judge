#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

#define N 110
using namespace std;

char arrayo[N][N];
char answer[N][N];
void addAnswer(int i, int j){
    //check bounds
    if(i >= 0 && j >=0){//avoid memory error
        if(arrayo[i][j] != '*'){
            answer[i][j]++;
        }

    }
}
int main(){

    int n,m;
    int counter =0;
    while(cin >> n >> m){
        counter++;
        memset(arrayo,'\0',sizeof(arrayo[0][0]*N*N));
        memset(answer,'0',sizeof(answer[0][0]*N*N));
    if(n == 0 && m ==0)
        break;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> arrayo[i][j];
                answer[i][j] = '0';
            }
        }
        //Got hte Input
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arrayo[i][j] == '*'){
                    //add to surroundings 
                    answer[i][j] = '*';
                    for(int u = i-1;u <= i+1;u++){
                        for(int v = j-1;v<=j+1;v++){
                            if(u == i && v == j){
                            }else{
                                addAnswer(u,v);
                                }
                        }
                    }
                }
            }
        }
        //output answer
        printf("Field #%d:\n",counter);
        for(int i =0;i<n;i++){
            for(int j = 0;j < m;j++){
                    cout << answer[i][j];
                }
            cout << endl;
        }
        cout <<endl;


    }
    return  0;
}

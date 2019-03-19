#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

#define N 110
#define M 110

char arrayo[N][M];
char answer[N][M];

void placeWarnings(int i ,int j){
    answer[i][j] = '*';
    for(int u =i-1;u<=i+1;u++){
        for(int v =j-1;v<=j+1;v++){
            if(u >=0 && v>=0 && answer[u][v]!='*'){
                answer[u][v]++;                                
            }
        }
    }
}
void createField(int n,int m){
    memset(answer,'0',N*M*sizeof(answer[0][0]));
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(arrayo[i][j] == '*')//then we inspect
                placeWarnings(i,j);
        }
    }
}
int main(){

    int n,m;
    int caseNo =1;
    while(cin >> n>>m){
        if(n == 0 && m ==0)
            break;
        if(caseNo != 1){
            cout <<endl;
        }
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                cin >> arrayo[i][j];
            }
        }
        createField(n,m);
        printf("Field #%d:\n",caseNo++);
        //printAnswer
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                cout << answer[i][j];
            }
            cout <<endl;
        }
    }


    return 0;
}

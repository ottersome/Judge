#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;
#define S 105

char arroyo[S][S];
int M,N,Q;
int findSize(int i,int j){
    int radius =0;
    bool inBounds = (i-(radius+1) >=0 && i+(radius+1)<M)&&(j-(radius+1)>=0 &&j+(radius+1)<N);
    while(inBounds){
        //Expand    
        for(int u = i-(radius+1);u<=i+(radius+1);u++){
            for(int v=j-(radius+1);v<=j+(radius+1);v++){
               if(arroyo[u][v] != arroyo[i][j])
                   return 1+ (2*radius);
            }
        }
        radius++;
        inBounds = (i-(radius+1) >=0 && i+(radius+1)<M)&&(j-(radius+1)>=0 &&j+(radius+1)<N);
    }
    return 1 + (2*radius);
}
int main(){

    int testCases;
    cin >> testCases;
    int r,c;
    while(testCases){
        memset(arroyo,'\0',N*N*sizeof(arroyo[0][0]));
        //get first three nums
        cin >> M>>N>>Q;
        //input grid
        for(int i =0;i<M;i++){
            for(int j =0;j<N;j++){
                cin >> arroyo[i][j];
            }
        }
        //Now get locations
        printf("%d %d %d\n",M,N,Q);
        while(Q){
            cin >> r >>c;
            //find the square
            cout <<  findSize(r,c)<<endl;
            cin.get();
            Q--;
        }

    
        testCases--;
    }

    return 0;
}

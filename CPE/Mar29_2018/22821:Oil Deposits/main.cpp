#include <iostream>
#include <vector>

using namespace std;

#define N 105

typedef pair<int,int> par;

char grid[N][N];
int curCount = 0;
void inspect(int i,int j){
    //double check
    //start stack
    vector<par> stacko;
    stacko.push_back(make_pair(i,j));
    int u,v;
    while(!stacko.empty()){
        par curPar = stacko.back();
        u = curPar.first;v =curPar.second;
        stacko.pop_back();
        if(grid[u][v] != '@') continue;

        for(int a=-u;a<


    }
}
int main(){

    int m,n;
    while(cin >>m>>n){
        if(m == 0) break;
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                cin >> grid[i][j];
            }
        }
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
               inspect(i,j); 
            }
        }

    }

    return 0;
}

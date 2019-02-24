#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;

#define N 1000
typedef pair<int,char> par;
typedef pair<int,int> intpair;
par NEGINF = make_pair(-1,'\0');

string a,b;
intpair sequence[1000][1000];

par memo[N][N];
par searchDyn(int i,int j){//i and j are the indices of where we are in both words
    if(i < 0 || j<0){
        return make_pair(0,'\0');
    }
    printf("Entering with (%d,%d)=(%c,%c).\n",i,j,a[i],b[j]);
    if (memo[i][j] != NEGINF){
        return memo[i][j];
    }//else
    //check limits
    //check the three cases
    if(a[i] == b[j]){//weve got a match
        return memo[i][j] = make_pair(searchDyn(i-1,j-1).first + 1,a[i]);
        sequence[i][j] = make_pair(i-1,j-1);
    }else{
        par ig = searchDyn(i,j-1);
        par jg = searchDyn(i-1,j);
        if(ig.first > jg.first){
            return memo[i][j] = ig;
            sequence[i][j] = make_pair(i,j-1);
        }else{
            return memo[i][j] = jg;
            sequence[i][j] = make_pair(i-1,j);
        }
    }
    

}

void iniMemo(){
    for(int i =0;i<N;i++){
        for(int j = 0;j<N;j++){
            memo[i][j] = NEGINF;
            sequence[i][j] = make;
        }
    }
}

int main(){
    iniMemo();
    //Ok este es dynamic programming
    int i, j;//indices of position but in this case it will always be the last letter of the word
    while(cin >> a>> b){
        i = a.length() -1;
        j = b.length() -1;

        cout << "Searching"<<endl;
        par result =searchDyn(i,j);
        cout << "Result was of " << result.first<<endl;
        cin.get();
        cin.get();

    }
    return 0;
}

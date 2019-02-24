#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

#define N 1000
#define M 1000
#define NEGINF 9//TODO make it better
using namespace std;
string s1; 
string s2; 

int memo[N][M];
int lcs(int i1, int i2){
    //printf("Entering with i1:%d, i2:%d \n",i1,i2);
    //cin.get();
    //aqui iria memoization
    if(memo[i1][i2] != NEGINF){//that means we got a hit on memory
        //cout << "Here my boi"<<endl;
        //printf("Value of indices i1:%d, i2:%d, and is : %i\n",i1,i2,memo[0][0]);
        return memo[i1][i2];
    }else if(i1+1 > s1.length() && i2+1 > s2.length()){
        return 0;
    }else if(i1+1 > s1.length() || i2+1 > s2.length()){
        return 0;
    }//else
    if(s1[i1] == s2[i2]){
        //printf("We got some equal putos\n");
        return memo[i1][i2] = lcs(i1+1,i2+1) + 1;
    }else{
        return memo[i1][i2] = max(lcs(i1+1,i2),lcs(i1,i2+1));
    }
}

void cleano(){
    for(int i =0;i<N;i++){
        for(int j=0;j<M;j++)
            memo[i][j] = NEGINF;
    }
}
int main(){
   while(cin >> s1 >> s2){
       cleano();
       int amount = lcs(0,0);
       cout <<amount<<endl;
   }

}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main(){

    int inputo;
    while(cin >> inputo){

        int enjoy = inputo;
        //now we consume them 
        int empty = inputo;
        while(empty/3>0){
            //now give your empty ones
            enjoy += empty /3;
            empty = (empty%3)+(empty/3);
            if(empty == 3){
                enjoy+=1;
                break;
            }
            if(empty == 2){
                enjoy +=1;
                break;
            }
        }
        cout<<enjoy<<endl;
    }

    return 0;
}

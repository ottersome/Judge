#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

bool Switches[3005];
int pushed[3005];
char tempo;
int main(){

    int nums;
    int totals;
    while(cin >> nums){
        totals = nums-1;
        memset(Switches,0,3005*sizeof(Switches[0]));
        for(int i =0; i < nums;i++){
            cin >> pushed[i];
        }
        //get the differences
        for(int i =0;i<nums-1;i++){
            int diff = abs(pushed[i] - pushed[i+1]);
            if(Switches[diff] == false && diff >= 1 && diff <= nums-1){
                totals--; 
                Switches[diff] = true;
            }
        }
        if(totals == 0){
            cout << "Jolly"<<endl;
        }else{
            cout << "Not jolly"<<endl;
        }
    }
    return 0;
}

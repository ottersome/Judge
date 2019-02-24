#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main(){

    int T;//number of tests cases to follow
    int N;//number of days to run simulation
    int P;//number of political parties
    int h[100];//hartal parameters for each party

    cin >> T;
    while(T){
        cin >> N >> P;
        for(int i = 0;i<P;i++){
            cin >> h[i];
        }
        //no we calculate amount
        int totalAmount= 0;
        for(int i = 1;i<= N;i++){
            if(i%7 == 6 || i%7 ==0)
                continue;//We dont care about fridays and saturdays
            //Remember that multiples of 7 will be s
            for(int j =0;j<P;j++){
                if(i % h[j] ==0){
                    totalAmount++;
                    break;
                }
            }
            
            
        }

       cout <<totalAmount<<endl;
        T--;
    }
}

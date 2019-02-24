#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

#define base 100000000LL
#define MAX 400

typedef long long int ll;

class BigNum{

    public:
        int numbo[MAX];

        BigNum(){
            memset(numbo,0,sizeof(numbo[0])*MAX);
        }

        BigNum& operator=(int initialValue){//i dont think we need string since the greatest number given is 
            numbo[0] = initialValue;
            return *this;
        }


        BigNum operator*(int factor){//we dont need anything more than an int because the greates numebr we will multiply against is 100
            ll tempo = 0;
            BigNum result;
            for(int i =0;i<MAX;i++){
                tempo += (long long) numbo[i] * factor;//add because of the carry i assume
                result.numbo[i] = tempo % base;
                tempo /= base;
            }
            return result;
        }
        int countTotalSum(){
            //In this method we add every digit in base 10 i assume
            int tmp, sum =0;
            for(int i =0;i < MAX ;i++){
                tmp = numbo[i];//que puede tener un valor maximo de como 32k
                while(tmp){//not equals 0
                    sum += tmp % 10;
                    tmp /= 10;//for base 10
                }
            }
            return sum;
        }
};

int resulto[1001];
int main(){
    resulto[0] = 1;//Base case
    int inputo = 0;
    BigNum curCase;
    curCase = 1;
    for(int num=1; num<=1000;num++){
        curCase = curCase*num;
        resulto[num] = curCase.countTotalSum();
    }
    while(cin >> inputo){
        cout << resulto[inputo]<<endl;
    }

}

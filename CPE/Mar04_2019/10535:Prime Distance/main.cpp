#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;
typedef long unsigned int llu;
#define INF ULONG_MAX

vector<llu> primes;
int main(){

    int divisor = 2;
    //I think we should do sieve first
    llu L,U;
    llu minDiff,maxDiff;
    llu minL=0,minR=0,maxL=0,maxR=0;
    while(cin >> L >> U){
        primes.clear();
        for(llu i =L;i<=U;i++){
            divisor = 2;
            while(i%divisor > 0 && divisor<sqrt(i)){
                divisor++;
            }
            if(i%divisor >0 || i==2){
                primes.push_back(i);
            }
            //
        }
        if(primes.size() <= 1){
            printf("There are no adjacent primes.\n");
            continue;
        }
        maxDiff = 0;
        minDiff = INF;
        vector<llu>::iterator it = primes.begin(); 
        while(it != primes.end()-1){
            //iterate though list and get min and max
            if(*(it+1) - *it < minDiff){
                minDiff = *(it+1) - *it;
                minL = *it;
                minR = *(it+1);
            }else if(*(it+1) - *it > maxDiff){
                maxDiff = *(it+1) - *it;
                maxL = *it;
                maxR = *(it+1);
            }
            it++;
        }
    printf("%lu,%lu are closest, ",minL,minR);
    printf("%lu,%lu are most distant.\n",maxL,maxR);
    }
    return 0;
}

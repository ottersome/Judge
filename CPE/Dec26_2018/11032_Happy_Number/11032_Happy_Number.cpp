#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int addIt(unsigned long cur, unsigned long ori){
    unsigned long sumo =0;
    int rem=cur;
    rem = cur%10;
    sumo = rem*rem;
    cur /=10;
    while(cur>0){
        rem = cur%10;
        sumo += rem*rem;
        cur /= 10;
    }

    return (sumo==1 ||ori>=9)?sumo: addIt(sumo,ori+1);
}
int main(){
    unsigned long n,k;
    cin >> n;
    for(int i =0;i<n;i++){
       cin >> k; 
       string mess = (addIt(k,0) != 1)?"an Unhappy number.":"a Happy number.";
       printf("Case #%lu: %lu is ",i+1,k);
       cout << mess<<endl;
    
    }
    return 0;
}

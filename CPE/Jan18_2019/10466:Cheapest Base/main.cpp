#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <climits>

using namespace std;
#define INF INT_MAX

int costs[37];
vector<int> numInBase;

vector<int> returnCost(int numero){
    int min = INF;
    vector<int> returnVector;
    int totalValue = 0;
    int tempNum;
    numInBase.clear();
    for(int base = 2;base <= 36;base++){
        tempNum = numero;
        totalValue = 0;
        while(tempNum/base != 0){
            totalValue += costs[tempNum%base];
            tempNum/=base;
        }
        totalValue += costs[tempNum%base];
        tempNum/=base;
        if(totalValue < min){
            returnVector.clear();
            returnVector.push_back(base);
            min =totalValue;
        }else if(totalValue ==min){
            returnVector.push_back(base);
        }
        totalValue =0;
    }
    return returnVector;
}
int main(){
    int numCases = 0;
    int numQueries = 0;
    int curQuery =0;
    cin >>numCases;
    int caseNo =1;
    while(numCases){
        printf("Case %d:\n",caseNo++);
        //get costs
        for(int i =0; i< 36;i++){
            cin >> costs[i];
        }
        //Get num of querys
        cin >> numQueries;
        while(numQueries){
        
            cin >> curQuery;
            vector<int> respuesta = returnCost(curQuery);
            vector<int>::iterator it = respuesta.begin();
            printf("Cheapest base(s) for number %d:",curQuery);
            while(it != respuesta.end()){
                cout <<" "<< *it;
                it++;
            }
            numQueries--;
            cout <<endl;
        }
        numCases--;
        if(numCases >0)
            cout <<endl;
    }

    return 0;
}

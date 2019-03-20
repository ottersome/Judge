#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

int main(){
    string line;
    //four inputs
    int conNo,probNo, timeo;
    char L;

    //string stream to parse
    stringstream ss;

    int cases;
    cin >> cases;
    if(!cases)
        return 0;
    do{
        while(getline(std::cin,line) && !line.empty()){
            //extract for inputs
            ss = stringstream(line);
            ss >> conNo >> probNo >>  timeo >> L;
            printf("This are the ones you entered ");
        }
    
        cases--;
    }while(cases);

    return 0;
}

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;
int instructions[105];//-1 = left, 1 = right
string tempo;
int pos;
int curPos;
int main(){

    string instruction;

    int testCases;
    cin >> testCases;
    int numInstructions;
    while(testCases){
        cin >> numInstructions;
        curPos = 0;
        for(int i =0;i<numInstructions;i++){
            cin >> instruction;
            if(instruction != "LEFT" && instruction != "RIGHT"){
                cin >> tempo;
                cin >> pos;
                instructions[i] = instructions[pos-1];
            }else{
            instructions[i] = (instruction == "LEFT")? -1:1;
            }
            curPos += instructions[i];
        }
        cout << curPos<<endl;
        testCases--;
    }

    return 0;
}

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
vector<string> inputo;
string tempo;
int numPaths =0;

string getFirstLevel(string dir){
    //printf("About to print it:\n");
    if(dir.find('\\') == string::npos)
        return dir;
    //cout << "\t"<<dir.substr(0,dir.find('\\'))<<endl;
    return dir.substr(0,dir.find('\\'));
}
string removeFirstLevel(string dir){
    //printf("About to print it after:\n");
    //cout << "\t"<<dir.substr(dir.find('\\')+1,string::npos)<<endl;
    return dir.substr(dir.find('\\')+1,string::npos);
}
void printer(vector<string> curStr,int level){
    if(curStr.empty()) return;
    string aimed = getFirstLevel(*curStr.begin());
    for(int i =0;i<level;i++){
        cout <<' ';
    }
    cout <<aimed<<endl;
    cin.get();
    while(!curStr.empty()){
        vector<string> nextLevel;
        vector<string>::iterator it = curStr.begin();
        for(;it!=curStr.end();it++){
            if(getFirstLevel(*it) == aimed){
                nextLevel.push_back(removeFirstLevel(*it));
                cout <<" For : "<<getFirstLevel(*it)<<endl;
                cout << "\tPushing Value : "<<removeFirstLevel(*it)<<endl;
            }            
        }
        it = nextLevel.begin();
        for(;it!=nextLevel.end();it++){
            curStr.erase(it);
        }
        cout << "Do we even make it here?"<<endl;
        printer(nextLevel,level+1);
    }

}


int main(){

    cin >> numPaths;
    for(;numPaths!=0;numPaths--){
        cin >> tempo;
        inputo.push_back(tempo);
    }
    printer(inputo,0);
    //we now go one by one 

    return 0;
}


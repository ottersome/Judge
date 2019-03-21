#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

struct troo{
    string identifier;
    vector<troo*> children;
};
vector<troo*> mainList;
string getMain(string inputo){
    int pos =inputo.find('\\');
    return (pos == string::npos) ? inputo :inputo.substr(0,pos);
}
string getRest(string inputo){
    int pos =inputo.find('\\');
    return (pos == string::npos) ? inputo :inputo.substr(pos+1,string::npos);
}
void createMainList(vector<string> inputo){
    string aim;
    vector<vector<string>::iterator> toTake;
    vector<string>::iterator it;

    troo* newTroo;
    while(!inputo.empty()){
        it = inputo.begin();
        aim = getMain(*it);
        newTroo = new troo;
        newTroo->identifier = aim;
        cout << "Aim is : "<<aim<<endl;
        mainList.push_back(new troo())
        for(;it!=inputo.end();it++){
            toTake.clear();
            if(getMain(*it) ==  aim){
                toTake.push_back(it);
                createMainList();
            }
        }
        vector<vector<string>::iterator>::iterator ito = toTake.begin();
        for(;ito!=toTake.end();ito++){
            mainList.erase(*ito);
        }
    }
}
int main(){
    
    int amount = 0;
    cin >> amount;
    vector<string> inputo;
    string tempo;
    for(;amount!=0;amount--){
        cin >> tempo;
        inputo.push_back(tempo);
    }

    return 0;
}

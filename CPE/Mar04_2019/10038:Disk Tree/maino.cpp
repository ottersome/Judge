#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

char tempo;
vector<char> charStr;

unordered_map<string,*estru> dicto;
string toStringo(vector<char> vectoro){
    vector<char>::iterator it = vectoro.begin();
    string resulto = "";
    for(;it!=vectoro.end();it++){
        resulto.append(1,*it);
    }

}
int main(){

    int numCases =0;
    cin >> numCases;
    estru* curPointer;
    bool level = false;
    while(numCases){
        level = false;
        while(cin >> tempo && tempo != '\n'){
            if(tempo =='\\'){//then we have reached a divide
                string esta = toStringo(charStr);
                if(level == false){
                    level =true;
                    if(dicto.find(tempo)!=dicto.end()){
                        dicto[esta] = new unordered_map<string,unordered_map<string,unordered_map>()>();
                        curPointer = dicto[esta];
                        cout << "Pushing new root value : "<<esta<<endl;
                    }
                }else{
                    if(dicto.find(tempo)!=dicto.end()){
                        (*curPointer).value[esta] = new unordered_map<string,estru>();
                        cout << "Pushing new value : "<<esta<<endl;
                    }
                }
            }else{
                charStr.push_back(tempo);
            }
        }
        numCases--;
        cin.get();
    }

    return 0;
}


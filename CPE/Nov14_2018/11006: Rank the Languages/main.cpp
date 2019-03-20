#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

char arrayo[21][21];
bool encountered[21][21];
int abcEncounters[27];
int h;
int w;
void recurso(int i ,int j){
    //recurse down and right
    if(encountered[i][j] == true)
       return;
    else
        encountered[i][j] = true;
    
    printf("Inside (%d,%d)\n",i,j);
    if(i < h-1)
        recurso(i+1,j);
    if(j < w-1)
        recurso(i,j+1);
    bool downSame = false;
    bool rightSame = false;
    char letter = arrayo[i][j];
    //check down
    if(i<h-1  && arrayo[i+1][j] == arrayo[i][j])
        downSame = true;
    //check right
    if(j<w-1  && arrayo[i][j+1] == arrayo[i][j])
        rightSame = true;
    if(!downSame && !rightSame){
        //thenm theres a new state
        printf("At (%d,%d) we have D:%d and R:%d\n",i,j,downSame,rightSame);
        printf("\tLetters us %c\n",arrayo[i][j]);
        abcEncounters[letter-'a']++;
    } 
}
char tempo;
int main(){

    int N = 0;
    cin >> N;
    while(N){
        cout << "Starting new one"<<endl;
        memset(encountered,0,sizeof(bool)*21*21);
        memset(abcEncounters,0,sizeof(int)*27);
        memset(arrayo,'\0',sizeof(arrayo[0][0])*21*21);
        cin >> h >> w;
        for(int i=0;i<h;i++){
            for(int j = 0;j<w;j++){
                cin >> tempo;
                while(tempo == '\n' || tempo == '\0')
                    cin >> tempo;
                arrayo[i][j] = tempo;
                if(arrayo[i][j] == '\n')
                    printf("Puto en %d,%d\n",i,j);
            }
        }
        recurso(0,0);
        for(int i =0;i<27;i++){
            if(abcEncounters[i]!=0)
                printf("We have %d %c\n",abcEncounters[i],'a'+i);
        }
        N--;
    }

    return 0;
}

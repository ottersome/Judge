#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
//make an array of characters that will contain the right anser, thus 120x100 characters
char rightAns[100][121];
using namespace std;
bool isnum(char c){
	if(c>= 48 && c<=57)
		return true;
	return false;
}
int main(){
	//create the loop
	string stringo,stringo2,result = "Accepted";
	vector<char> rightNums;
	vector<char> giveAns;
	int lns,lnsa;
	char inputo[121];
	int caseno =1 ;
	while(getline(cin,stringo) && stringo !="0"){
		fill(rightNums.begin(),rightNums.end(),0);
		fill(giveAns.begin(),giveAns.end(),0);
		stringstream ss(stringo);
		ss >> lns;
		//REMEMBER to use cin.ignore() before getting new line after cin >> 
		//now loop through the lines and get every character inserted into the right ans
		for(int i =0;i<lns;i++){
			cin.getline(rightAns[i],sizeof(rightAns[i]));
			for(int j =0;j<sizeof(rightAns[i]);j++){
				//printf("We are going through %d\n",rightAns[i][j]);
				if(rightAns[i][j] != '\n'){
					if(rightAns[i][j] >= 48 && rightAns[i][j] <= 57){
						rightNums.push_back(rightAns[i][j]);
					}
				}else{
					break;
				}
			}
		}
		getline(cin,stringo);
		ss = stringstream(stringo);
		ss >> lnsa;
			for(int i =0;i<lnsa;i++){
				//print word by word
				cin.getline(inputo,sizeof(inputo));
				for(int j =0;j<sizeof(inputo);j++){
					if(isnum(inputo[j])){
						giveAns.push_back(inputo[j]);
						printf("Inputo is  : %c",inputo[j]);
					}
				}
				//compare strings
				if(string(inputo) != string(rightAns[i]))
					result = "Presentation Error";

			}
			//check the nums
			//printf("Size are %d - %d\n",rightNums.size(),giveAns.size());
			if(rightNums.size() == giveAns.size()){
				for(int i = 0;i<rightNums.size();i++){
					//printf("This are the nums compared: %c vs. %c\n",rightNums[i],giveAns[i]);
					if(rightNums[i] != giveAns[i])
						result = "Wrong Answer";
				}
			}else{
				result = "Wrong Answer";
				printf("Size are %d - %d\n",rightNums.size(),giveAns.size());
			}
		//zero de arrays
		printf("Run #%d: ",caseno++);
		cout << result<<endl;
		result = "Accepted";
	}
	return 0;
}

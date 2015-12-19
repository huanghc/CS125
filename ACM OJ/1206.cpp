#include <iostream>
#include <cstring>
using namespace std;
int main(){
	string pas[5000];
	int num=0,i,s=0,numIf=0,numElse=0;
	int stack[10000]={0};
	while (1){
		getline(cin, pas[num]);			
		if (pas[num]=="") break;
		++num;
	}

	for (i=0;i<num;++i){
		if (pas[i].find("begin")!= -1) {
			stack[s]=1;++s;
		}
		if (pas[i].find("end")  != -1) {
			if (stack[s-1]!=1) {
				cout<< "Error!"; return 0;
			}
			else --s;
		}
		if (pas[i].find("if") != -1) {
			++numIf;stack[s]=3;++s;
		}
		if (pas[i].find("then") != -1) {
			if (stack[s-1]!=3) {
				cout<< "Error!"; return 0;
			}
			else --s;
		}
		if (pas[i].find("else") != -1) {
			++numElse;
			if (numElse>numIf){
				cout<<"Error!";return 0;
			}
		}
    }
    if (s==0) cout<<"Match!";
    else cout<<"Error!";
    return 0;
} 

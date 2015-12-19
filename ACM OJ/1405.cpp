#include <iostream>
#include <cstring>
using namespace std;

int main(){
	string a;
	string name[1000];int index=0;
	while(getline(cin,a)){	
		int len1 = a.length();
		int kong= a.find(" ");		
		int kong2= a.find("hits ");
		

		string tmp2 = a.substr(kong+1,kong2-kong-2); 		cout<<tmp2<<endl;
		name[index]=tmp2;++index;
		string tmp3 = a.substr(kong2+5,len1-kong2);	
		cout<<tmp3<<endl;		

		int kong3=tmp3.find(" for");
		string tmp4 = tmp3.substr(0,kong3);
		cout<<tmp4<<endl;	
	}
}

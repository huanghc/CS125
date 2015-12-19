#include <iostream>
#include <cstring>
using namespace std;
int main(){
	int n,i,j,sumDay=0,sumEnd=0,num_gd=0;
	cin>>n;
	char aa=cin.get();
	string sen[1000];
	string tmp[1000];
	string getday[1000];
	int flag[1000]; 
	for (i=0;i<n;++i) flag[i]=-1;
	
	for (i=0;i<n;++i){		
		getline(cin,sen[i]);
		int len=sen[i].length();
		
		if (sen[i].compare(0,9,"Today is ",0,9)== 0){		
			tmp[i] = sen[i].substr(9,len-10);
			flag[i]=0;
		}
		if (sen[i].compare(0,14,"Yesterday was ",0,14) ==0){	
			tmp[i] = sen[i].substr(14,len-15);
			flag[i]=1;
		}
		if (sen[i].compare(0,17,"Tomorrow will be ",0,17) ==0){	
			tmp[i] = sen[i].substr(17,len-18);
			flag[i]=2;
		}
    }
    
    for (i=0;i<n;++i){
    	int len=sen[i].length();
	    string dayend=sen[i].substr(len-4,3);	
	    bool flag2=true;
        if (flag[i] == 0){				
			for (j=0;j<num_gd;++j){
				if (tmp[i] == getday[j])  flag2 = false;
			}
		}
		
		if (flag[i] == 1){
		    flag2 = false;
			for (int j=0;j<i;++j){
				if (tmp[i] == tmp[j])  flag2 = true;
			}
			for (int j=0;j<num_gd;++j){
				if (tmp[i] == getday[j])  flag2 = false;
			}
		}
		if (flag[i] == 2){
			flag2 = false;
			for (j=i+1;j<n;++j){
				if (tmp[i] == tmp[j])  flag2 = true;
			}
			for (j=0;j<num_gd;++j){
				if (tmp[i] == getday[j])  flag2 = false;
			}
		}
		if (flag2){
			getday[num_gd] = tmp[i];
			++num_gd;
			if (dayend == "day") ++sumDay;
			if (dayend == "end") ++sumEnd;
		}
	}
    cout<<sumEnd+sumDay<<" "<<sumEnd;
}

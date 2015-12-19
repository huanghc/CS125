#include <iostream>
#include <cstring>
using namespace std;
int main(){
	int a,b,c,i,j;
	string name[10];
	string sen[20];
	cin>>a>>b>>c;
	for (i=0;i<a;++i){
		cin>>name[i];
	}
	char aa=cin.get();
	int ret[20]={0};
	
	for (i=0;i<c;++i){
		
		getline(cin,sen[i]);
		int ans[3];
		for (j=0;j<3;++j){
			ans[j]=-1;
		}
		int len=sen[i].length();
		int first=sen[i].find(" ");
		string getName=sen[i].substr(0,first-1);
		
		for (j=0;j<a;++j){
			if (getName==name[j]){
				ans[0]=j;break;
			}			
		}
		
		string rest=sen[i].substr(first+1,len-first-1);
		int second=rest.find(" ");
		string name2=rest.substr(0,second);		
		string afterNam=rest.substr(name2.length()+1,rest.length()-name2.length()-1);
		
		if (name2=="I"){
			if (afterNam=="have the ring."){
				ans[1]=ans[0];ans[2]=1;
			}
			else if (afterNam=="have not the ring."){
				ans[1]=ans[0];ans[2]=2;
			}			
		}
		
		if (afterNam=="has the ring."){
			for (j=0;j<a;++j){
				if (name2==name[j]){
					ans[1]=j;break;
				}			
			}
			ans[2]=1;
		}
		if (afterNam=="has not the ring."){
			for (j=0;j<a;++j){
				if (name2==name[j]){
					ans[1]=j;break;
				}			
			}
			ans[2]=2;
		}

		string today=rest.substr(0,9);
		if (today=="Today is "){
			ans[2]=3;
			string day=rest.substr(9,rest.length()-10);
			if (day=="Monday") ans[1]=1;
			else if(day=="Tuesday") ans[1]=2;
			else if(day=="Wednesday") ans[1]=3;
			else if(day=="Thursday") ans[1]=4;
			else if(day=="Friday") ans[1]=5;
			else if(day=="Saturday") ans[1]=6;
			else if(day=="Sunday") ans[1]=7;			
			else ans[2]=-1;
		}
		
		bool flag=true;
		if (ans[0]==-1 || ans[1]==-1 || ans[2]==-1){
			flag=false;ret[i]=1;
		}
		if (flag){
			for (j=0;j<3;++j){
				cout<<ans[j]<<" ";		
			}
			cout<<endl;
		}		
    }
    
    bool flag=true;
    for (int k=0;k<c;++k){
    	if (ret[k]!=1) flag=false;
	}
	if (flag) cout<<"Orz";
}

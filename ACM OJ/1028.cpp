#include <iostream>
using namespace std;
int main(){
	int word; cin>>word;
	int compare_if=0,compare_then=0,compare_else=0,compare2=0,m=0,n=0,judge=0;	
	string p[word];
	bool flag=true;
	for (int i=0;i<word;++i) cin>>p[i];
	
	for(int i=0; i<word; ++i){		
		if(p[i]=="if"){		
			++compare_if;	
			judge=1;		
		}		
		else {
			if(p[i]=="then"){			
				++compare_then;		
			}		
			else if(p[i]=="else") ++compare_else; 		
			else if(p[i]=="begin") {
				++compare2;
				if (judge==1){
					flag=false;break;
				}
			} 		
			else if(p[i]=="end") --compare2; 
			judge=0;
    	}
    	if(compare_if<compare_else || compare_if<compare_then) flag=false;	
	    if(compare2<0) flag=false;
	}
	if(compare2!=0) flag=false;
	if(compare_if!=compare_then) flag=false;
	if (flag) cout<<"YES";
	else cout<<"NO";
		
    return 0;  
}

#include <iostream>
using namespace std;
int main(){
	int N,i,j,tmp1,tmp2;
	cin>>N;
	int spare=0,work=0;
	bool flag=true;
	struct hourT{
		int start,end;
	};
	hourT hour[5000];
	for (i=0;i<N;++i){
		cin>>hour[i].start>>hour[i].end;
	}
	for (i=1;i<N;++i){
        flag = false;
        for (j=0;j<N-i;++j)
            if (hour[j+1].start<hour[j].start){
                tmp1 = hour[j].start; hour[j].start = hour[j+1].start; hour[j+1].start = tmp1; 
				tmp2 = hour[j].end; hour[j].end = hour[j+1].end; hour[j+1].end = tmp2; 
				flag = true;}
        if (!flag) break;
    }
    
    int m=hour[0].start;int n=hour[0].end;
    for (i=0;i<N-1;++i){   	
    	if (n<hour[i+1].start){
    		if (n-m>work){
    			work=n-m;
			}			
    		if ((hour[i+1].start-n)>spare){
    			spare=(hour[i+1].start-n);  			
			}
			n=hour[i+1].end;m=hour[i+1].start;			
		}
		else {
			if (n<hour[i+1].end) n=hour[i+1].end;
		}
	}
	if (n-m>work){
		work=n-m;
	}
	cout<<work<<" "<<spare;
	return 0;
}

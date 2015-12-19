#include <iostream>
using namespace std;
void bubble_sort(double k[],int n);

int main(){
	int n,i,j,sum=2;cin>>n;
	int s[700][2];

	
	for (i=0;i<n;++i){
		s[i][0]=0;s[i][1]=0;
		cin>>s[i][0]>>s[i][1];
	}
	
	for (i=0;i<n-1;++i){
	    int sum2=2,num_k=0;
		double k[800];	
		for (j=i+1;j<n;++j){			
			if (s[j][0]==s[i][0]){
				k[num_k]=32767;
			}
			else {
				double a=double(s[j][1]-s[i][1]);
				double b=double(s[j][0]-s[i][0]);
				k[num_k]=a/b;
			}
			++num_k;	  
	    }
	    
		bubble_sort(k,num_k);
		
		for (int s=0;s<num_k;++s){
			if (k[s]==k[s+1]) {
				++sum2;				
			}			
			else sum2=2;
			if (sum2>sum) sum=sum2;
		}	
			
	}	
	cout<<sum;
	return 0;
} 

void bubble_sort(double k[],int n){
	for (int i=1; i<n; ++i){
        bool flag = false;
        for (int j=0; j<n-i; ++j)
            if (k[j+1] < k[j])
                {double tmp = k[j]; k[j] = k[j+1]; k[j+1] = tmp; flag = true;}
        if (!flag) break;
    }
} 

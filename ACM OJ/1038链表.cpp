#include <iostream>
using namespace std;
struct  node{ 
    int data;     
    node  *next;
};
int main(){ 
    node *head, *p, *q;         
    int n,i,tmp=0;
	int num[10000]; 
    cin >> n;
    for (i=0;i<n-1;++i){
    	cin>>num[i];
    	num[i]=num[i]%n; 
	}
    head = p = new node;        
    p->data = 1; 
    for (i=1; i<n; ++i) {
        q = new node;               
        q->data =i+1; 
        p->next = q;  
		p = q;           
    }
    p->next = head;   
    q=head;                            
    while (q->next != q) {  
	    for (i=0;i<num[tmp]-1;++i){	    	
			p = p->next;				
		}  
		++tmp;  
	    q = p->next ;
        p->next = q->next;              
        //cout << q->data << '\t';       
        delete q;	                     
        q=p->next;                
    }
    cout << q->data;

}


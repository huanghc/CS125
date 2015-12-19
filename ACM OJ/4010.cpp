#include <iostream>
using namespace std;

struct kidT
{	int num;
	kidT *before;
	kidT *next;	
}; 

int main()
{	int n,min=1000000,m=0;	
	cin >> n;	
    int input[n];
	for (int i=0;i<n;++i)
	{	cin >> input[i];
		if (min > input[i]) min = input[i];
	}
	for (int i=0;i<n;++i){
		input[i] -= min;
	}
	
	kidT *head= new kidT,*p= new kidT,*q= head;
	head->next = p;
	head->before = NULL;
	
	for (int i=0;i<n;++i)
	{	p->before = q;		
		p->num = i;
		
		q = p;
		p = new kidT;
		q->next = p;
	} 

	p = head->next;
	p->before = q;
	q->next = p;
	p = head->next;
	
	while (m < n-1)
	{	--input[p->num];
		if (input[p->num] == -1) 
		{	q = p->before;
			q->next = p->next;
			q = p->next;
			q->before = p->before;	
			++m;
			
			min=1000000;
			for (int j=0;j<n-m;++j)
			{	if (min > input[q->num]){
					min = input[q->num];
				}
				q = q->next;
			}
			for (int j=0;j<n-m;++j)
			{	input[q->num] -= min;
				q = q->next;
			}
		}
		
		if (m%2){
			p=p->before;
		} 	
		else p=p->next;
	}
	cout <<p->num+1;
	return 0;
} 

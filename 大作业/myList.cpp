#include<iostream>
using namespace std;

template<class T>class MyList;
// redefine operator list + list
template<class T>
MyList<T> operator+ (const MyList<T> &l1, const MyList<T> &l2){
	MyList<T> tmp; 
	int q1=l1.lenth,q2=l2.lenth;
	tmp.a=new T[q1+q2];
	tmp.lenth=q1+q2;
	tmp.size=q1+q2;
	for (int i=0;i<q1;++i){
		tmp.a[i]=l1.a[i];
	}
	for (int i=q1;i<q1+q2;++i){
		tmp.a[i]=l2.a[i-q1];
	}
	return tmp;
}                                      

// redefine operator list + item 
template<class T>
MyList<T> operator + (const MyList<T> &l1, const T &item){
	MyList<T> tmp;
	tmp.a=new T[l1.lenth+1];
	tmp.lenth=l1.lenth+1;
	for (int i=0;i<l1.lenth;++i){
		tmp.a[i]=l1[i];
	}
	tmp.a[tmp.lenth-1]=item;
	return tmp;
}

// redefine operator << 
template<class T>
ostream & operator<<(ostream &os, const MyList<T> &obj){
	os<<'[';
	for (int i=0;i<obj.lenth-1;++i){
		os<<obj.a[i]<<',';
	}
	if (obj.lenth>=1) os<<obj.a[obj.lenth-1];
	os<<']';
	return os;
};

template<class T>
class MyList{
friend ostream & operator << <>(ostream &, const MyList<T> &);
friend MyList<T> operator + <>(const MyList<T> &, const MyList<T> &); 
friend MyList<T> operator + <>(const MyList<T> &, const T &); 

private:
	T *a;
	int size;
	int lenth;
	
	// double size when lenth > size
	void double_space(){
		T *a2;
		a2 = new T [lenth];
		for (int i=0;i<lenth;++i){
			a2[i]=a[i];
		}
		delete [] a;		
		size*=2;
		a=new T[size];
		for (int i=0;i<lenth;++i){
			a[i]=a2[i];
		}
		delete []a2;
	};

public:
	//four initialize functions 
	MyList(){
		size = 100;
		a = new T [size];
		lenth=0;
	}
	MyList(int num, const T &item){
		size=num;
		lenth=num;
		a= new T [size];
		for(int i=0;i<size;++i){
			a[i]=item;
		}
	};
	MyList(const MyList &l){
		size=l.lenth;
		lenth=l.lenth;
		a = new T [size];
		for (int i=0;i<size;++i){
			a[i]=l.a[i];
		}
	};
    MyList(T* arr, int len){
		size=len;
		lenth=len;
		a = new T [size];
		for (int i=0;i<len;++i){
			a[i]=arr[i];
		}
	};
	
    //push an item into the list
	void push(const T &item){
	    if (lenth>=size) double_space();	
		a[lenth]=item;
		++lenth;	
	};
	
	//pop the last item
	T pop(){
		try { 		
		if (lenth == 0) throw 1;
		T b=a[lenth-1];
		--lenth;
		return b;
	    }
	    catch (int) {
	    	cout << "The list doesn't have any elements.";
	    	exit(-1);
	    }		
	};
	
	//insert the item
	void insert(int index, const T &item){
		try {
			if (index>=lenth) throw 1;
			if (lenth==size) double_space();
			for (int i=lenth-1;i>=index;--i){
				a[i+1]=a[i];
			}
			a[index]=item;
			++lenth;
		}
		catch (int) {cout<<"out of range"<<endl;exit(-1);}
	};
	
	//clean a list to null
	void clean(){
		lenth=0;
		size=0;
		delete [] a;
		a = new T[0];
	};
	
	//get the size of the list
	int get_size(){
		return lenth;
	};
	
	//erase a part of the list
	void erase(int start, int end){
		try {
			if (start>end || end>=lenth) throw 1;
			for (int i=end+1;i<lenth;++i){
				a[i-(end-start+1)]=a[i];
			}
			lenth=lenth-end+start-1;
		}
		catch (int) {cout<<"out of range"<<endl;exit(-1);}		
	}; 
	
	//get an item from the list
	T get_item(int index){
		try {
			if (index>lenth) throw 1;
			else return a[index];		
		}
		catch (int) {cout<<"out of range"<<endl;exit(-1);}				
	};
	
	//get a part of the list
	MyList get_item(int start, int end){
		if (start<0) start=lenth+start;
		if (end<0) end=lenth+end;
        try {
	        if (end>=lenth || start>end) throw 1;
		}
		catch (int) {cout<<"out of range"<<endl;return *this;}		
		MyList tmp;
		if (end<start) {
			tmp.lenth=0;
			tmp.a = new T [1];
			tmp.a[0]=NULL;
			return tmp;
		}
	    
		tmp.lenth=end-start+1;
		tmp.size=end-start+1;
		tmp.a= new T [lenth];
		for (int i=0;i<tmp.lenth;++i){
			tmp.a[i]=a[start+i];
		}
		return tmp;
	};
	
	//count how many times the item appears
	int count(const T &item){
		int tmp=0;
		for (int i=0;i<lenth;++i){
			if (item==a[i]) ++tmp;
		}
		return tmp;
	};
	
	//remove the first appearance of the item
	void remove(const T &item){
		int tmp;
		for (int i=0;i<lenth;++i){
			if (item==a[i]) {
				tmp=i;break;
			}
		}
		for (int i=tmp;i<lenth;++i){
			a[i]=a[i+1];
		}
		--lenth;
	};

    //redefine the operator =
	MyList &operator = (const MyList &l){
		if (this == &l) return *this;
		lenth=l.lenth;
		size=l.lenth;
		delete [] a;
		a=new T[l.lenth];
		for (int i=0;i<l.lenth;++i){
			a[i]=l.a[i];		
		}
		return *this;
	};
	
	//redefine the operator list += item
	MyList &operator += (const T &item){		
		++lenth;
		if (lenth<=size) double_space();
		a[lenth-1]=item;
		return *this;
	};
	
	//redefine the operator list += list2
	MyList &operator += (const MyList &l){		
		int q1=l.lenth;
		lenth+=q1;
	    while (lenth>=size) double_space();
		for (int i=lenth-q1;i<lenth;++i){
			a[i]=l.a[i-lenth+q1];
		}
		return *this;
	};
	
	//redefine the operator [] 
	T &operator [](int index){
		try  {
			if (index>=lenth-1) throw 1;
			else return a[index];
		}
		catch (int) {cout<<"out of range"<<endl;exit(-1);}		
	};
	
	//merge sort the list  
	void merge(T a[], int p, int q, int r){   
	    int n1 = q-p+1;  
	    int n2 = r-q;  
	    T *L = new T[n1];  
	    T *R = new T[n2];  
	    int i,j,k;  
	    for (i=0; i<n1; ++i){  
	        L[i] = a[p+i];  
	    }  
	    for (j=0; j<n2; ++j){  
	        R[j] = a[q+j+1];  
	    }
	    
		i=0;j=0;k=p;   
	    while (i < n1 && j < n2){       
	        if (L[i] <= R[j]){
	        	a[k] = L[i]; ++i;
			}               
	        else{
	        	a[k] = R[j]; ++j;
			}            			
			++k; 
	    }  
	      
	    while (i < n1){
	    	a[k++] = L[i++];
		}  
	                
	    while (j < n2){
	    	a[k++] = R[j++];
		}           
	}  
	  
	void mergeSort1(T a[], int p, int r){    
	    if (p<r){       
	        int q = (p+r)/2;  
	        mergeSort1(a, p, q);  
	        mergeSort1(a, q+1, r);  
	        merge(a, p, q, r);  
	    }  
	}
	
	//reverse the list
	void reverse(){
		for (int i=0;i<lenth/2;++i){
			T p=a[i];
			a[i]=a[lenth-i-1];
			a[lenth-i-1]=p;
		}	
	}; 	
	
	//merge sort the list
	void sort(bool less=true){
		mergeSort1(a,0,lenth-1);
		if (!less){
		    reverse();
		}		
	};
    
    //delete []
	~MyList(){delete [] a;}
};
	
int main(){
	MyList<int> a, b;
	int i;
	for (i=0; i<5; ++i)
		a.push(i);
    cout<<"push:\t\t\ta="<<a<<endl;
	a[3] = 15; cout<<"a[3]=15:\t\t\ta="<<a<<endl;
	a.sort(); cout<<"sort:\t\t\ta="<<a<<endl;
	a.reverse(); cout<<"reverse:\t\t\t"<<a<<endl;
	a += 12; cout<<"+=:\t\t\t"<<a<<endl;
//	for (i=0; i<a.get_size(); ++i)
//		cout<<a[i]<<endl;
    b = a.get_item(4, -3); cout<<"get_item:\t\t\tb="<<b<<endl;
	b = a.get_item(3, -1); cout<<"get_item:\t\t\tb="<<b<<endl;	
	a += b; cout<<"a+=b:\t\t\ta="<<a<<endl;
//	for (i=0; i<a.get_size(); ++i)
//		cout<<a.get_item(i)<<endl;
	cout<<a.count(5)<<endl;
	b.clean();
	cout<<"claen:\t\t\tb="<<b<<endl; 
	cout<<"get_size b:\t\t\t"<<b.get_size()<<endl;
	a.erase(2, 6);  
	cout<<"erase a:\t\t\t"<<a<<endl;
	b = a+a; 
	cout<<"b=a+a:\t\t\tb="<<b<<endl;
	b.insert(3, 116); 
	cout <<"b.insert(3, 116):\t\t\tb="<<b<< endl;
	b.remove(4); 
	cout<<"b.remove(4):\t\t\tb="<<b<<endl;
	MyList<double> c(10, 3.14);
	cout<<"c:\t\t\t"<<c<<endl;
	for (i=0; i<100; ++i)
		c.push(1.1*i);	
	cout<<"get_item:\t\t\tc="<<c.get_item(100, 105)<<endl;
//  the index out of range
//	a[100]=15;       
//	b = a.get_item(3,18);   
//	a.erase(2, 96);
//	b.insert(20, 116);   
	return 0;
}




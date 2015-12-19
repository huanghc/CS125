void Mylist::double_space(){
	Mylist tmp;
	tmp.a=new T [size];
	for (int i=0;i<size;++i){
		tmp.a[i]=a[i];
	}
	a=new T[2*size];
	for (int i=0;i<size;++i){
		a[i]=tmp.a[i];
	}
	delete [] tmp;
}

MyList(int num, const T &item){
	size=num;
	a= new T [size];
	for(int i=0;i<size;++i){
		a[i]=item;
	}
}

MyList(const MyList &l){
	size=l.size;
	a = new T [size];
	for (int i=0;i<size;++i){
		a[i]=l.a[i];
	}
}

MyList(T* arr, int len){
	size=len;
	a = new T [size];
	for (int i=0;i<len;++i){
		a[i]=arr[i];
	}
}

void push(const T &item){	
	a[size]==item;
	++size;	
}

T pop(){
	T b=a[size-1];
	--size;
	return b;
}

void insert(int index, const T &item){
	for (int i=size-1;i>index;--i){
		a[i+1]=a[i];
	}
	a[index]=item;
	++size;
}

void clean(){
	size=0;
	delete [] a;
}

int get_size(){
	return MyList::size;
}

void erase(int start, int end){
	for (i=end+1;i<size;++i){
		a[i-(end-start+1)]=a[i];
	}
}

T get_item(int index){
	if (index>size) {
		cout<<"xiabiaoyuejie";exit(-1);
	}
	return a[index];
}

MyList get_item(int start, int end){
	if (start<0) start=size+start;
	if (end<0) end=size+end;
	
	Mylist tmp;
	if (end<start) {
		tmp.size=0;
		return tmp;
	}

	tmp.size=end-start+1;
	tmp.a= new T [size];
	for (int i=0;i<size;++i){
		tmp.a[i]=a.[start+i];
	}
	return tmp;
}

int count(const T &item){
	int tmp=0;
	for (int i=0;i<size;++i){
		if (item==a.[i]) ++tmp;
	}
	return tmp;
}

void remove(const T &item){
	int tmp;
	for (int i=0;i<size;++i){
		if (item==a.[i]) {
			tmp=i;break;
		}
	}
	for (int i=tmp;i<size;++i){
		a[i]=a[i+1];
	}
	--size;
}

MyList operator + (const MyList &l1, const MyList &l2){
	Mylist tmp; 
	int q1=l1.size,q2=l2.size;
	tmp.a=new T[q1+q2];
	tmp.size=q1+q2;
	for (int i=0;i<q1;++i){
		tmp.a[i]=l1[i];
	}
	for (int i=q1;i<q1+q2;++i){
		tmp.a[i]=l2[i-q1];
	}
	return tmp;
}

MyList operator + (const MyList &l1, const T &item){
	Mylist tmp;
	tmp.a=new T[l1.size+1];
	tmp.size=l1.size+1;
	for (int i=0;i<l1.size;++i){
		tmp.a[i]=l1[i];
	}
	tmp.a[tmp.size-1]=item;
	return tmp;
}
	
MyList &operator = (const MyList &l){
	if (this == &l) return *this;
	detele [] a;
	a=new T[l.size];
	size=l.size;
	for (int i=0;i<size;++i){
		a[i]=l[i];
	}
	return *this;
}

MyList &operator += (const T &item){
	++size;
	a[size]==item;
	return *this;
}

MyList &operator += (const MyList &l){
	int q1=l.size;
	size+=q1;
	for (int i=size-q1;i<size;++i){
		a[i]=l2[i-q1];
	}
	return *this;
}

T &operator [](int index){
	if (index>size) {
		cout<<"xiabiaoyuejie";exit(-1);
	}
	return a[index];
}

ostream & operator<<(ostream &os, const MyList &obj){
	os<<'[';
	for (int i=0;i<obj.size;++i){
		os<<obj.a[i]<<',';
	}
	os<<']';
}

void reverse(){
	for (int i=0;i<size/2;++i){
		T p=a[i];
		a[i]=a[size-i-1];
		a[size-i-1]=p;
	}	
}

void merge(T a[], int p, int q, int r){   
    int n1 = q-p+1;  
    int n2 = r-q;  
    T *L = new int[n1];  
    T *R = new int[n2];  
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

void sort(bool less=true){
	if (less){
		mergeSort1(a,0,size-1);
	}
}
 

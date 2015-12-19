#include <iostream>
#include <cstring>

using namespace std;
int clk[9];
int klc[9];
int minn=100;
int k[9]={0};
int ans[9]={0};
void try1(int i);
void try2(int i);
void try3(int i);
void try4(int i);
void try5(int i);
void try6(int i);
void try7(int i);void try8(int i);void try9(int i);
int main(){	
	int i,j,i1,i2,i3,i4,i5,i6,i7,i8,i9;
	for (i=0;i<9;++i){
		cin>>clk[i];
		klc[i]=clk[i];
	}
	for (i1=0;i1<4;++i1){
		try1(i1);
		for (i2=0;i2<4;++i2){
			try2(i2);
			for (i3=0;i3<4;++i3){
				try3(i3);
				for (i4=0;i4<4;++i4){
					try4(i4);
					for (i5=0;i5<4;++i5){
						try5(i5);
						for (i6=0;i6<4;++i6){
							try6(i6);
							for (i7=0;i7<4;++i7){
								try7(i7);
								for (i8=0;i8<4;++i8){
									try8(i8);
//									cout<< "8: ";
//											for (i=0;i<9;++i){
//												cout<< clk[i];
//											}
//											cout<<endl;
									for (i9=0;i9<4;++i9){
										try9(i9);
										bool flag=true;
										int cal=0;
//										cout<< endl;
//										cout<< "9: ";
//											for (i=0;i<9;++i){
//												cout<< clk[i];
//											}
//											cout<<endl;
										for (i=0;i<9;++i){
											cal+=k[i];
											if((clk[i]%12)!=0){
												flag=false;break;
											}
										}
										if (flag){
											if (cal<minn){
												minn=cal;
												for(j=0;j<9;++j){
													ans[j]=k[j];
												}												
											}
										}
										clk[8]-=3*i9;
										clk[7]-=3*i9;
										clk[4]-=3*i9;
										clk[5]-=3*i9;										
									}
										clk[6]-=3*i8;
										clk[7]-=3*i8;
										clk[8]-=3*i8;
								}
									clk[6]-=3*i7;
									clk[7]-=3*i7;
									clk[3]-=3*i7;
									clk[4]-=3*i7;
							}
								clk[2]-=3*i6;
								clk[5]-=3*i6;
								clk[8]-=3*i6;
						}
							clk[1]-=3*i5;
							clk[3]-=3*i5;
							clk[5]-=3*i5;
							clk[4]-=3*i5;
							clk[7]-=3*i5;
					}
						clk[0]-=3*i4;
						clk[6]-=3*i4;
						clk[3]-=3*i4;
				}
					clk[2]-=3*i3;
					clk[1]-=3*i3;
					clk[5]-=3*i3;
					clk[4]-=3*i3;
			}
				clk[0]-=3*i2;
				clk[1]-=3*i2;
				clk[2]-=3*i2;
		}
			clk[0]-=3*i1;
			clk[1]-=3*i1;
			clk[3]-=3*i1;
			clk[4]-=3*i1;
	}
	for (i=0;i<9;++i){
		for (j=0;j<ans[i];++j){
			cout<<i+1<<" ";
		}
	}
} 

void try1(int i){
	clk[0]=(clk[0]+3*i);
	clk[1]=(clk[1]+3*i);
	clk[3]=(clk[3]+3*i);
	clk[4]=(clk[4]+3*i);
	k[0]=i;
}

void try2(int i){
	clk[0]=(clk[0]+3*i);
	clk[1]=(clk[1]+3*i);
	clk[2]=(clk[2]+3*i);
	k[1]=i;
}

void try3(int i){
	clk[2]=(clk[2]+3*i);
	clk[1]=(clk[1]+3*i);
	clk[5]=(clk[5]+3*i);
	clk[4]=(clk[4]+3*i);
	k[2]=i;
}

void try4(int i){
	clk[0]=(clk[0]+3*i);
	clk[6]=(clk[6]+3*i);
	clk[3]=(clk[3]+3*i);
	k[3]=i;
}

void try5(int i){
	clk[1]=(clk[1]+3*i);
	clk[3]=(clk[3]+3*i);
	clk[5]=(clk[5]+3*i);
	clk[4]=(clk[4]+3*i);
	clk[7]=(clk[7]+3*i);
	k[4]=i;
}

void try6(int i){
	clk[2]=(clk[2]+3*i);
	clk[5]=(clk[5]+3*i);
	clk[8]=(clk[8]+3*i);
	k[5]=i;
}

void try7(int i){
	clk[6]=(clk[6]+3*i);
	clk[7]=(clk[7]+3*i);
	clk[3]=(clk[3]+3*i);
	clk[4]=(clk[4]+3*i);
	k[6]=i;
}

void try8(int i){
	clk[6]=(clk[6]+3*i);
	clk[7]=(clk[7]+3*i);
	clk[8]=(clk[8]+3*i);
	k[7]=i;
}

void try9(int i){
	clk[8]=(clk[8]+3*i);
	clk[7]=(clk[7]+3*i);
	clk[4]=(clk[4]+3*i);
	clk[5]=(clk[5]+3*i);
	k[8]=i;
}

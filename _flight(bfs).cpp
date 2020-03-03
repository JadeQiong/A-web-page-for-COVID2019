#include<iostream>
using namespace std;
int n,m,x0,x;
int ans = 99999999;

struct p {
	int num;//current 
	int s;//times 
};

p que[2501]={}; 
int a[50][50]={};
int book[50]={};


int main(){
	cin >>n>>m;
	cin>>x0>>x;	
	for(int i=1;i<=n;i++)
	for(int j=1;i<=n;j++){
	if(i== j) a[i][j] = 0;
	else a[i][j]= 99999999;}
	 
	int flag =0;
	for(int i=1;i<=m;i++){
	int j,k;
	cin >> j>>k;
	a[j][k] = 1;
	a[k][j] = 1;	
	}
	
	int head =1;
	int tail =1;
	que[tail].num=x0;
	que[tail].s=0;
	tail++;
	book[x0] = 1;
	
	
	while(head< tail){
		int temp = que[head].num;
		for(int i=1;i<= n;i++){
			if(book[i]== 0 && a[temp][i]!= 99999999){
				book[i] = 1;
				que[tail].s = que[head].s+1;
				que[tail].num=i;
				tail++;	
			}
			if(que[tail-1].num==x)
			{
				flag=1;
				break;
			}
		}
		if(flag)
			break;
		head++;
	} 
	cout<<que[tail-1].s<<endl;
} 

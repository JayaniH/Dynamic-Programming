#include<iostream>
#include<stdlib.h>

using namespace std;

void subsetSum(int subset[],int len,int sum){
	
	int table[len+1][sum+1];
	
	for(int i=0;i<len+1;i++){
		for(int j=0;j<sum+1;j++){
			
			if(j==0){
				table[i][j] = 1;
			}
			else if(i==0){
				table[i][j] = 0;
			}
			else{
				if(j-subset[i-1]>=0){
					table[i][j] = table[i-1][j] || table[i-1][j-subset[i-1]]; 
				}else{
					table[i][j] = table[i-1][j];
				}
			}
		}
	}
	
	if(table[len][sum]){
		cout<<"TRUE";
	}else{
		cout<<"FALSE";
	}
	cout<<"\nTable: \n";
	for(int i=0;i<len+1;i++){
		for(int j=0;j<sum+1;j++){
			cout<<table[i][j]<<"  ";
		}
		cout<<endl;
	}
}

int main(){
	int subset[] = {1,4,9,2};
	int len = sizeof(subset)/sizeof(subset[0]);
	int sum = 8;
	subsetSum(subset,len,sum);
}

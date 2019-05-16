#include<iostream>
#include<string>
#include<algorithm>
#include <iterator>
using namespace std;

void calculate(int s, int val[]){
	int optimal[s+1];
	int cut[s+1];
	int max;
	int n=s;

	optimal[0] =0;
	cut[0] = 0;
	
	cout<<"Rod length = "<<s<<endl;
	
	for(int i=1;i<=s;i++){
		max = val[1] + optimal[i-1];
		cut[i] = 1;
		for(int j=2;j<=i;j++){
			if(max < val[j] + optimal[i-j]){
				max = val[j] + optimal[i-j];
				cut[i] = j;
			}
		}
		optimal[i]= max;
	}
	cout<<"Maximum value = "<<optimal[s]<<endl;
	
	cout<<"Cuts: "<<endl;
	
	while(n>0){
		cout<<cut[n]<<" ";
		n = n-cut[n];
	}
	
	//additional-print out the calcuted values
	cout<<endl<<endl;
	cout<<"Optimal value and first cut size:"<<endl;
	cout<<"size\t";
	for (int i=1;i<=s;i++){
		cout<<i<<"\t";
	}
	cout<<endl;
	cout<<"opt val\t";
	for (int i=1;i<=s;i++){
		cout<<optimal[i]<<"\t";
	}
	cout<<endl;
	cout<<"1st cut\t";
	for (int i=1;i<=s;i++){
		cout<<cut[i]<<"\t";
	}
	cout<<endl<<endl;

}
void display(int val[], int len){

	cout<<"values for individual sizes:"<<endl;
	cout<<"size\t";
	for (int i=1;i<len;i++){
		cout<<i<<"\t";
	}
	cout<<endl;
	cout<<"val\t";
	for (int i=1;i<len;i++){
		cout<<val[i]<<"\t";
	}
	cout<<endl<<endl;
}

int main(){
	int val[9] = {0,1,5,8,9,10,17,17,20};
	int len = sizeof(val)/sizeof(int);
	display(val,len);
	calculate(8,val);
}

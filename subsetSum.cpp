#include<iostream>
using namespace std;

bool subsetSum(int arr[], int sum, int size){
//	int size = sizeof(arr)/sizeof(int);
	bool table[size+1][sum+1];
	
	cout<<"Sum = "<<sum<<endl;
	
	for(int i=0;i<=size;i++){
		for(int j=0;j<=sum;j++){
			if(j==0){
				table[i][j] = true;
			}
			else if(i==0){
				table[i][j] = false;
			}
			else{
				if(j<arr[i-1]){
					table[i][j] = table[i-1][j];
				}
				else{
					table[i][j] = table[i-1][j] || table[i-1][j-arr[i-1]];
				}
			}
		}
	}
	//print table
	cout<<endl;
	for(int i=0;i<=size;i++){
		for(int j=0;j<=sum;j++){
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return table[size][sum];
}

int main(){
	int set[]= {3, 34, 4, 12, 5, 2};
	int size = sizeof(set)/sizeof(int);
	
	cout<<"Set: "<<endl;
	for(int i=0;i<size;i++){
		cout<<set[i]<<" ";
	}
	
	cout<<endl;
	if(subsetSum(set,9,size)){
		cout<<"Subset exists"<<endl;
	}
	else{
		cout<<"Subset does not exist"<<endl;
	}
}

#include <iostream>
#include <stdlib.h>

using namespace std;

const int MAX = 10;

class rod{
	private:
		int length;
		int priceForLength[MAX];
		int MaxCostForLength[MAX];
		int backtrackPrice[MAX];
		friend int max(int,int);
	public:
		rod(int len);
		void setPrices();
		int maxProfit();
		void calculateCuts();
};

rod::rod(int len){
	length = len;
}

void rod::setPrices(){
	cout<<"length  Value"<<endl;
	
	for(int i=1;i<=length;i++){
		cout<<"  ";
		cout<< i;
		cout<<"\t ";
		cin>>priceForLength[i];
	}
}

int rod::maxProfit(){
	
	int maxValue;
	int testValue;
	
	for(int i=1;i<=length;i++){
		
		maxValue = 0;
		testValue = 0;
		for(int k=1;k<=i;k++){
			maxValue = max(maxValue, priceForLength[k] + MaxCostForLength[i-k]);
			if(maxValue!= testValue){
				backtrackPrice[i] = k;
			}
			testValue = maxValue;
		}
		MaxCostForLength[i] = maxValue;
	}
	
	return MaxCostForLength[length];
}

void rod::calculateCuts(){
	int i = length;
	
	cout<<"Lengths of pieces to be cut into: ";
	
	while(i != 0){
		cout<<backtrackPrice[i];
		cout<<"\t";

		i -= backtrackPrice[i];
	}
}

int max(int num1, int num2){
	return (num1>num2)? num1 : num2;
}

int main(){
	int len;
	cout<<"Enter rod length: ";
	cin>>len;
	rod myrod(len);
	myrod.setPrices();
	int x = myrod.maxProfit();
	cout<<"\nMax Profit: ";
	cout<<x<<endl;
	myrod.calculateCuts();
	
}


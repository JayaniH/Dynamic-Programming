#include <iostream>
#include<stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

class lcs{
	private:
		string string1;
		string string2;
		
	public:
		void claculateLcs();
		friend int max(int,int);
		
};

void lcs::claculateLcs(){
	cout<<"Enter string 1: ";
	cin>>string1;
	cout<<"Enter string 2: ";
	cin>>string2;
	
	int lenString1 = string1.size();
	int lenString2 = string2.size();
	
	int array[lenString1+1][lenString2+1];
	int printArray[lenString1+1][lenString2+1];
	
	for(int i=0;i<lenString1+1;i++){
		array[0][i] = 0;
	}
	for(int i=0;i<lenString2+1;i++){
		array[i][0] = 0;
	}
	for(int i=0;i<lenString1;i++){
		for(int j=0;j<lenString2;j++){
			if(string1[i] == string2[j]){
				array[i+1][j+1] = 1 + array[i][j];
				
				printArray[i+1][j+1] = 3;		// 3-Black(common element) 2-gray(derived from black) 1-white
			}else{
				array[i+1][j+1] = max(array[i][j+1],array[i+1][j]);
				
				if(printArray[i][j+1]==3||printArray[i+1][j]==3){
					printArray[i+1][j+1] = 2;
				}else{
					printArray[i+1][j+1] = 1;
				}
			}
		}
	}	
	cout<<"\nLCS length: "<<array[lenString1][lenString2];
	
	//Print LCS
	
	string result = "";

	for(int i=lenString1;i>0;i--){
		for(int j=lenString2;j>0;j--){
			if(printArray[i][j]==3){	// If (i,j) is black then move to (i-1,j-1)
				result = result + string1[i-1];
				//cout<<"\n"<<string1[i-1]<<"\t";
				i--;
			}else if(printArray[i][j]==2){		
				if(printArray[i-1][j]==3){	//If (i,j) is gray and if (i-1,j) is black move to (i-1,j)
					i--;
					j++;
				}
			}
			// Else loop backwards until a gray is found
		}
	}	
	reverse(result.begin(),result.end());
	cout<<endl<<"LCS = "<<result;
	
}


int max(int a,int b){
	return (a>b)? a : b;
}

int main(){
	lcs str;
	str.claculateLcs();
}

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

class minEditDistance{
	private:
		string string1,string2;
		int lenString1,lenString2;
	public:
		minEditDistance(string,string);
		void calculateMED();
		friend int min(int,int);
};

minEditDistance::minEditDistance(string s1,string s2){
	string1 = s1;
	string2 = s2;
	lenString1 = s1.length();
	lenString2 = s2.length();
}

void minEditDistance::calculateMED(){
	
	int table[lenString1+1][lenString2+1];
	
	for(int i=0;i<lenString1+1;i++){
		for(int j=0;j<lenString2+1;j++){
			
			if(i==0){
				table[i][j]=j;
			}
			else if(j==0){
				table[i][j]=i;
			}
			else if(string1[i-1]==string2[j-1]){
				table[i][j]=table[i-1][j-1];
			}
			else{
				table[i][j]=1 + min(min(table[i][j-1],table[i-1][j]),table[i-1][j-1]);
			}
		}
	}
	cout<<"Minimum Edit Distance: "<<table[lenString1][lenString2];
	
}

int min(int a,int b){
	return (a<b)? a : b;
}

int main(){
	minEditDistance strings("choco","coco");
	strings.calculateMED();
}

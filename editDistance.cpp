#include <iostream>
#include <string>
using namespace std;

class Distance{
	private:
		string s1,s2;
		int l1,l2;
		int table[25][25];
	public:
		Distance(string str1, string str2);
		void editDistance();
		int min (int x, int y, int z);
		void print();
};

Distance::Distance(string str1, string str2){
	s1=str1;
	s2=str2;
	l1=s1.length();
	l2=s2.length();
}

void Distance::editDistance(){
	
	for(int i=0;i<=l1;i++){
		for(int j=0;j<=l2;j++){
			if(i==0){
				table[i][j] = j;
			}
			else if(j==0){
				table[i][j] = i;
			}
			else if(s1[i-1] == s2[j-1]){
				table[i][j] = table[i-1][j-1];
			}
			else{
				table[i][j] = 1+ min(table[i-1][j],table[i-1][j-1],table[i][j-1]);
			}
		}
	}
	cout<<"Minimum Edit Distance = "<<table[l1][l2]<<endl;
}

int Distance::min(int x, int y, int z){
	int min = x;
	if(y<min){
		min = y;
	}
	if(z<min){
		min =z;
	}
	return min;
}

void Distance::print(){
	cout<<endl;
	for(int i=0;i<=l1;i++){
		for(int j=0;j<=l2;j++){
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int main(){
	Distance d1("saturday","sunday");
	d1.editDistance();
	d1.print();
}

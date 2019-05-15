#include<iostream>
#include <string>
using namespace std;

class LCS{
	private:
		string s1, s2;
		int n,m;
		int length[25][25];
		char direction[25][25];
		char str[25];
		int len;
	public:
		LCS(string str1, string str2);
		void lcs_length();
		void lcs_print();
		int max(int x, int y);
		void print_direction();
		void print_length();
	
};

LCS::LCS(string str1, string str2){
	s1=str1;
	s2=str2;
	n=str1.length();
	m=str2.length();
}
void LCS::lcs_length(){
	
	//cout<<"\n"<<s1<<"\n"<<s2<<endl;
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0 || j==0){
				length[i][j]=0;
				direction[i][j]='0';
			}
			else if(s1[i-1] == s2[j-1]){
				length[i][j]=length[i-1][j-1] +1;
				direction[i][j]='d';
			}
			else{
				length[i][j] = this->max(length[i][j-1],length[i-1][j]);
				if(length[i][j-1]>length[i-1][j]){
					direction[i][j]='l';
				}
				else{
					direction[i][j]='u';
				}
			}
		}
	}
	len=length[n][m];
	cout<<"length of LCS= "<<len<<endl<<endl;
}

void LCS::lcs_print(){
	int i=n;
	int j=m;
	int l=len;
	while(i>0){
		while(j>0){
			if(direction[i][j] == 'd'){
				str[l-1]=s1[i-1];
				i--;
				j--;
				l--;
			}
			else if(direction[i][j] == 'u'){
				i=i-1;
			}
			else{
				j=j-1;
			}
		}
		i--;
	}
	
	cout<<"LCS = ";
	for(int i=0;i<len;i++){
		cout<<str[i];
	}
	cout<<endl<<endl;
}

void LCS::print_direction(){
	cout<<"Direction Table"<<endl<<endl;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			cout<<direction[i][j]<<"  ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void LCS::print_length(){
	cout<<"Length Table"<<endl<<endl;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			cout<<length[i][j]<<"  ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int LCS::max(int x, int y){
	if(x>y){
		return x;
	}
	else{
		return y;
	}
}
int main(){

	//LCS lcs1("abcdefgh","abdhijk");
	LCS lcs1("abcdcba","bdcaba");
	lcs1.lcs_length();
	lcs1.lcs_print();
	lcs1.print_direction();
	lcs1.print_length();
}

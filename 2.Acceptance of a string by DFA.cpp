#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int states[100][100];

int move(int ans, char ch){
	int val = ch-'a';
	return states[ans][val];
}

int main(){
	int n,alpha;
	cout<<"Enter number of States: ";
	cin>>n;
	cout<<"Enter number of alphabets: ";
	cin>>alpha;
	
	for(int i=0;i<n;i++){
		cout<<"For state: "<<i<<endl;
		char ch ='a'+i;
		for(int j=0;j<alpha;j++){
			cout<<"On Inputting alphabet '"<<ch++<<"' which state you moved to: ";
			cin>>states[i][j];
		}
	}
	int f;
	unordered_set <int> final;
	cout<<"\nEnter number of Final States: ";
	cin>>f;
	cout<<"Input Final States: ";
	for(int i=0;i<f;i++){
		int val;cin>>val;
		final.insert(val);
	}
	string s;
	cout<<"Input string: ";
	cin>>s;
	int ans=0,ptr = 0;
	while(ptr<s.length()){
		ans = move(ans,s[ptr]);
		ptr++;
	}
	if(final.find(ans)!=final.end()){
		cout<<"YES, Given String is accepted by DFA"<<endl;
	}else{
		cout<<"NO, Given String is not accepted by DFA"<<endl;
	}
	cout<<"State Transition Table of DFA: \n";
	cout<<"\t";
	for(int k=0;k<alpha;k++){
		char temp = 'a'+k;
		cout<<temp<<"\t";
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<i<<"\t";
		for(int j=0;j<alpha;j++){
			cout<<states[i][j]<<"\t";
		}
		cout<<endl;
	}
	return 0;
}

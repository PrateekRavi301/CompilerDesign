#include<iostream>
#include<bits/stdc++.h>
using namespace std;

set<string> keywords = {"asm","double","new","switch","auto","else","operator","template","break","enum","this",
"case","extern","protected","throw","catch","float","public","try","char","for","register","typedef","class",
"friend","return","union","const","goto","short","unsigned","continue","if","signed","virtual","default","inline",
"sizedof","void","typedef","delete","int","static","volatile","do","long","struct","while"};
set<string> operators = {"+","-","*","/","%","++","--","==","!=",">","<",">=","<=","&&","||","!","=","+=","-=","*=","/=","%=","&","|","^","~","<<",">>","?"};
set<string> specialChar = {"(",")","{","}","[","]","\\",";",",",".","/","#"};

vector<string> tokens;
bool validIdentifier(string word){
	
	if(word[0]>='0' && word[0]<'9')
		return false;
	for(auto a:word){
		if((a>='A' && a<='Z') || (a>='a'&&a<='z') || (a>='0' && a<='9') ||a=='_')
			continue;
		else{ 
			return false;
		}
	}
	return true;
}
bool constant(string word){
	int dot=0;
	for(int i=0;i<word.length();i++){
		if(word[0]=='-')
			continue;
		if(word[i]>='0'&&word[i]<='9')
			continue;
		else if(dot==0 && word[i]=='.'){
			dot++;
		}else{
			return false;
		}
	}
	return true;
}
int solve(string s){
	int ans=0;
	vector<string> words;
	string word="";
	for(char x:s){
		if(x==' '){
			words.push_back(word);
			word = "";
		}else{
			word+=x;
		}
	}
	words.push_back(word);
	for(int i=0;i<words.size();){
		if(keywords.find(words[i])!=keywords.end()){
			ans++;
			tokens.push_back(words[i]+" - Keyword");
		}else if(operators.find(words[i])!=operators.end()){
			ans++;
			tokens.push_back(words[i]+" - Operator");
		}else if(specialChar.find(words[i])!=specialChar.end()){
			ans++;
			tokens.push_back(words[i]+" - Special Character");
		}else if(validIdentifier(words[i])){
			ans++;
			tokens.push_back(words[i]+" - Identifier");
		}else if(words[i][0]=='"' && words[i][words[i].length()-1]=='"'){
			ans++;
			tokens.push_back(words[i]+" - Constant");
		}else if(words[i][0]=='"'){
			string temp = words[i];
			while(i<words.size() && words[i][words[i].length()-1]!='"'){
				i++;
				temp+=" "+words[i];
			}
			ans++;
			tokens.push_back(temp+" - String Literal");
		}else if(constant(words[i])){
			ans++;
			tokens.push_back(words[i] +" - Constant");
		}
		i++;
	}
	return ans;
}

int main(){
	int n;
	cout<<"Enter number of lines of code: ";
	cin>>n;
	cin.ignore();
	int res=0;
	string str="";
	for(int i=0;i<n;i++){
		getline(cin,str);
		res+=solve(str);
	}
	cout<<"\nTotal number of tokens : "<<res<<endl;
	for(auto i: tokens)cout<<i<<"\n";
	

	return 0;
}

	
	

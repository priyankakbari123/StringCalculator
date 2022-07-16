#include<bits/stdc++.h>

using namespace std;

//Method for finding numbers from string
vector<int> extractNumbers(string numbers){
    vector<int> nums;
    int i;
    string temp="";

    for(i=0;i<numbers.length();i++){
    	//here 92 is ascii of '\'
        if(numbers[i]!=',' && numbers[i]!=92 )temp+=numbers[i];
        else{
        	if(numbers[i]==92)i++;
            nums.push_back(stoi(temp));
            temp="";
        }
    }

    if(i==numbers.length() && temp!="")nums.push_back(stoi(temp));

    return nums;
}


//Method for Computing sum
int Add(string numbers){
    if(numbers.empty())return 0;

    //extractNumbers extract numvers from strings
    vector<int> nums=extractNumbers(numbers);

    //sum of extracted numbers
    return accumulate(nums.begin(),nums.end(),0);
}


int main(){
	//Taking Inputs
    string numbers;
    getline(cin,numbers);

    cout<<"Sum : "<<Add(numbers)<<endl;
    return 0;
}
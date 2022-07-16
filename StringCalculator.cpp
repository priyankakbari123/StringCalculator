#include<bits/stdc++.h>

using namespace std;

//Method for finding numbers from string
vector<int> extractNumbers(string numbers){
    vector<int> nums;
    int i=0;
    string temp="";

    //vector for maintaing delimeter list
    std::vector<char> delimiter;
    delimiter.push_back(',');
    //here 92 is ascii of '\'
    delimiter.push_back((char)92);

    //if delimeter specified in string
    if(numbers.substr(0,2)=="//"){
    	delimiter.push_back(numbers[2]);
    	i=5;
    }

    for(i;i<numbers.length();i++){
    	
     
        if(find(delimiter.begin(),delimiter.end(),numbers[i])==delimiter.end() )temp+=numbers[i];
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
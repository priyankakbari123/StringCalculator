#include<bits/stdc++.h>

using namespace std;

//Method for finding numbers from string
vector<int> extractNumbers(string numbers){
    vector<int> nums;

    int i;
    string temp="";
    for(i=0;i<numbers.length();i++){
        if(numbers[i]!=',')temp+=numbers[i];
        else{
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
    vector<int> nums=extractNumbers(numbers);

    return accumulate(nums.begin(),nums.end(),0);
}


int main(){
    string numbers;
    cin>>numbers;
    cout<<"Sum : "<<Add(numbers)<<endl;
    return 0;
}
// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
#include<string>
using namespace std;

class read_input {
    public:
        static const int no_of_rows=70;
        int year[no_of_rows];
        float interest_rate[no_of_rows];
        float inflation[no_of_rows];
        string gov[no_of_rows];
        string continent[no_of_rows];
        string temp;
        int size;
        float final_amount;

        void read_file(string);
        float final(int input_amount, int);
        float final_in_year(int input_amount,int yr);
};

float read_input::final_in_year(int input_amount,int yr){
    float final_amount= input_amount;
    float rate=interest_rate[yr-1960]-inflation[yr-1960];
    float SI=(rate*final_amount)/100;
    final_amount+=SI;
    return final_amount;
}
float read_input::final(int input_amount, int input_year){
    final_amount=input_amount;
    float rate,SI;
    for(int i=input_year-1960;i<=size;i++){
        rate=interest_rate[i]-inflation[i];
        SI=(rate*final_amount)/100;
        final_amount=final_amount + SI;
    }
    return final_amount;
}

void read_input::read_file(string str){
    int i=0;
    ifstream in_da(str);
    getline(in_da,temp);
    string yr,interest,infl,index;
    while(!in_da.eof()){ 
        getline(in_da,index,',');
        getline(in_da,yr,',');
        year[i]=stoi(yr);
        getline(in_da,interest,',');
        interest_rate[i]=stof(interest);
        getline(in_da,infl,',');
        inflation[i]=stof(infl);
        getline(in_da,gov[i],',');
        getline(in_da,continent[i],'\n');
        i++;
    }
    size=i-1;
}

int main(){
    read_input obj;
    obj.read_file("india_data.csv");
    int input_amount,input_yr;
    cout<<"Enter the amount of Investment ";
    cin>>input_amount;
    cout<<endl<<"Enter the year ";
    cin>>input_yr;
    // obj.read_file("");
    float final_amount_reseived = obj.final(input_amount,input_yr);
    cout<<endl<<"The Total money received : ";
    cout<<final_amount_reseived<<endl;
    int input_amount_1,input_yr_1;
    cout<<"Enter the amount of Investment to get the money after that year it was invested : ";
    cin>>input_amount_1;
    cout<<endl<<"Enter the year : ";
    cin>>input_yr_1;
    float final_Yr=obj.final_in_year(input_amount_1, input_yr_1);
    cout<<endl<<"Money after the year is : "<<final_Yr<<endl;
    
    return 0;
}




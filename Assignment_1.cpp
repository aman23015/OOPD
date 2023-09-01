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
        float final(int , int);
        float final_in_year(int ,int );
        float final_spain(int,int);
        float final_in_year_spain(int ,int );
        void Check_value();
};
void read_input::Check_value(){
    int peroid1 = 1977-1960;
    float rate;
    float SI;
    float final_value=166;
    for(int i=0;i<=peroid1;i++)
    {
        rate=interest_rate[i]-inflation[i];
        SI = (final_value*rate)/100;
        final_value = final_value + SI;
        
    }
    float final_rate = (166 - final_value)/166;
    cout<<"\nGrowth rate for Dictatorship period is :"<<final_rate<<endl;
    
    
    final_value = 166;
    int size2 = 1978 - 1960;
    for(int i=size2;i<=size;i++)
    {
        if(i==(2002-1960))
            final_value = final_value/166;
        rate = interest_rate[i]-inflation[i];
        SI = (final_value*rate)/100;
        final_value = final_value + SI;
    }
    //cout<<p_value<<endl;
    float final_rate_1 = (166/166 - final_value)/(166/166);
    cout<<"Growth rate for Republican Era is :"<<final_rate_1<<endl;
    if(final_rate > final_rate_1)
        cout<<"The Growth rate for Dictatorship is more compared to Republican Era";
    else
        cout<<"The Growth rate for Republican Era is more compared to Dictatorship";
}
float read_input::final_in_year_spain(int input_amount,int yr){
    float final_amount= input_amount;
    float rate=interest_rate[yr-1960]-inflation[yr-1960];
    float SI=(rate*final_amount)/100;
    final_amount+=SI;
    return final_amount;
}
float read_input::final_spain(int input_amount,int yr){
    final_amount=input_amount;
    float rate,SI;
    for(int i=(yr-1960);i<=size;i++){
        if(i==2002-1996){
            final_amount=final_amount/166;
        }
        rate=interest_rate[i]-inflation[i];
        SI=(rate*final_amount)/100;
        final_amount=final_amount+SI;
    }
    return final_amount;
}

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
    for(int i=(input_year-1960);i<=size;i++){
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

    cout<<"Question_2 :"<<endl;
    obj.read_file("spain_data.csv");
    
    int input_amount_2,input_yr_2;
    cout<<"Enter the amount of Investment in Spain bank : ";
    cin>>input_amount_2;
    cout<<endl<<"Enter the year : ";
    cin>>input_yr_2;
    cout<<"The total money received in spain bank is : ";
    float final_amount_reseived_1=obj.final_spain(input_amount_2,input_yr_2);
    cout<<final_amount_reseived_1<<endl;

    int input_amount_3,input_yr_3;
    cout<<"Enter the amount of Investment in spain bank to get the money after that year it was invested : ";
    cin>>input_amount_3;
    cout<<endl<<"Enter the year";
    cin>>input_yr_3;
    cout<<"Money after the year is :";
    float final_am=obj.final_in_year_spain(input_amount_3,input_yr_3);
    cout<<final_am<<endl;   
    return 0;
}




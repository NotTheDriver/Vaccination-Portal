#include<iostream>
#include<fstream>
using namespace std;
struct Account{
        long long int aadhar;
        long long int phone_num;
        string first_name;
        string last_name;
        string gender;
        int age;
};
void search_data(){
    long long int aadhar_no,flag=0;
    Account user;
    cout<<"Enter the Aadhar number of user: ";
    cin>>aadhar_no;
    ifstream read("user.txt");
    if(!read){cout<<"error";}
    read>>user.first_name;
    read>>user.last_name;
    read>>user.aadhar;
    read>>user.phone_num;
    read>>user.gender;
    read>>user.age;
    while(!read.eof()){
        if(user.aadhar==aadhar_no){
            cout<<"================================================================================================================\n";
            cout<<"First Name"<<"\t"<<"Last Name"<<"\t\t\t"<<"Aadhar Number"<<"\t\t\t"<<"Phone Number"<<"\t\t\t"<<"Gender"<<"\t\t"<<"Age"<<endl;
            cout<<"================================================================================================================\n";
            cout<<user.first_name<<"\t\t"<<user.last_name<<"\t\t"<<user.aadhar<<"\t\t"<<user.phone_num<<"\t\t"<<user.gender<<"\t"<<user.age<<endl;
            cout<<"\n\n";
            flag=1;
            break;
        }
        read>>user.first_name;
        read>>user.last_name;
        read>>user.aadhar;
        read>>user.phone_num;
        read>>user.gender;
        read>>user.age;
        if(user.aadhar==aadhar_no){
            cout<<"================================================================================================================\n";
            cout<<"First Name"<<"\t"<<"Last Name"<<"\t"<<"Aadhar Number"<<"\t\t"<<"Phone Number"<<"\t\t"<<"Gender"<<"\t\t"<<"Age"<<endl;
            cout<<"================================================================================================================\n";
            cout<<user.first_name<<"\t\t"<<user.last_name<<"\t\t\t"<<user.aadhar<<"\t\t\t"<<user.phone_num<<"\t\t\t"<<user.gender<<"\t\t\t"<<user.age<<endl;
            cout<<"\n\n";
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"Record Not Found"<<"\n\n";
    }
}
void update_vaccine(){
    int array[2],extra_doses;
    ifstream vaccine("vaccine.txt");
    vaccine>>array[0];
    vaccine>>array[1];
    cout<<"Vaccination Doses Available:"<<array[0]-array[1];
    printf("\n\nEnter the amount of vaccine doses to be added to the Inventory: ");
    cin>>extra_doses;
    array[0]+=extra_doses;
    cout<<"\n\nVaccination Doses Available:"<<array[0]-array[1];
    cout<<"\n\n";
    vaccine.close();
    ofstream file("vaccine.txt");
    file<<array[0]<<"\n";
    file<<array[1];
    vaccine.close();
}
void setdata();
int main();
void print_data(Account s){
    cout<<s.first_name<<"\t\t"<<s.last_name<<"\t\t"<<s.aadhar<<"\t\t"<<s.phone_num<<"\t\t"<<s.gender<<"\t\t"<<s.age<<endl;
}
void show_data(){
    Account user;
    ifstream read("user.txt");
    cout<<"================================================================================================================\n";
    cout<<"First Name"<<"\t"<<"Last Name"<<"\t"<<"Aadhar Number"<<"\t\t"<<"Phone Number"<<"\t\t"<<"Gender"<<"\t\t"<<"Age"<<endl;
    cout<<"================================================================================================================\n";

    if(!read){cout<<"error";}
    while(!read.eof()){
    read>>user.first_name;
    read>>user.last_name;
    read>>user.aadhar;
    read>>user.phone_num;
    read>>user.gender;
    read>>user.age;
    print_data(user);
    }
    cout<<endl;
    read.close();
}
void show_vaccine(){
    int array[2];
    char option;
    ifstream vaccine("vaccine.txt");
    vaccine>>array[0];
    vaccine>>array[1];
    cout<<"Vaccination Doses Available:"<<array[0]-array[1];
    cout<<"\n\nDo you want to update the Vaccine data? (Y/N): ";
    cin>>option;
    vaccine.close();
    if(option=='Y'|| option=='y'){
        system("cls");
        update_vaccine();
    }

}
void admin_main(){
    int choice;
    while(1){
    cout<<"1. Show Vaccine Data\n\n";
    cout<<"2. Show Records of All Users\n\n";
    cout<<"3. Search info of user\n\n";
    cout<<"4. Update Vaccine data\n\n";
    cout<<"5. To exit\n\n";
    cout<<"Enter your choice:";
    cin>>choice;
    switch(choice){
        case 1: show_vaccine();
        break;
        case 2: show_data();
        break;
        case 3:search_data();
        break;
        case 4: update_vaccine();
        break;
        case 5: system("cls");
        main();
        default:
        cout<<"Invalid input\n try again...\n\n";
    }

}}

void admin_login(){
    string username,password;
    int counter=3;
    while(counter>=1){
        cout<<"Enter username: ";
        cin>>username;
        cout<<"Enter password: ";
        cin>>password;
        counter--;
        if(username=="admin" && password=="admin"){
            system("cls");
            admin_main();
        }
        else if(counter==0){
            cout<<"No attempts left!\n\n";
        }
        else{
            cout<<"Wrong username and(or) password combination "<<counter<<" attempts left"<<endl;
        }
        
    }
}

void setdata(){
    struct Account new_account;
    long long int aadhar,phone_num;
    int age;
    string first_name,last_name,gender;
    cout<<"\n\nEnter first Name:";
    cin>>first_name;
    cout<<endl;
    cout<<"Enter last Name:";
    cin>>last_name;
    cout<<endl;
    cout<<"Enter Aadhar Number:";
    cin>>aadhar;
    cout<<endl;
    cout<<"Enter age:";
    cin>>age;
    cout<<endl;
    cout<<"Gender:";
    cin>>gender;
    cout<<endl;
    cout<<"Enter phone number:";
    cin>>phone_num;
    cout<<endl;
    // new_account.aadhar=aadhar,new_account.first_name=first_name,new_account.last_name=last_name,new_account.gender=gender,new_account.age=age,new_account.phone_num=phone_num;

    new_account={aadhar,phone_num,first_name,last_name,gender,age};
    ofstream file;
    file.open("user.txt",ios::app);
    file<<new_account.first_name<<"\n";
    file<<new_account.last_name<<"\n";
    file<<new_account.aadhar<<"\n";
    file<<new_account.phone_num<<"\n";
    file<<new_account.gender<<"\n";
    file<<new_account.age;
    file.close();
    int array[2];
    ifstream vaccine("vaccine.txt");
    vaccine>>array[0];
    vaccine>>array[1];
    array[1]+=1;
    vaccine.close();
    ofstream file2("vaccine.txt");
    file2<<array[0]<<"\n";
    file2<<array[1];
    file2.close();
    cout<<"Record Added Succesfully!\n\n"<<endl;
}


int main(){
    int option;
    cout<<"\t\t\t\t\t\t\t================================================"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\tVaccination Portal"<<endl;
    cout<<"\t\t\t\t\t\t\t================================================"<<endl;
    cout<<"Welcome!\n"<<endl;
    while(1){
    cout<<"1.Login as Admin\n\n2.Register For Vaccine\n\n3.Exit\n\nEnter your choice: ";
    cin>>option;
    switch (option)
    {
    case 1:system("cls");
        admin_login();
        break;
    case 2:setdata();
        break;
    case 3:exit(0);
    default:
        cout<<"Invalid choice....Try Again\n\n";
        system("cls");
        break;
    }
    }

    return 0;
}
#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

void login();
void registr();
void forgot();

main(){
    int choice;
    cout<<"****************** LOGIN ********************"<<endl;
    cout<<"\n1. Login"<<endl;
    cout<<"2. Register"<<endl;
    cout<<"3. Forgot password"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"\nEnter your choice : ";
    cin>>choice;
    switch(choice){
        case 1:{
            login();
            break;
        }
        case 2:{
            registr();
            break;
        }
        case 3:{
            forgot();
            break;
        }
        case 4:{
            cout<<"Thanks for your time! Hope to see you again."<<endl;
            break;
        }
        default:{
            cout<<"Wrong choice! Try again."<<endl;
            cout<<"\n";
            main();
        }
    }
}

void registr(){
    string reguser,regpass;
    system("cls");
    cout<<"Enter username : ";
    cin>>reguser;
    cout<<"Enter password : ";
    cin>>regpass;

    ofstream reg("database.txt", ios::app);
    reg<<reguser<<" "<<regpass<<endl;
    system("cls");
    cout<<"Registration successful!"<<endl;
    cin.get();
    cin.get();
    system("cls");
    main();
}

void login(){
    int exist;
    string user,pass,u,p;
    system("cls");
    cout<<"Enter username : ";
    cin>>user;
    cout<<"Enter password : ";
    cin>>pass;

    ifstream input("database.txt");

    while(input>>u>>p){
        if(u==user && p==pass){
            exist = 1;
        }
    }
    input.close();
    if(exist==1){
        cout<<"Hello "<<user<<"! Welcome back."<<endl;
        cin.get();
        cin.get();
        system("cls");
        main();
    }
    else{
        cout<<"Login error!";
        cin.get();
        cin.get();
        system("cls");
        main();
    }
}

void forgot(){
    int ch;
    system("cls");
    cout<<"*************** RESTORE ACCOUNT ***************"<<endl;
    cout<<"\n1. Find your account by username"<<endl;
    cout<<"2. Mainmenu"<<endl;
    cout<<"\nEnter your choice : ";
    cin>>ch;
    if(!cin){
        cout<<"Non-numeric value not supported!";
        return;
    }
    system("cls");

    switch(ch){
        case 1:{
            int ex=0;
            string finduser,fu,fp;
            cout<<"Enter username : ";
            cin>>finduser;

            ifstream findu("database.txt");
            while(findu>>fu>>fp){
                if(fu==finduser){
                    ex=1;
                    break;
                }
            }
            findu.close();
            if(ex==1){
                cout<<"We have found your account!"<<endl;
                cout<<"Here is your password : "<<fp;
                cin.get();
                cin.get();
                system("cls");
                main();
            }
            else{
                cout<<"Sorry, we couldn't find your account."<<endl;
                cin.get();
                cin.get();
                system("cls");
                main();
            }
            break;
        }

        case 2:{
            main();
            break;
        }
        default:{
            cout<<"Wrong choice! Try again.";
            cin.get();
            cin.get();
            system("cls");
            forgot();
        }
    }
}

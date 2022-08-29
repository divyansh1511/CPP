#include<iostream>
#include<bits/stdc++.h>
#include <fstream>

using namespace std;
class book{
    public:
    void askForData();
    void checkCompleteData();
    void checkYourBook();
};
void book::askForData(){
    system("cls");
    fstream file;
    string author, title, publisher,b_id;
    float price;
    int copies;
    cout<<"Enter the  book id:"<<endl;
    cin>>b_id;
    cout<<"Enter the name of the author:"<<endl;
    cin>>author;
    cout<<"Enter the title of the book:"<<endl;
    cin>>title;
    cout<<"Enter the publisher name of the book:"<<endl;
    cin>>publisher;
    cout<<"enter the price(in Rs) of the book:"<<endl;
    cin>>price;
    cout<<"Enter the no of copies of the book:"<<endl;
    cin>>copies;
    file.open("book1.txt", ios::out | ios::app);
    file << " " << b_id << " " << author << " " << title << " " << publisher << " " << price << " " << " " << copies << "\n";
    file.close();
}
void book::checkCompleteData(){
    system("cls");
    fstream file;
    string author, title, publisher,b_id;
    float price;
    int copies;
    cout << "List of All Books : "<<endl;
    file.open("book1.txt", ios::in);
    if (!file)
        cout << "File Openning Error.Check is Your File created?";
    else
    {
        cout << "\n\n Book ID   Author  Book Name  Publisher  prices  Copies\n\n";
        file >> b_id >> author>> title >> publisher >> price>> copies;
        while (!file.eof())
        {
            cout   << "   " << b_id <<"   " << author << "     " << title << "     " << publisher << "    " << price << "    " << copies <<endl;
            file  << " " << b_id <<" " << author << " " << title << " " << publisher << " " << price << " " << " " << copies << "\n";
            break;
        }
        file.close();

    }

}
void book::checkYourBook(){
    system("cls");
    fstream file;
    string author, title, publisher,b_id ,b_idd,a,t;
    float price;
    int req_copies,copies,count = 0;
    cout << "\n\n\t\t\t\tCheck Your Book Here"<<endl;
    cout<<endl;
    file.open("book1.txt", ios::in);
    if (!file)
        cout << "\n\n File Openning Error. Check is Your File created?";
    else
    {
        cout<<" Please enter the author name : ";
        cin>>a;
        cout<<"Please enter the title of the book : ";
        cin>>t;
        file  >> b_id >> author >> title >> publisher >>price >>copies;
        while (!file.eof())
        {
            if (a==author && t==title)
            {
                system("cls");
                cout << "Check Specific Book"<<endl;
                cout << "b_id : " << b_id<<endl;
                cout << "Author : " << author<<endl;
                cout << "title : " << title<<endl;
                cout << "publisher : " << publisher<<endl;
                cout << "Price : " << price<<endl;
                cout << "No. of Copies : " << copies<<endl;
                count++;
                cout<<endl;
                cout<<"enter reqd. copies:"<<endl;
                cin>>req_copies;
                if(req_copies<=copies){
                    cout<<"Total cost for the required no of copies is "<<req_copies*price<<endl;
                    copies=copies-req_copies;
                } 
                else{
                    cout<<"Sorry! Required number of copies are not in stock."<<endl;
                }
                break;
            }
            file >> b_id >>title >> author >> publisher >>price >>copies;

        }
        file.close();
        if (count == 0)
            cout << "\n\n Sorry!! we didn't found the book in aur server!";
    }
    
};  

int main(){
    int choice;
    char x;
    book b;
    cout<<"Welcome !!"<<endl;
    cout<<"Enter 1 for adding new book"<<endl;
    cout<<"Enter 2 for check the complete list of books"<<endl;
    cout<<"Enter 3 for checking specific book"<<endl;
p:
    cout << "\n\n Your Choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        do
        {
            b.askForData();
            cout << "\n\n Do You Want to Add another Book (y,n) : ";
            cin >> x;
        } while (x == 'y');
        break;
    case 2:
        b.checkCompleteData();
        break;
    case 3:
        b.checkYourBook();
        break;
    case 6:
        exit(0);
    default:
        cout << "\n\n Invalid Choice!! Please Try Again!!";
    }
    
    goto p;
    return 0;
}
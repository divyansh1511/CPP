#include<iostream>
#include<bits/stdc++.h>
#include <fstream>

using namespace std;
class book{
    public:
    void getdata();
    void showdata();
    void checkdata();
};
void book::getdata(){
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
    cout<<"publisher of the book:"<<endl;
    cin>>publisher;
    cout<<"enter the price of the book:"<<endl;
    cin>>price;
    cout<<"Enter the no of copies of the book:"<<endl;
    cin>>copies;
    file.open("book.txt", ios::out | ios::app);
    file << " " << b_id << " " << author << " " << title << " " << publisher << " " << price << " " << " " << copies << "\n";
    file.close();
}
void book::showdata(){
    system("cls");
    fstream file;
    string author, title, publisher,b_id;
    float price;
    int copies;
    cout << "Show All Books"<<endl;
    file.open("book.txt", ios::in);
    if (!file)
        cout << "File Openning Error...";
    else
    {
        cout << "\n\n Book ID    Book    Author    No. of Copies\n\n";
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
void book::checkdata(){
    system("cls");
    fstream file;
    string author, title, publisher,b_id ,b_idd;
    float price;
    int c,copies,count = 0;
    cout << "\n\n\t\t\t\tCheck Specific Book";
    file.open("book.txt", ios::in);
    if (!file)
        cout << "\n\n File Openning Error...";
    else
    {
        cout << "\n\n Book ID : ";
        cin >> b_idd;
        file  >> b_id >> author >> title >> publisher >>price >>copies;
        while (!file.eof())
        {
            if (b_idd == b_id)
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
                cout<<"enter reqd. copies:"<<endl;
                cin>>c;
                if(c<=copies){
                    cout<<"total cost of required copies is "<<c*price<<endl;
                    copies=copies-c;
                } 
                else{
                    cout<<"required copies are not in stock"<<endl;
                }
                break;
            }
            file >> b_id >>title >> author >> publisher >>price >>copies;

        }
        file.close();
        if (count == 0)
            cout << "\n\n Book ID Not Found...";
    }
    
};  

int main(){
    int choice;
    char x;
    book b;
p:
    cout << "\n\n Your Choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        do
        {
            b.getdata();
            cout << "\n\n Do You Want to Add another Book (y,n) : ";
            cin >> x;
        } while (x == 'y');
        break;
    case 2:
        b.showdata();
        break;
    case 3:
        b.checkdata();
        break;
    case 6:
        exit(0);
    default:
        cout << "\n\n Invalid Value...Please Try Again...";
    }
    
    goto p;
    return 0;
}
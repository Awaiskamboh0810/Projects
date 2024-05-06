#include<iostream>
#include<conio.h>
using namespace std;
int ascii =  178, i=0;
char ch = ascii;
struct bookshop
{
  int id;
  float price;
  string name, a_name,p_name;
}B[25];
// heading function
void heading()
{
    cout<<"\n";
        for(int m=1;m<=46;m++)
        cout<<ch;
        cout<<" BOOKSHOP INVENTORY SYSTEM ";
        for(int m=1;m<=46;m++)
        cout<<ch;
}
//insert new book
void Insert()
{
    system("cls");
    heading();


    cout<<"\n\n ENTER BOOK ID -> ";
    cin>>B[i].id;
    cout<<"\n\n ENTER BOOK NAME -> ";
    cin>>B[i].name;
    cout<<"\n\n ENTER AUTHOR NAME -> ";
    cin>>B[i].a_name;
    cout<<"\n\n ENTER PUBLISHER NAME -> ";
    cin>>B[i].p_name;
    cout<<"\n\n ENTER BOOK PRICE -> ";
    cin>>B[i].price;
    i++;
    cout<<"\n\n\n"<<ch<<ch<<" INSERT NEW BOOK SUCCESSFULLY "<<ch<<ch;
}
// search book
void Search()
{
    system("cls");
    heading();
    if(i == 0)
        cout<<"\n\n\n"<<ch<<ch<<" STRUCTURE IS EMPTY "<<ch<<ch;
    else
    {
     int t_id, found=0;
        cout<<"\n\n ENTER BOOK ID FOR SEARCH -> ";
        cin>>t_id;
        for(int a=0;a<i;a++)
        {
            if(t_id == B[a].id)
            {
                cout<< "\n\n BOOK NAME -> "<<B[a].name;
                cout<< "\n\n AUTHOR NAME -> "<<B[a].a_name;
                cout<< "\n\n PUBLISHER NAME -> "<<B[a].p_name;
                cout<< "\n\n BOOK PRICE -> "<<B[a].price;
                found++;
                break;
            }
        }
        if(found == 0)
        cout<<"\n\n\n"<<ch<<ch<<" BOOK ID NOT FOUND "<<ch<<ch;
}

    }
// update book
void update()
{
    system("cls");
    heading();
    if(i == 0)
        cout<<"\n\n\n"<<ch<<ch<<" STRUCTURE IS EMPTY "<<ch<<ch;
    else
    {
     int t_id, found=0;
        cout<<"\n\n ENTER BOOK ID FOR UPDATE -> ";
        cin>>t_id;
        for(int a=0;a<i;a++)
        {
            if(t_id == B[a].id)
            {
                cout<<"\n\n ENTER BOOK NAME -> ";
                cin>>B[a].name;
                cout<<"\n\n ENTER AUTHOR NAME -> ";
                cin>>B[a].a_name;
                cout<<"\n\n ENTER PUBLISHER NAME -> ";
                cin>>B[a].p_name;
                cout<<"\n\n ENTER BOOK PRICE -> ";
                cin>>B[a].price;
                cout<<"\n\n\n"<<ch<<ch<<" UPDATE BOOK SUCCESSFULLY "<<ch<<ch;
                found++;
                break;
            }
        }
        if(found == 0)
        cout<<"\n\n\n"<<ch<<ch<<" BOOK ID NOT FOUND "<<ch<<ch;
}

    }
    //delete book
    void Delete()
{
    system("cls");
    heading();
    if(i == 0)
        cout<<"\n\n\n"<<ch<<ch<<" STRUCTURE IS EMPTY "<<ch<<ch;
    else
    {
     int t_id, found=0;
        cout<<"\n\n ENTER BOOK ID FOR DELETE -> ";
        cin>>t_id;
        for(int a=0;a<i;a++)
        {
            if(t_id == B[a].id)
            {
                for(int k=a;k<i;k++)
                {
                    B[k].id = B[k+1].id;
                    B[k].name = B[k+1].name;
                    B[k].a_name = B[k+1].a_name;
                    B[k]. p_name = B[k+1].p_name;
                    B[k]. price = B[k+1].price;
                }
                cout<<"\n\n\n"<<ch<<ch<<" DELETE BOOK SUCCESSFULLY "<<ch<<ch;
                found++;
                i--;
                break;
            }
        }
        if(found == 0)
        cout<<"\n\n\n"<<ch<<ch<<" BOOK ID NOT FOUND "<<ch<<ch;
}

    }
    //show all books
    void Show()
{
    system("cls");
    heading();
    if(i == 0)
        cout<<"\n\n\n"<<ch<<ch<<" STRUCTURE IS EMPTY "<<ch<<ch;
    else
    {

        for(int a=0;a<i;a++)
        {
                cout<< "\n\n BOOK ID -> "<<B[a].id;
                cout<< "\n\n BOOK NAME -> "<<B[a].name;
                cout<< "\n\n AUTHOR NAME -> "<<B[a].a_name;
                cout<< "\n\n PUBLISHER NAME -> "<<B[a].p_name;
                cout<< "\n\n BOOK PRICE -> "<<B[a].price<<"\n\n";
                for(int m=1;m<46;m++)
                cout<<ch;
        }


}
    }
int main()

{      p:
    system ("cls");
 int choice;
       heading();
        cout<<"\n\n "<<ch<<ch<<"1. INSERT BOOK";
        cout<<"\n\n "<<ch<<ch<<"2. SEARCH BOOK";
        cout<<"\n\n "<<ch<<ch<<"3. UPDATE BOOK";
        cout<<"\n\n "<<ch<<ch<<"4. DELETE BOOK";
        cout<<"\n\n "<<ch<<ch<<"5. SHOW ALL BOOKS";
        cout<<"\n\n "<<ch<<ch<<"6. EXIT\n\n";
        for(int i=1;i<=46;i++)
        cout<<ch;
        cout<<"\n\n"<<ch<<ch<<" ENTER YOUR CHOICE -> ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            Insert();
            break;
        case 2:
            Search();
            break;
        case 3:
            update();
            break;
        case 4:
            Delete();
            break;
        case 5:
            Show();
            break;
        case 6:
            exit(0);
        default:
            cout<<"\n\n"<<ch<<ch<<" PLEASE SELECT CORRECT OPTION "<<ch<<ch;
        }
        getch();
        goto p;

}


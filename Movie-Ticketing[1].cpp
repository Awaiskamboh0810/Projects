#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
int ascii = 177, i=0;
char ch = ascii;
class Menu {
public:
	void heading()
    {
        cout<<"\n";
        for(int m=1;m<=45;m++)
        cout<<ch;
        cout<<" MOVIE TICKET BOOKING SYSTEM ";
        for(int m=1;m<=45;m++)
        cout<<ch;
	}

	void menu2() {
		system("cls");
        heading();
		cout<<"\n\n\n\n\n\t\t\t\tPress 1 to book a ticket"<<endl;
		cout<<"\t\t\t\tPress 2 to view your booking"<<endl;
		cout<<"\t\t\t\tPress 3 to view Price of tickets"<<endl;
		cout<<"\t\t\t\tPress 4 to check available seats"<<endl;
		cout<<"\t\t\t\tPress 5 to check Movie timing"<<endl;
		cout<<"\t\t\t\tPress 6 to show movies list"<<endl;
		cout<<"\t\t\t\tPress 7 to get a membership"<<endl;
		cout<<"\t\t\t\tPress 8 to exit"<<endl;
		cout<<"\t\t\t___________________________________________"<<endl;
	}
}; // End of class 'Menu'

class Person {
private:
    string name;
   long long cellno;
   long long CNIC;
public:
    Person() {
        name = " ";
        cellno = 0;
        CNIC = 0;
    }
    Person(string n, long long cn, long long c) {
        name = n;
        cellno = cn;
        CNIC = c;
    }
	// Setters and Getters
    void setName(string n) {
        name = n;
    }
    
    void setcellno(long long cn) {
        cellno = cn;
    }

    void setCNIC(long c) {
        CNIC = c;
    }

    string getname() {
        return name;
    }

    long getCell_no() {
        return cellno;
    }

   long long getCNIC() {
        return CNIC;
    }
    // Insert and display methods
    void insert() {
        cout<<"\t\t\tEnter your name:        ";
        getline(cin,name);
        cout<<"\t\t\tEnter your phone no:    ";
        cin>>cellno;
        cout<<"\t\t\tEnter your CNIC:        ";
        cin>>CNIC;
    }

    void display() {
        cout<<"\t\t\t\t\t\t---------------\n";
        cout<<"\t\t\t\t\tYour Name:     " << name <<endl;
        cout<<"\t\t\t\t\tYour Phone no: " << cellno <<endl;
        cout<<"\t\t\t\t\tYour CNIC:     " << CNIC <<endl;
    }
};  // End of class 'Person'

class Customer : public Person {

    int customer_id;
    string address;
public:
    Customer() {
        customer_id = 0;
        address = " ";
    }
    // Setters and Getters
    void setcustomer_id(int cid) {
        customer_id = cid;
    }
    int getcustomer_id() {
        return customer_id;
    }
    
    void setaddress(string ad) {
        address = ad;
    }
    string getaddress() {
        return address;
    }
    
    void check_customer() {
        string check;
        int arr[10];
        int serial = 101;
        int local = 0;
        int id;
        cout<<"Are you a new Customer or a member"<<endl;
        cout<<"Press 'N' for new"<<endl;
        cout<<"Press 'M' for member"<<endl;
        cin>>check;
        for (int n = 0; n < 10; n++) {
            arr[n] = serial;
            serial++;
        }
        if (check == "n" || check == "N") {

        } else if (check == "m" || check == "M") {
            cout<<"Enter your Customer id: ";
            cin>>id;
            for (int n = 0; n < 10; n++) {
                if (id == n) {
                    serial++;
                } 
            } // for loop
            if (local > 0) {
                cout<<"Customer Verified"<<endl;
                cout<<"You will get an additional 10% off"<<endl;
            } else {
                cout<<"Invalid membership id"<<endl;
            }
        } // else-if statement
    } // End of function, check_customer()
    
    void menu2() {
        cout << "\t\t===================================" << endl;
        cout << "\t\t|Welcome to Movie Ticket Booking | "<<endl;
		cout << "\t\t===================================\n" << endl;
        cout << "\t\t\tPress 1 to book a ticket" << endl;
        cout << "\t\t\tPress 2 to view your booking" << endl;
        cout << "\t\t\tPress 3 to view Price of tickets" << endl;
        cout << "\t\t\tPress 4 to check available seats" << endl;
        cout << "\t\t\tPress 5 to check movie timing" << endl;
        cout << "\t\t\tPress 6 to show movies list" << endl;
        cout << "\t\t\tPress 7 to get a membership" << endl;
        cout << "\t\t\tPress 8 to exit" << endl;
        cout << "\t\t___________________________________________" << endl;
    }
    
    void old_customer() {
        int id = 101;
        string s, st;
        cout<<"\t\t\tDo you have any old membership."<<endl;
        cout<<"\t\t\tPress 'Y' for Yes or 'N' for No."<<endl;
        cin>>s;
        if (s == "y" || s == "Y") {
            cout<<"Renew your membership"<<endl;
            cout<<"Enter your id: ";
            cin>>id;
            cout<<"Your membership is renewed"<<endl;
        } else if (s == "n" || s == "N") {
            cout<<"\t\t\tEnter your address: ";
            cin>>st;
            cout<<"\t\t\t\tCongratulations You are now a member"<<endl;
            cout<<"\t\t\t\t\tYour membership id: "<<id<<endl;
        }
    }
}; // End of class 'Customer'

class Login {
private:
    string un; // for username
    string pass;// for password
public:
    Login() {
        un = "";
        pass = "";
    }
    // Setters and Getters
    void set_un(string u) {
        un = u;
    }
    string get_un() {
        return un;
    }
    void set_pass(string p) {
        pass = p;
    }
    string get_pass() {
        return pass;
    }
    
    void memberships() {
        cout<<"\t\tMembers Benefits: "<<endl;
        cout<<"\t\t1) Discount on Drinks"<<endl;
        cout<<"\t\t2) 10% off on tickets"<<endl;
        cout<<"\t\t3) Free 3D Glasses"<<endl;
    }
    
    void admin() {
    string username, password;

    cout << "\n\n\t\tEnter your username: ";
    cin >> username;

    cout << "\n\t\tEnter your password: ";
    cin >> password;
    ofstream file("login.txt", ios::app); 

    if (!file) {
        cerr << "Error opening file." << endl;
    } else {
        file << "Username: " << username << "\nPassword: " << password << endl;
        file.close();
        cout << "\n\n\t\t\t----------------------"<<endl;
        cout << "\t\t\t| login Successfully |" << endl;
        cout << "\t\t\t----------------------"<<endl;
        cout << "\n\n\n\t\t\t\tPress any key to continue......!!!" << endl;
    }
}

	void memberop() {   
		 memberships();
	} 
}; 
class Movie
{
private:
	string movie_name;
	string dimension;
	string direct;
	string run_time;
	string type;
	string release;
public:
	int tim;
	Customer cu;
	
	
	Movie() {
		movie_name="";
		dimension="";
		direct="";
	    release="";
		type="";
		run_time="";
	}
	// Setters and Getters
	void setmovie_name(string smn) {
		movie_name=smn;
	}
	string getmovie_name() {
		return movie_name;
	}
	
	void setdimension(string sd) {
		dimension=sd;
	}
	string getdimension() {
		return dimension;
	}
	
	void setdirect(string di) {
		direct=di;
	}
	string getdirect() {
		return direct;
	}
	
	void setrelease(string r) {
		release=r;
	}
	string getrelease() {
		return release;
	}
	
	void settype(string ty) {
		type=ty;
	}
	string gettype() {
		return type;
	}
	
	void setrun_time(string rt) {
		run_time=rt;
	}
	string getrun_time() {
		return run_time;
	}
	
	void playing() {
		Movie m[4];
	    int i;
	    
		m[0].setmovie_name("Fast and furious");
		m[0].setrelease("12th Junuary 2022");
		m[0].setrun_time("2h 23mins");
		m[0].settype("Action//Adventure");
		m[0].setdirect("Christopher paolini");
		m[0].setdimension("3D");
		
		m[1].setmovie_name("Oppenheimer");
		m[1].setrelease("16th march 2022");
		m[1].setrun_time("2h 27mins");
		m[1].settype("Action//Adventure");
		m[1].setdirect("Christopher Nolan ");
		m[1].setdimension("3D");
		
		m[2].setmovie_name("John Wick");
		m[2].setrelease("12th Junuary 2022");
		m[2].setrun_time("2h 53mins");
		m[2].settype("Action//Adventure");
		m[2].setdirect("Christopher paolini");
		m[2].setdimension("3D");
		
		m[3].setmovie_name("Mission Impossible 7");
		m[2].setrelease("26th may 2023");
		m[3].setrun_time("3h 12mins");
		m[3].settype("Action//Adventure");
		m[3].setdirect("Christopher McQuarrie");
		m[3].setdimension("3D");  // Provide details for other movies as well
	    // Set details for Movie 
	    cout << "\t\t\t Select the Movie" << endl;
	    for (int i = 0; i < 4; i++) {
	        cout << "______________________________________________" << endl;
	        cout << "\n\t\t\tMovie No : " << i + 1 << endl;
	        cout << "______________________________________________" << endl;
	        cout << "Movie Title : " << m[i].getmovie_name() << endl;
	        cout << "Release Date : " << m[i].getrelease() << endl;
	        cout << "Runtime : " << m[i].getrun_time() << endl;
	        cout << "Directed By : " << m[i].getdirect() << endl;
	        cout << "Genre : " << m[i].gettype() << endl;
	        cout << "Screen : " << m[i].getdimension() << endl;
	    }
	    cout << "\t\t\tPress 1 for Movie no 1\n\t\t\tPress 2 for Movie no 2\n\t\t\tpress 3 for Movie no 3\n\t\t\tPress 4 forn Movie no 4\n\n";
	    cout << "Enter Your choice";
	    cin >> i;
	
	    if (i >= 1 && i <= 4) {
	        tim = i;  // Set the selected movie timing
	        cout << "______________________________________________" << endl;
	        cout << "\t\t\tYour Selected Movie is : " << endl;
	        cout << "Movie Title : " << m[i - 1].getmovie_name() << endl;
	        cout << "Release Date : " << m[i - 1].getrelease() << endl;
	        cout << "Runtime : " << m[i - 1].getrun_time() << endl;
	        cout << "Directed By : " << m[i - 1].getdirect() << endl;
	        cout << "Genre : " << m[i - 1].gettype() << endl;
	        cout << "Screen : " << m[i - 1].getdimension() << endl;
	    } else
			cout << "Invalid choice!" << endl;
	} // function, playing()

	void movieselected() {
		cout<<"\t\t\t\t\tMovie Title : "<<getmovie_name()<<endl;
		cout<<"\t\t\t\t\tRuntime : "<<getrun_time()<<endl;
	}
	void viewb() {
		cout<<"\t\t\tYour Booking's\n";
		cout<<"Movie Deails : "<<endl;
		cout<<"\t\t\tMovie Title : "<<getmovie_name()<<endl;
		cout<<"\t\t\tRelease date : "<<getrelease()<<endl;
		cout<<"\t\t\tRuntime : "<<getrun_time()<<endl;
		cout<<"\t\t\tDirected By : "<<getdirect()<<endl;
		cout<<"\t\t\tGenre : "<<gettype()<<endl;
		cout<<"\t\t\tScreen : "<<getdimension()<<endl; 
	}
	void addmovie() {
		string n,m,s,p,q,r;
		cout<<"Enter Movie Name : ";
		cin>>n;
		setmovie_name(n);
		cout<<"Enter Release Date : ";
		cin>>m;
		setrelease(m);
		cout<<"Enter Runtime : ";
		cin>>s;
		setrun_time(s);
		cout<<"Enter Directors Name:";
		cin>>p;
		setdirect(p);
		cout<<"Enter Type : ";
		cin>>q;
		settype(q);
		cout<<"Enter Dimension";
		cin>>r;
		setdimension(r);
		cout<<"\t\t\tMovie has successfully been Added"<<endl;
		cout<<"Movie Title : "<<getmovie_name()<<endl;
	    cout<<"Release Date : "<<getrelease()<<endl;
		cout<<"Runtime : "<<getrun_time()<<endl;
		cout<<"Directed By : "<<getdirect()<<endl;
		cout<<"Genre : "<<gettype()<<endl;
		cout<<"Screen : "<<getdimension()<<endl;
	}
	void list() {
		Movie q[4];
		q[0].setmovie_name("Fast and furious");
		q[0].setrelease("12th Junuary 2022");
		q[0].setrun_time("2h 23mins");
		q[0].settype("Action//Adventure");
		q[0].setdirect("Christopher paolini");
		q[0].setdimension("3D");
		
		q[1].setmovie_name("Oppenheimer");
		q[1].setrelease("16th march 2022");
		q[1].setrun_time("2h 27mins");
		q[1].settype("Action//Adventure");
		q[1].setdirect("Christopher Nolan ");
		q[1].setdimension("3D");
		
		q[2].setmovie_name("John Wick");
		q[2].setrelease("12th Junuary 2022");
		q[2].setrun_time("2h 53mins");
		q[2].settype("Action//Adventure");
		q[2].setdirect("Christopher paolini");
		q[2].setdimension("3D");
		
		q[3].setmovie_name("Mission Impossible 7");
		q[2].setrelease("26th may 2023");
		q[3].setrun_time("3h 12mins");
		q[3].settype("Action//Adventure");
		q[3].setdirect("Christopher McQuarrie");
		q[3].setdimension("3D");
		cout<<"\nMovie Playing :"<<endl;
		for(int i=1; i<120; i++)
			cout<<"_";
			
    cout << "\nMovies List\t|\t\tMovie No 1\t|\t\tMovie no 2\t|\ttMovie No 3\t|\t\tMovie No 4" << endl;
    cout << "\nName:\t\t|\t\tFast X\t\t|\tOppenheimer\t\t|\tJohn Wick 4\t\t|\tMission Impossible 7" << endl;
    cout << "\nRelease:\t|\t12th January 2020\t|\t12th January 2020\t|\t12th January 2020\t|\t12th January 2020\n" << endl;
    cout << "Dimensions:\t|\t3D\t\t\t|\t3D\t\t\t|\t3D\t\t\t|\t3D" << endl;
    cout << "\nType:\t\t|\tAction\\Adventure\t|\tAction\\Adventure\t|\tAction\\Adventure\t|\tAction\\Adventure" << endl;
    cout << "\nDirectors:\t|\tChristopher Paolini\t|\tChristopher Nolan\t|\tChristopher Paolini\t|\tChristopher McQuarrie" << endl;
	}
	
}; // End of class 'Movie'

class Time {
private:
	string movietime;
public:
	Time() {
		movietime="";
	}
	// Setter and Getter
	void setmovietime(string mt) {
		movietime=mt;
	}
	string getmovietime() {
		return movietime;
	}
	
	void shedule1() {
		cout<<"\t\t\t\t\t1.)\tMon	11am\n\t\t\t\t\t2.)\tWed	2pm\n\t\t\t\t\t3.)\tSun 	4pm\n\t\t\t\t\t4.)\tSun	6pm"<<endl;
	}
	void shedule2() {
		cout<<"\t\t\t\t\t1.)\tTUE	11am\n\t\t\t\t\t2.)\tTHU	2pm\n\t\t\t\t\t3.)\tSAT 	4pm\n\t\t\t\t\t4.)\tSUN	  6pm"<<endl;
	}
	void shedule3() {
		cout<<"\t\t\t\t\t1.)\tMon	11am\n\t\t\t\t\t2.)\tWed	2pm\n\t\t\t\t\t3.)\tSun   	4pm\n\t\t\t\t\t4.)\tSUN 	6pm"<<endl;
	}
	void shedule4() {
		cout<<"\t\t\t\t\t1.)\tFRI	11am\n\t\t\t\t\t2.)\tMON	2pm\n\t\t\t\t\t3.)\tSun  	4pm\n\t\t\t\t\t4.)\tSUN   	6pm"<<endl;
	}					
};

class Ticket {
private:
	int tim;
	int id;
	int number;
	double price;
	string goldorsilver;
	int member;
	int availableseat;
public:
	Time t;
	Movie m;
	Customer cu;
	
	Ticket() {
		id=11101;
		price=0.0;
		availableseat=300;
	}
	// Setters and Getters
	void setid(int id) {
		id=id;
	}
	int getid() {
		return id;
	}
	
	void setnumber(int n) {
		number=n;
	}
	int getnumber() {
		return number;
	}
	
	void setprice(double pri) {
		price=pri;
	}
	double getprice() {
		return price;
	}
	
	void settickettye(string tt) {
		goldorsilver=tt;
	}
	string gettickkettye() {
		return goldorsilver;
	}
	
	void setseat(int a) {
		availableseat=a;
	}
	int getseat() {
		return availableseat;
	}
	
	void movie1() {   
		cout<<"\t\t\t_______________________________________\n"<<endl;
		cout<<"\t\t\t\t\t\tMovie Timing !!!\n"<<endl;
		cout<<"\t\t\t\t\t\tDay		Time"<<endl;
		cout<<"\t\t\t\t\t\t_____________"<<endl;
		t.shedule1();
		cout<<"\t\t\tEnter your Choice : ";
		int x;
		cin>>x;
		cout<<"\t\t\t_______________________________________________\n"<<endl;
		
		if(x==1) {
			cout<<"\t\t\t\t\tTimings : MON		11am"<<endl;
			t.setmovietime("MON		11am");
		}
		else if(x==2) {
			cout<<"\t\t\t\t\tTimings : WED		2pm"<<endl;
			t.setmovietime("WED		2pm");
		}
		else if(x==3) {
				cout<<"\t\t\t\t\tTimings : SUN		4pm"<<endl;
			t.setmovietime("SUN		4pm");
		}
		else if(x==4) {
				cout<<"\t\t\t\t\tTimings : SUN		9pm"<<endl;
			t.setmovietime("SUN		9pm");
		}
		cout<<"\t\t\t__________________________________________________\n"<<endl;
	}
	void movie2() {
	    cout<<"\t\t\t_______________________________________\n"<<endl;
		cout<<"\t\t\t\t\t\tMovie Timing !!!\n"<<endl;
		cout<<"\t\t\t\t\t\tDay		Time"<<endl;
		cout<<"\t\t\t\t\t\t_____________"<<endl;
		t.shedule2();
		cout<<"\t\t\tEnter your Choice : ";
		int x;
		cin>>x;
		cout<<"\t\t\t_______________________________________________\n"<<endl;
		
		if(x==1) {
			cout<<"\t\t\t\t\tTimings : TUE		3pm"<<endl;
			t.setmovietime("TUE		3pm");
		}
		else if(x==2) {
			cout<<"\t\t\t\t\tTimings : THU		4pm"<<endl;
			t.setmovietime("THU		4pm");
		}
		else if(x==3) {
				cout<<"\t\t\t\t\tTimings : SAT		3pm"<<endl;
			t.setmovietime("SAT		3pm");
		}
		else if(x==4) {
				cout<<"\t\t\t\t\tTimings : SUN		5pm"<<endl;
			t.setmovietime("SUN		5pm");
		}
		cout<<"\t\t\t__________________________________________________\n"<<endl;
	}
	void movie3() {
		cout<<"\t\t\t_______________________________________\n"<<endl;
		cout<<"\t\t\t\t\t\tMovie Timing !!!\n"<<endl;
		cout<<"\t\t\t\t\t\tDay		Time"<<endl;
		cout<<"\t\t\t\t\t\t_____________"<<endl;
		t.shedule3();
		cout<<"\t\t\tEnter your Choice : ";
		int x;
		cin>>x;
		cout<<"\t\t\t_______________________________________________\n"<<endl;
		
		if(x==1) {
			cout<<"\t\t\t\t\tTimings : MON		3pm"<<endl;
			t.setmovietime("MON		3pm");
		}
		else if(x==2) {
			cout<<"\t\t\t\t\tTimings : WED		6pm"<<endl;
			t.setmovietime("WED		6pm");
		}
		else if(x==3) {
				cout<<"\t\t\t\t\tTimings : SUN		5pm"<<endl;
			t.setmovietime("SUN		5pm");
		}
		cout<<"\t\t\t__________________________________________________\n"<<endl;
	}
	void movie4() {
		cout<<"\t\t\t_______________________________________\n"<<endl;
		cout<<"\t\t\t\t\t\tMovie Timing !!!\n"<<endl;
		cout<<"\t\t\t\t\t\tDay		Time"<<endl;
		cout<<"\t\t\t\t\t\t_____________"<<endl;
		t.shedule4();
		cout<<"\t\t\tEnter your Choice : ";
		int x;
		cin>>x;
		cout<<"\t\t\t_______________________________________________\n"<<endl;
		
		if(x==1) {
			cout<<"\t\t\t\t\tTimings : FRI		2pm"<<endl;
			t.setmovietime("FRI		2pm");
		}
		else if(x==2) {
			cout<<"\t\t\t\t\tTimings : MON		4pm"<<endl;
			t.setmovietime("MON		4pm");
		}
		else if(x==3) {
				cout<<"\t\t\t\t\tTimings : SUN		5pm"<<endl;
			t.setmovietime("SUN		5pm");
		}
		cout<<"\t\t\t__________________________________________________\n"<<endl;
	}
	void shedule() {
		m.playing();
		if(m.tim==1) {
			movie1();
		}
		else if(m.tim==2) {
			movie2();
		}
		else if(m.tim==3) {
			movie3();
		}
		else if(m.tim==4) {
			movie4();
		}
	}
	void tickettyppe() {
		cout<<"\t\t\t\t\tEnter your Ticket type Silver or GOld : "<<endl;
		cout<<"\t\t\t\t\tSilver costs RS.500, Gold costs RS.1000 "<<endl;
		cout<<"\t\t\t\t\tPress S for Silver \n\t\t\t\t\tPress G for Gold"<<endl;
		cout<<"\t\t\t\t\tEnter your choice : ";
		string s;
		cin>>s;
		cout<<"\t\t\t____________________________________________"<<endl;
		if(s=="s" || s=="S") {
			cout<<"\t\t\t\t\tSilver Ticket Selected"<<endl;
			setprice(500.0);
			settickettye("Silver Ticket");
		}
		else if(s=="g" || s=="G") {
			cout<<"\t\t\t\t\tGold Ticket Selected"<<endl;
			setprice(1000.0);
			settickettye("GOld Ticket");
		}
		cout<<"\t\t\t____________________________________________"<<endl<<endl;
	}
	void display() {
		numbert();
		cout<<"\t\t\t____________________________________________"<<endl;
		cout<<"\t\t\t\tYour Ticket has Successfuly been Booked\n";
		cout<<"\t\t\t____________________________________________"<<endl;
		//cout<<"\t\t\t\t\t\tBookking Details!!!!!\n"<<endl;
		 ofstream bookingFile("booking_info.txt", ios::app);
        if (bookingFile.is_open()) {
            bookingFile << "Ticket ID: " << getid() << "\n";
            bookingFile << "Movie Title: " << m.getmovie_name() << "\n";
            bookingFile << "Release date: " << m.getrelease() << "\n";
            bookingFile << "Runtime: " << m.getrun_time() << "\n";
            bookingFile << "Ticket Type: " << gettickkettye() << "\n";
            bookingFile << "Ticket Price: " << getprice() << "\n";
            bookingFile << "--------------------------------------\n";
            bookingFile.close();
        } else {
            cout << "Error opening booking_info.txt for writing." << endl;
        }
    }
void ticketd()
      { 
  	 m.viewb(); 
	 cout << "\t\t\tTicket id\t: " << getid() << endl;
	 cout << "\t\t\tTicket Type\t: " << gettickkettye() << endl; 
  	 cout << "\t\t\tTicket Price\t: " << getprice() << endl; 
	   }
	    void pricet() {
		cout<<"\n\n";
		cout<<"\t\t\t\t\tWhick Ticket Type Silver or Gold : "<<endl;
		cout<<"\t\t\t\t\tPress S for Silver \n\t\t\t\t\tPress G for Gold"<<endl;
		cout<<"\t\t\t\t\tEnter your choice : ";
		string s;
		cin>>s;
		cout<<"\t\t\t_______________________________________________"<<endl;
		if(s=="s" || s=="S") {
			cout<<"\t\t\tCost of Silver Lounge Ticket= 500 Inc.Tax"<<endl;
			setprice(500.0);
			settickettye("Silver Ticket");
		}
		else if(s=="g" || s=="G") {
			cout<<"\t\t\tCost of Gold Lounge Ticket= 1000 Inc.Tax"<<endl;
			setprice(1000.0);
			settickettye("GOld Ticket");
		}
		cout<<"\t\t\t_______________________________________________"<<endl;
	}
	void numbert() {
		cout<<"\t\t\tNo. of Tickets to Book: ";
		int i;
		cin>>i;
		setnumber(i);
		setseat(availableseat-i);
		if(getprice()==500) {
			cout<<"\t\t\tPrice of each Ticket = 500 Inc.Taxes"<<endl;
			setprice(500*i);
		}
		else if(getprice()==1000) {
			cout<<"\t\t\tPrice of each Ticket = 1000 Inc.Taxes"<<endl;
			setprice(1000*i);
		}
		cout<<"\t\t\t Total Price of Tickets = "<<getprice()<<" Inc.Taxes"<<endl;
	}
	void availableseats() {
		cout<<endl<<endl;
		cout<<"\t\t\tavailable Seats of Theater"<<endl;
		cout<<"\t\t\tTotal Seats of Theater = 300"<<endl;
		cout<<"\t\t\tSeats Booked : "<<getnumber()<<endl;
		cout<<"\t\t\tAvailable Seats : "<<getseat()<<endl;
	}
	void timing() {
		cout<<"\t\t\t_______________________________________________"<<endl;
		cout<<"\n\t\t\t\t\tMovie Timings"<<endl;
		cout<<"\nMovies Playing : "<<endl;
		cout<<"\t\t\t1)  Fast & Furious"<<endl;
		cout<<"\t\t\t2)  Oppenheimer"<<endl;
		cout<<"\t\t\t3)  John Wicks"<<endl;
		cout<<"\t\t\t4)  Mission Impossible 7"<<endl;
	    int v;
	    cout<<"Entr your choice: ";
	    cin>>v;
	    cout<<"\n\t\t\tNow playing in Following Timings"<<endl;
	    if(v==1) {
	    	t.shedule1();
		}
		else if(v==2) {
			t.shedule2();
		}
		else if(v==3) {
			t.shedule3();
		}
		else if(v==4) {
			t.shedule4();
		}	
	}
}; 
int main() {
    Movie m;
    Menu me;
    Ticket ti;
    Customer c;
    Login l;
    system("cls");
    int x;
    int lop = 1;
    cout<<"\n\n";
    me.heading();
    cout<<"\n\n\n\t\tDeveloped By:";
    cout<<"\n\n\n\n\t\t\t\t-----------------"<<endl;
    cout<<"\t\t\t\t| Taha Naveed   |";
    cout<<"\n\n\t\t\t\t| Awais Shabbir |";
    cout<<"\n\t\t\t\t-----------------"<<endl;
    cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!!";
	getch();
	system("cls");
	me.heading();
	l.admin();
	getch();
    do {
    	system("cls");
    	Menu me;
    	int choice;
    	me.menu2();
        cout<<"\n\t\t\tEnter your Choice : ";
        cin>>choice;
        switch(choice) {
            case 1: {
                ti.shedule();
                ti.tickettyppe();
               ti.display();
                break;
            }
            case 2: {
                ti.ticketd();
                break;
            }
            case 3: {
                ti.pricet();
                break;
            }
            case 4: {
                ti.availableseats();
                break;
            }
            case 5: {
                ti.timing();
                break;
            }
            case 6: {
                m.list();
                break;
            }
            case 7: {
                l.memberop();
                cout << "\n\n";
                cin.ignore();
                c.insert();
                c.old_customer();
                c.display();
                break;
            }
            case 8: {
                return 0;
            }
            default:
                break;
        } 
        cout << "\n\n\t\t\t\t\tPress 1 to go to the main menu" << endl;
        cout << "\t\t\t\t\tPress 0 to Exit" << endl;
        cin >> lop;
    } while(lop == 1); {
	}
    return 0;
}             

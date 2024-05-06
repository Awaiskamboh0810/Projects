#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
using namespace std;


void result() {
    // open the file for reading
    ifstream file("party_Votes.txt");

    // initialize an array to store the vote counts for each party
    int votes[5] = {0};

    // read the party choices from the file
    int party;
    while (file >> party) {
        // increment the vote count for the chosen party
        votes[party - 1]++;
    }

    // close the input file
    file.close();

    // display the final results
    cout << "\n\nFinal Results:" << endl;
    cout << "-------------" << endl;
    cout << "\t\t\t1. PTI: " << votes[0] << endl;
    cout << "\n\t\t\t2. PMLN: " << votes[1] << endl;
    cout << "\n\t\t\t3. TLP: " << votes[2] << endl;
    cout << "\n\t\t\t4. PPP: " << votes[3] << endl;
    cout << "\n\t\t\t5. JUI: " << votes[4] << endl;

    // find the party with the most votes
    int max_Votes = 0;
    int winner = 0;
    for (int i = 0; i < 5; i++) {
        if (votes[i] > max_Votes) {
            max_Votes = votes[i];
            winner = i++;
        }
    }

    // display the winner
    cout << "\n\t\t\tThe winner is: Party " << winner << endl;
}









int name() {
    int age;
    system("cls");
    cout << "\n\t\t\t\t*************************";
    cout << "\n\t\t\t\t Age Eligibility Criteria ";
    cout << "\n\t\t\t\t*************************" << endl;
    cout << "\n\t\t\tEnter your age: ";
    cin >> age;
    if (age >= 18) {
        system("cls");
        string name;

        long long int id;
        string dob;
        ofstream pass("party_Votes.txt", ios::app);
        ofstream file("record.txt", ios::app);

        cout << "Candidate Information" << endl;
        cout << "---------------------" << endl;

        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, name);

        ifstream id_num_in("idcard.txt");
        bool id_exists = false;
        long long int existing_id;
        while (id_num_in >> existing_id) {
            if (existing_id == id) {
                id_exists = true;
                break;
            }
        }
        id_num_in.close();

        if (id_exists) {
            cout << "Warning: ID card number already exists!" << endl;
            return 0; // Exit the function if ID exists
        } else {
            ofstream id_num_out("idcard.txt", ios::app);
            cout << "ID-Card Number: ";
            cin >> id;
            id_num_out << " " << id;
            id_num_out.close();
        }

        cout << "Enter your Date of Birth: ";
        cin >> dob;
        cout << endl;
        cout << "Choose Party" << endl;
        cout << "------------";
        system("cls");
int n;
        string arr[5] = {"PTI","PMLN","TLP","PPP","JUI"};
        cout << "\n\n\n\t\t\t1.PTI";
        cout << "\n\t\t\t2.PMLN";
        cout << "\n\t\t\t3.TLP";
        cout << "\n\t\t\t4.PPP";
        cout << "\n\t\t\t5.JUI";
        cout << "\n\n\t\t\tEnter Your Choice: ";
        cin >> n;
        pass << "  " << arr[n - 1]; // Corrected array indexing
        pass.close();

        file << "Name: " << name << endl;
        file << "Age: " << age << endl;
        file << "Date-of-Birth: " << dob << endl;
        file << "Your vote has been casted to " << arr[n-1]<<"\n";

        file.close();
        cout << endl << "Congratulation! Your vote has been casted to " << arr[n-1] << " party";
    } else {
        cout << "\n\nYou are Under 18...Not Eligible for Vote Casting. Thanks! ";
    }
}

void main_menu(){
	int choice;
	system("cls");
	cout<<"\n\t\t\t\t*************************";
cout<<"\n\t\t\t\t Electronic Voting System ";
cout<<"\n\t\t\t\t      * MAIN MENU *";
cout<<"\n\t\t\t\t*************************";
cout<<"\n\n\n\t\t\t1.Cast a Vote";
cout<<"\n\t\t\t2.Candidates Record";
cout<<"\n\t\t\t3:Final Results";
cout<<"\n\t\t\t4.Exit";
cout<<"\n\n\t\t\tEnter Your Choice: ";
cin>>choice;
int age_1;
string name_1;
	string line;
	ifstream file("record.txt");

	switch(choice)
	{
		case 1:
			name();
			getch();
			main_menu();
			break;

		case 2:
			system("cls");

			cout<<"Candiadate Record"<<endl;
			cout<<"-----------------";


		while(getline(file,line))
		{
			cout<<endl<<" "<<line;
		}

		file.close();
		getch();
		main_menu();

		break;

		case 3:
			system("cls");
			result();
			getch();
			main_menu();
			break;

		file.close();
		cout<<endl<<"\n\nPress any key to go back to Main Menu: ";
		getch();
		main_menu();

		break;

		case 4:

			break;
		default:
		cout<<" ";


	}

}

int main()

{
	cout<<"\n\t\t\t****************************";
cout<<"\n\t\t\t* Electronic Voting System *";
cout<<"\n\t\t\t****************************";
cout<<"\n\n\t\tDeveloped By:";
cout<<"\n\t\t\t\t M. Faizan ";
cout<<"\n\t\t\t\t M. Ihtisham ";

cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";

getch();

main_menu();

	return 0;
}

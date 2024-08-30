#include <iostream>
#include <stdexcept>
#include <ctime>
using namespace std;
class admin
{
private:
    string user_name = "admin";
    string password = "admin";

public:
    bool login(string user, string pass);
};

class Node
{
public:
    int id;
    string flightNumber;
    string departureAirport;
    string arrivalAirport;
    string departureDate;
    string arrivalDate;
    int capacity;
    int availableSeats;
    Node *next;

    Node(int id, string flightNumber, string departureAirport, string arrivalAirport, string departureDate, string arrivalDate, int capacity, int availableSeats)
    {
        this->id = id;
        this->flightNumber = flightNumber;
        this->departureAirport = departureAirport;
        this->arrivalAirport = arrivalAirport;
        this->departureDate = departureDate;
        this->arrivalDate = arrivalDate;
        this->capacity = capacity;
        this->availableSeats = availableSeats;
        next = NULL;
    }
};

class BookedTicketNode
{
public:
    int id;
    string name;
    string phoneNumber;
    string cnic;
    string email;
    string debitCardNumber;
    int debitCardExpiryMonth;
    int debitCardExpiryYear;
    string bookingDate;
    BookedTicketNode *next;

    BookedTicketNode(int id, string name, string phoneNumber, string cnic, string email, string debitCardNumber, int debitCardExpiryMonth, int debitCardExpiryYear, string bookingDate)

    {
        this->id = id;
        this->name = name;
        this->phoneNumber = phoneNumber;
        this->cnic = cnic;
        this->email = email;
        this->debitCardNumber = debitCardNumber;
        this->debitCardExpiryMonth = debitCardExpiryMonth;
        this->debitCardExpiryYear = debitCardExpiryYear;
        this->bookingDate = bookingDate;
        next = NULL;
    }
};

class Stack
{
private:
    static const int MAX_SIZE = 100;
    int top;
    BookedTicketNode *stackArray[MAX_SIZE];

public:
    Stack() : top(-1) {}

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX_SIZE - 1;
    }

    void push(BookedTicketNode *ticket)
    {
        if (isFull())
        {
            throw runtime_error("Stack overflow");
        }
        stackArray[++top] = ticket;
    }

    BookedTicketNode *pop()
    {
        if (isEmpty())
        {
            throw runtime_error("Stack underflow");
        }
        return stackArray[top--];
    }

    BookedTicketNode *peek()
    {
        if (isEmpty())
        {
            throw runtime_error("Stack is empty");
        }
        return stackArray[top];
    }
};

class FlightDAO
{
private:
    Node *head;
    Stack bookedTicketsStack;

public:
    FlightDAO() : head(NULL) {}

    void addFlight(Node *node)
    {
        if (!head)
        {
            head = node;
        }
        else
        {
            Node *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = node;
        }
    }

    Node *getFlightById(int id)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->id == id)
            {
                return temp;
            }
            temp = temp->next;
        }
        throw runtime_error("Flight not found.");
    }

    void updateFlight(Node *node)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->id == node->id)
            {
                temp->availableSeats = node->availableSeats;
                return;
            }
            temp = temp->next;
        }
        throw runtime_error("Flight not found.");
    }

    void displayFlights()
    {
        Node *temp = head;
        while (temp)
        {
            cout << "Flight ID: " << temp->id << endl;
            cout << "Flight Number: " << temp->flightNumber << endl;
            cout << "Departure Airport: " << temp->departureAirport << endl;
            cout << "Arrival Airport: " << temp->arrivalAirport << endl;
            cout << "Departure Date: " << temp->departureDate << endl;
            cout << "Arrival Date: " << temp->arrivalDate << endl;
            cout << "Capacity: " << temp->capacity << endl;
            cout << "Available Seats: " << temp->availableSeats << endl;
            cout << endl;
            temp = temp->next;
        }
    }

    bool isValidDate(string date)
    {
        int year, month, day;
        sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
        if (year < 2023 || year > 2030)
        {
            return false;
        }
        if (month < 1 || month > 12)
        {
            return false;
        }
        if (day < 1 || day > 31)
        {
            return false;
        }
        if ((month == 2 && day > 28) || (month == 4 && day > 30) || (month == 6 && day > 30) || (month == 9 && day > 30) || (month == 11 && day > 30))
        {
            return false;
        }
        return true;
    }

    void bookFlight(int flightId, string name, string phoneNumber, string cnic, string email, string debitCardNumber, int debitCardExpiryMonth, int debitCardExpiryYear, string bookingDate)
    {
        Node *flight = getFlightById(flightId);
        if (flight)
        {
            if (flight->availableSeats > 0)
            {
                if (isValidDate(bookingDate))
                {
                    cout << "Booking flight..." << endl;
                    // simulate payment processing
                    cout << "Payment successful!" << endl;
                    flight->availableSeats--;
                    updateFlight(flight);
                    BookedTicketNode *bookedTicket = new BookedTicketNode(flightId, name, phoneNumber, cnic, email, debitCardNumber, debitCardExpiryMonth, debitCardExpiryYear, bookingDate);
                    bookedTicketsStack.push(bookedTicket);
                    cout << "Flight booked successfully!" << endl;
                }
                else
                {
                    cout << "Invalid booking date. Please try again." << endl;
                }
            }
            else
            {
                cout << "Sorry, no available seats on this flight." << endl;
            }
        }
        else
        {
            cout << "Flight not found." << endl;
        }
    }

    void displayBookedTicketsSummary()
    {
        cout << "Summary Report:" << endl;

        Stack tempStack = bookedTicketsStack;

        while (!tempStack.isEmpty())
        {
            BookedTicketNode *ticket = tempStack.pop();
            cout << "Booking ID: " << ticket->id << endl;
            cout << "Name: " << ticket->name << endl;
            cout << "Email: " << ticket->email << endl;
            cout << "Phone Number: " << ticket->phoneNumber << endl;
            cout << endl;
        }
    }
};
class VNode
{
public:
    int data;
    VNode *next;

    VNode(int value)
    {
        data = value;
        next = NULL;
    }
};

// Function to display the linked list
void displayLinkedList(VNode *head)
{
    VNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << std::endl;
}

int main()
{
    FlightDAO flightDAO;
    int choice;
    string user, pass;
    admin ad;

    do
    {
        system("cls");
        cout << "\t\t\t------------------------------------------" << endl;
        cout << "\t\t\t***Welcome to Flight reservation system***" << endl;
        cout << "\t\t\t------------------------------------------" << endl;
        cout << "\t\t1).Login as Admin" << endl;
        cout << "\t\t2).Login as customer" << endl;
        cout << "\t\t3).Visualize link list" << endl;
        cout << "\t\tPress '0' to exit...";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            cout << "\t\t\t---------------------------" << endl;
            cout << "\t\t\t***Welcome to admin page***" << endl;
            cout << "\t\t\t---------------------------" << endl;
            cout << "\n\t\tEnter username: ";
            cin >> user;
            cout << "\t\tEnter password: ";
            cin >> pass;
            if (ad.login(user, pass))
            {
                do
                {
                    system("cls");
                    cout << "\t\t\t---------------------------" << endl;
                    cout << "\t\t\t***Welcome to admin page***" << endl;
                    cout << "\t\t\t---------------------------" << endl;
                    cout << "\t\t1).Add flight details" << endl;
                    cout << "\t\t2).View available flights" << endl;
                    cout << "\t\t3).View bookings summery report" << endl;
                    cout << "\t\t4).Update Flight details" << endl;
                    cout << "\t\tPress '5' to exit..." << endl;
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                    {
                        system("cls"); // clear the console screen
                        Node *flight = new Node(0, "", "", "", "", "", 0, 0);
                        cout << "Enter flight details:" << endl;
                        cout << "Flight ID: ";
                        cin >> flight->id;
                        cout << "Flight Number: ";
                        cin >> flight->flightNumber;
                        cout << "Departure Airport: ";
                        cin >> flight->departureAirport;
                        cout << "Arrival Airport: ";
                        cin >> flight->arrivalAirport;
                        cout << "Departure Date (YYYY-MM-DD): ";
                        cin >> flight->departureDate;
                        cout << "Arrival Date (YYYY-MM-DD): ";
                        cin >> flight->arrivalDate;
                        cout << "Capacity: ";
                        cin >> flight->capacity;
                        cout << "Available Seats: ";
                        cin >> flight->availableSeats;
                        flightDAO.addFlight(flight);
                        cout << "Flight added successfully!" << endl;
                        system("pause"); // wait for user to press a key
                        break;
                    }
                    case 2:
                    {
                        system("cls"); // clear the console screen
                        flightDAO.displayFlights();
                        system("pause"); // wait for user to press a key
                        break;
                    }
                    case 3:
                    {
                        system("cls"); // clear the console screen
                        flightDAO.displayBookedTicketsSummary();
                        system("pause"); // wait for user to press a key
                        break;
                    }
                    case 4:
                    {
                        system("cls"); // clear the console screen
                        int id;
                        cout << "Enter flight ID: ";
                        cin >> id;
                        Node *flight = flightDAO.getFlightById(id);
                        if (flight)
                        {
                            cout << "Updating flight details for Flight ID: " << flight->id << endl;
                            cout << "Current Flight Number: " << flight->flightNumber << endl;
                            cout << "New Flight Number: ";
                            cin >> flight->flightNumber;
                            cout << "Current Departure Airport: " << flight->departureAirport << endl;
                            cout << "New Departure Airport: ";
                            cin >> flight->departureAirport;
                            cout << "Current Arrival Airport: " << flight->arrivalAirport << endl;
                            cout << "New Arrival Airport: ";
                            cin >> flight->arrivalAirport;
                            cout << "Current Departure Date: " << flight->departureDate << endl;
                            cout << "New Departure Date (YYYY-MM-DD): ";
                            cin >> flight->departureDate;
                            cout << "Current Arrival Date: " << flight->arrivalDate << endl;
                            cout << "New Arrival Date (YYYY-MM-DD): ";
                            cin >> flight->arrivalDate;
                            cout << "Current Capacity: " << flight->capacity << endl;
                            cout << "New Capacity: ";
                            cin >> flight->capacity;
                            cout << "Current Available Seats: " << flight->availableSeats << endl;
                            cout << "New Available Seats: ";
                            cin >> flight->availableSeats;
                            flightDAO.updateFlight(flight);
                            cout << "Flight details updated successfully!" << endl;
                        }
                        else
                        {
                            cout << "Flight not found." << endl;
                        }
                        system("pause"); // wait for user to press a key
                        break;
                    }
                    }
                } while (choice != 5);
            }
            break;
        case 2:
            do
            {
                system("cls");
                cout << "\t\t\t---------------------------------" << endl;
                cout << "\t\t\t***Welcome to Reservation page***" << endl;
                cout << "\t\t\t---------------------------------" << endl;
                cout << "\n\t\t1).View available flights" << endl;
                cout << "\t\t2).Search flight by ID" << endl;
                cout << "\t\t3).Book flight" << endl;
                cout << "\t\t4).Search ticket" << endl;
                cout << "\t\tPress '5' to exit..." << endl;
                cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    system("cls"); // clear the console screen
                    flightDAO.displayFlights();
                    system("pause"); // wait for user to press a key
                    break;
                }
                case 2:
                {
                    system("cls"); // clear the console screen
                    int id;
                    cout << "Enter flight ID: ";
                    cin >> id;
                    Node *flight = flightDAO.getFlightById(id);
                    if (flight)
                    {
                        cout << "Flight ID: " << flight->id << endl;
                        cout << "Flight Number: " << flight->flightNumber << endl;
                        cout << "Departure Airport: " << flight->departureAirport << endl;
                        cout << "Arrival Airport: " << flight->arrivalAirport << endl;
                        cout << "Departure Date: " << flight->departureDate << endl;
                        cout << "Arrival Date: " << flight->arrivalDate << endl;
                        cout << "Capacity: " << flight->capacity << endl;
                        cout << "Available Seats: " << flight->availableSeats << endl;
                    }
                    else
                    {
                        cout << "Flight not found." << endl;
                    }
                    system("pause"); // wait for user to press a key
                    break;
                }
                case 3:
                {
                    system("cls"); // clear the console screen
                    int id;
                    cout << "Enter flight ID: ";
                    cin >> id;
                    string name;
                    cout << "Enter your name: ";
                    cin >> name;
                    string phoneNumber;
                    cout << "Enter your phone number: ";
                    cin >> phoneNumber;
                    string cnic;
                    cout << "Enter your CNIC: ";
                    cin >> cnic;
                    string email;
                    cout << "Enter your email: ";
                    cin >> email;
                    string debitCardNumber;
                    cout << "Enter your debit card number: ";
                    cin >> debitCardNumber;
                    int debitCardExpiryMonth;
                    cout << "Enter your debit card expiry month: ";
                    cin >> debitCardExpiryMonth;
                    int debitCardExpiryYear;
                    cout << "Enter your debit card expiry year: ";
                    cin >> debitCardExpiryYear;
                    string bookingDate;
                    cout << "Enter booking date (YYYY-MM-DD): ";
                    cin >> bookingDate;
                    flightDAO.bookFlight(id, name, phoneNumber, cnic, email, debitCardNumber, debitCardExpiryMonth, debitCardExpiryYear, bookingDate);
                    system("pause"); // wait for user to press a key
                    break;
                }
                case 4:
                {
                    system("cls"); // clear the console screen
                    int id;
                    cout << "Enter booked ticket ID: ";
                    cin >> id;
                    flightDAO.displayBookedTicketsSummary();
                    system("pause"); // wait for user to press a key
                    break;
                }
                }
            } while (choice != 5);
            break;
        case 3:
        {
            // Creating an empty linked list
            VNode *head = NULL;
            VNode *tail = NULL;

            int numNodes;
            cout << "Enter the number of nodes: ";
            cin >> numNodes;

            // Creating the linked list with user input values
            for (int i = 0; i < numNodes; i++)
            {
                int value;
                cout << "Enter the value for node " << i + 1 << ": ";
                cin >> value;

                VNode *newNode = new VNode(value);

                if (head == NULL)
                {
                    head = newNode;
                    tail = newNode;
                }
                else
                {
                    tail->next = newNode;
                    tail = newNode;
                }
            }

            // Displaying the linked list
            displayLinkedList(head);

            // Clean up the memory
            VNode *current = head;
            while (current != NULL)
            {
                VNode *next = current->next;
                delete current;
                current = next;
            }
            cout << "Press any key to continue...." << endl;
            system("pause");
        }
        break;
        }
    } while (choice != 0);

    return 0;
}
bool admin::login(string user, string pass)
{
    if (user_name == user && pass == password)
        return 1;
    else
        return 0;
}

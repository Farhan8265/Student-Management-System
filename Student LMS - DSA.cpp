#include <iostream>
#include <string>
using namespace std;

// Node class representing a single student record
class node
{
	public:
		string name;
	    string rollNo;
	    string className;
	    string semester;
	    string department;
	    string phoneNumber;
	    node* next_add;
};

// Linked list class for managing student records
class Linked_List
{
	public:
		node* head = NULL;
		
		void Insert ()
		{
			// Function to insert a new node
			string n;
			string r;
			string cl;
			string sem;
			string dep;
			string pnum;
			cin.ignore();
			
			// Get input from the user for various fields
			cout << "\n\n Enter Roll No: ";
			getline(cin, r);
	        cout << "\n\n Enter Name: ";
	        getline(cin, n);
	        cout << "\n\n Enter Class: ";
	        getline(cin, cl);
	        cout << "\n\n Enter Semester: ";
	        getline(cin, sem);
	        cout << "\n\n Enter Department: ";
	        getline(cin, dep);
	        cout << "\n\n Enter Phone Number: ";
	        getline(cin, pnum);
	
	        // Create a new node and assign input values to its members
			node* newNode = new node;
	        newNode->rollNo = r;
	        newNode->name = n;
	        newNode->className = cl;
	        newNode->semester = sem;
	        newNode->department = dep;
	        newNode->phoneNumber = pnum;
	        newNode->next_add = NULL;
			
			if (head == NULL)
			{
				// If the linked list is empty, make the new node as the head
				head = newNode;
			}
			else
			{
				// Traverse to the end of the linked list and add the new node
				node* ptr = head;
				while (ptr -> next_add != NULL)
				{
					ptr = ptr -> next_add;
				}
				ptr -> next_add = newNode;
			}
			cout<<"\n\n New Node Inserted Successfully!";
		}
		
		void Search()
		{
			// Function to search for a record based on the roll number
			if (head == NULL)
			{
				cout<<"\n\n Linked List is Empty!";
			}
			else
			{
				string r;
				int found = 0;
				cout<<"\n\n Enter Roll Number for Search: ";
				cin.ignore();
            	getline(cin, r);
				node* ptr = head;
				while (ptr != NULL)
				{
					if (r == ptr -> rollNo)
					{
						// If the roll number matches, display the record
						cout << "\n\n Roll No: " << ptr->rollNo;
	                    cout << "\n\n Name: " << ptr->name;
	                    cout << "\n\n Class: " << ptr->className;
	                    cout << "\n\n Semester: " << ptr->semester;
	                    cout << "\n\n Department: " << ptr->department;
	                    cout << "\n\n Phone Number: " << ptr->phoneNumber << endl;
						found++;
					}
					ptr = ptr -> next_add;
				}
				if (found == 0)
				{
					cout<<"\n\n The Roll Number "<<r<<" Not Found.";
				}
			}
		}
		
		void Count()
		{
			// Function to count the number of nodes/records in the linked list
			if (head == NULL)
			{
				cout<<"\n\n Linked List is Empty!";
			}
			else
			{
				int c;
				c=0;
				node* ptr = head;
				while (ptr != NULL)
				{
					c++;
					ptr = ptr -> next_add;
				}
				cout<<"\n\n Total No. of Nodes: "<<c<<endl;
			}
		}
		
		void Update()
		{
			// Function to update a record based on the roll number
			if (head == NULL)
			{
				cout<<"\n\n Linked List is Empty!";
			}
			else
			{
				string r;
				int found = 0;
				cout<<"\n\n Enter Roll Number for Update: ";
				cin.ignore();
            	getline(cin, r);
				node* ptr = head;
				while (ptr != NULL)
				{
					if (r == ptr -> rollNo)
					{
						// Update the fields of the matched record
	                    cout << "\n\n Enter New Roll No: ";
	                    getline(cin, ptr->rollNo);
	                    cout << "\n\n Enter Name: ";
	                    getline(cin, ptr->name);
	                    cout << "\n\n Enter Class: ";
	                    getline(cin, ptr->className);
	                    cout << "\n\n Enter Semester: ";
	                    getline(cin, ptr->semester);
	                    cout << "\n\n Enter Department: ";
	                    getline(cin, ptr->department);
	                    cout << "\n\n Enter Phone Number: ";
	                    getline(cin, ptr->phoneNumber);
	                    cout << "\n\n Record Updated Successfully!";
	                    found++;
					}
					ptr = ptr -> next_add;
				}
				if (found == 0)
				{
					cout<<"\n\n The Updated Roll Number "<<r<<" Not Found.";
				}
			}
		}
		
		void Del()
		{
			// Function to delete a record based on the roll number
			if (head == NULL)
			{
				cout<<"\n\n Linked List is Empty!";
			}
			else
			{
				string r;
				int found = 0;
				cout<<"\n\n Enter Roll Number for Deletion: ";
				cin.ignore();
            	getline(cin, r);
				if (r == head -> rollNo)
				{
					// If the head node matches the roll number, update the head and delete the node
					node* ptr = head;
					head = head -> next_add;
					cout<<"\n\n Record Deleted Successfully!";
					found ++;
					delete ptr;
				}
				else
				{
					// Traverse the linked list to find the node to be deleted
					node* prev = head;
					node* ptr = head -> next_add;
					while (ptr != NULL)
					{
						if (r == ptr -> rollNo)
						{
							// If a non-head node matches the roll number, delete it
							prev -> next_add = ptr -> next_add;
							cout<<"\n\n Record Deleted Successfully!";
							found ++;
							delete ptr;
							break;
						}
						prev = ptr;
						ptr = ptr -> next_add;
					}
				}
				if (found == 0)
				{
					cout<<"\n\n The Deleted Roll Number "<<r<<" Not Found.";
				}
			
			}	
		}
		
		void Display ()
		{
			// Function to display all the records in the linked list
			if (head == NULL)
			{
				cout<<"\n\n Linked List is Empty!";
			}
			else
			{
				node* ptr = head;
				while (ptr != NULL)
				{
					cout << "\n\n Roll No: " << ptr->rollNo;
	                cout << "\n\n Name: " << ptr->name;
	                cout << "\n\n Class: " << ptr->className;
	                cout << "\n\n Semester: " << ptr->semester;
	                cout << "\n\n Department: " << ptr->department;
	                cout << "\n\n Phone Number: " << ptr->phoneNumber<<endl;
	                ptr = ptr->next_add;
				}
			}
		}
};

int main ()
{
	Linked_List obj;
	int choice;
	while (true)
	{
		// Display menu and get user choice
		system ("cls");
		cout<< "\t\t\t\t\tWELCOME TO NUML STUDENT MANAGEMENT SYSTEM"<<endl;
		cout<<"                                       -------------------------------------------"<<endl;
		cout<<"\n\n 1. Insert Record";
		cout<<"\n\n 2. Search Record";
		cout<<"\n\n 3. Count Nodes";
		cout<<"\n\n 4. Update Record";
		cout<<"\n\n 5. Delete Record";
		cout<<"\n\n 6. Display All Record";
		cout<<"\n\n 7. Exit";
		cout<<"\n\n\n Enter Your Choice: ";
		cin>>choice;
		switch (choice)
		{
			// Handle different choices by calling the appropriate functions
			case 1:
				system ("cls");
				obj.Insert();
				break;
			case 2:
				system ("cls");
				obj.Search();
				break;
			case 3:
				system ("cls");
				obj.Count ();
				break;
			case 4:
				system ("cls");
				obj.Update();
				break;
			case 5:
				system ("cls");
				obj.Del();
				break;
			case 6:
				system ("cls");
				obj.Display();
				break;
			case 7:
				exit (0);
			default:
				cout<<"\n\n\n Invalid Choice!";
		}
    	
		cin.ignore();
        cout << "\n\n Press Enter to continue...";
        cin.get();
	}
	return 0;
}


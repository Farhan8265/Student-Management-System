#include<iostream>
using namespace std;
string arr1 [100], arr2 [100], arr3 [100], arr4 [100], arr5 [100], arr6 [100];
int total = 0;
void enter ()
{
	int choice;
	string data;
	cout<< "How many students you want to Enter: ";
	cin>>choice;
	if (total==0)
	{
		total = total + choice;
	
	for (int a=0; a<choice; a++)
	{
		cout<< "\nEnter Data of Student: "<<a+1<<endl<<endl;
		cout<< "Enter Name: ";
		getline(cin>>ws, arr1[a]);
		cout<< "Enter Roll No: ";
		getline(cin>>ws, arr2[a]);
		cout<< "Enter Class: ";
		getline(cin>>ws, arr3[a]);
		cout<< "Enter Semester: ";
		getline(cin>>ws, arr4[a]);
		cout<< "Enter Department: ";
		getline(cin>>ws, arr5[a]);
		cout<< "Enter Contact Number: ";
		getline(cin>>ws, arr6[a]);
	}	
	}
	else
	{
		for (int a=total; a<(total+choice); a++)
	{
		cout<< "\nEnter Data of Student: "<<a+1<<endl<<endl;
		cout<< "Enter Name: ";
		cin>>arr1[a];
		cout<< "Enter Roll No: ";
		cin>>arr2[a];
		cout<< "Enter Class: ";
		cin>>arr3[a];
		cout<< "Enter Semester: ";
		cin>>arr4[a];
		cout<< "Enter Department: ";
		cin>>arr5[a];
		cout<< "Enter Contact Number: ";
		cin>>arr6[a];
	}
		total = total + choice;
	}
}
void show ()
{
	if (total==0)
	{
		cout<< "No Data is Entered"<<endl;
	}
	else
	{
		for (int a=0; a<total; a++)
	{
		cout<< "\nData of Student: "<<a+1<<endl<<endl;
		cout<< "Student Name: "<<arr1[a]<<endl;
		cout<< "Roll No: "<<arr2[a]<<endl;
		cout<< "Class: "<<arr3[a]<<endl;
		cout<< "Semester: "<<arr4[a]<<endl;
		cout<< "Department: "<<arr5[a]<<endl;
		cout<< "Contact Number: "<<arr6[a]<<endl;
	}
}
}
void search ()
{
	if (total==0)
	{
		cout<< "No Data is Entered"<<endl;
	}
	else
	{
	string rollno;
	cout<< "Enter Roll Number of student which you want to search: ";
	cin>>rollno;
	
	for (int a=0; a<total; a++)
	{
		if (rollno==arr2[a])
		{
		cout<< "\nData of Student: "<<a+1<<endl<<endl;
		cout<< "Student Name: "<<arr1[a]<<endl;
		cout<< "Roll No: "<<arr2[a]<<endl;
		cout<< "Class: "<<arr3[a]<<endl;
		cout<< "Semester: "<<arr4[a]<<endl;
		cout<< "Department: "<<arr5[a]<<endl;
		cout<< "Contact Number: "<<arr6[a]<<endl;
		}
	}
}
}
void update ()
{
	if (total==0)
	{
		cout<< "No Data is Entered"<<endl;
	}
	else
	{
	string rollno;
	cout<< "Enter Roll Number of student which you want to search: ";
	cin>>rollno;
	
	for (int a=0; a<total; a++)
	{
		if (rollno==arr2[a])
		{
		cout<< "\nPrevious Data"<<endl;
		cout<< "Data of Student: "<<a+1<<endl<<endl;
		cout<< "Student Name: "<<arr1[a]<<endl;
		cout<< "Roll No: "<<arr2[a]<<endl;
		cout<< "Class: "<<arr3[a]<<endl;
		cout<< "Semester: "<<arr4[a]<<endl;
		cout<< "Department: "<<arr5[a]<<endl;
		cout<< "Contact Number: "<<arr6[a]<<endl;
		cout<< "\nEnter New Data"<<endl;
		cout<< "Enter Name: ";
		getline(cin>>ws, arr1[a]);
		cout<< "Enter Roll No: ";
		getline(cin>>ws, arr2[a]);
		cout<< "Enter Class: ";
		getline(cin>>ws, arr3[a]);
		cout<< "Enter Semester: ";
		getline(cin>>ws, arr4[a]);
		cout<< "Enter Department: ";
		getline(cin>>ws, arr5[a]);
		cout<< "Enter Contact Number: ";
		getline(cin>>ws, arr6[a]);
		}
	}
}
}
void deletedata ()
{
	if (total==0)
	{
		cout<< "No Data is Entered"<<endl;
	}
	else
	{
	int b;
	cout<< "Press 1 to Delete All Record "<<endl;
	cout<< "Press 2 to Delete a Specific Record "<<endl;
	cin>>b;
	if (b==1)
	{
		total=0;
		cout<< "All Record is Deleted"<<endl;
		
	}
	else (b==2);
	{
		string rollno;
		cout<< "Enter the Roll Number of specific record to be deleted: "<<endl;
		cin>>rollno;
		
		for (int a=0; a<total; a++)
		{
			if (rollno==arr2[a])
			{
				for (int c=a; c<total; c++)
				{
					arr1[c]=arr1[c+1];
					arr2[c]=arr2[c+1];
					arr3[c]=arr3[c+1];
					arr4[c]=arr4[c+1];
					arr5[c]=arr5[c+1];
					arr6[c]=arr6[c+1];
				}
				total--;
				cout<< "Your Required Record is Deleted..."<<endl;
			}
		}
	}
}
}

int main ()
{
	int value;
	while (true)
	{
	cout<< "\t\t\t\tWELCOME TO NUML STUDENT MANAGEMENT SYSTEM"<<endl;
	cout<< "\nPress 1 to Enter Data"<<endl;
	cout<< "Press 2 to Show Data"<<endl;
	cout<< "Press 3 to Search Data"<<endl;
	cout<< "Press 4 to Update Data"<<endl;
	cout<< "Press 5 to Delete Data"<<endl;
	cout<< "Press 6 to Exit"<<endl<<endl;
	cin>>value;
	
	switch (value)
	{
		case 1:
			enter ();
			break;
		case 2:
			show ();
			break;
		case 3:
			search ();
			break;
		case 4:
			update ();
			break;
		case 5:
			deletedata ();
			break;
		case 6:
			exit (0);
			break;
		default:
			cout<< "Invalid Input"<<endl;
			break;
	}
	}
	
}

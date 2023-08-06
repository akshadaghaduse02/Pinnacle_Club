#include<iostream>
#include<string.h>
using namespace std;

class Student
{
	public:
		char name[20];
		int prn;
		Student(char *p , int a)
		{
			strcpy(name , p);
			prn = a;
		}
		Student()
		{
			
		}
		void getstudent()
		{
			cin.ignore(1);
			cout<<"\nEnter Name : ";
			cin.getline(name,20);
			cout<<"\nEnter Prn : ";
			cin>>prn;
		}
		void showdata()
		{
			cout<<"\nName of Student = "<<name;
			cout<<"\nPRN No of Student  = "<<prn;
		}
};
class Node
{
	public:
		Student Std;
		Node *next;
		Node()
		{
			next = NULL;
		}
		Node(Student T)
		{
			Std = T;
			next = NULL;
		}
		~Node()
		{
			cout<<"\n destroyed ";
		}
};
class SLLPinnacle
{
	Node *head;
	public:
		SLLPinnacle()
		{
			head = NULL;
		}
		void addatbeg(Student s);
		void addatend(Student s);
		void addmember();
		void show(); 
		int count();
		void delbyprn(int r);
		void addstudent()
		{
			Student Std;
			Std.getstudent();
			addatend(Std);
		}
		void addpresident()
		{
			Student Std;
			cout<<"\nEnter President information : ";
			Std.getstudent();
			addatbeg(Std);
		}
		void addsecretary()
		{
			Student Std;
			cout<<"\nEnter secretary information : ";
			Std.getstudent();
			addatend(Std);
		}
		void showpresec()
		{
			Node *p;
			p = head;
			if(head!=NULL)
			{
				cout<<"\n president : ";
				p->Std.showdata();
				while(p->next!=NULL)
				{
					p = p->next;
				}
				cout<<"\n Secretary : ";
				p->Std.showdata();
			}
			else
			{
				cout<<"\n list is empty ";
			}
		}
};
void SLLPinnacle::addatbeg(Student s)
{
	Node * p;
	p = new Node(s);
	if(head == NULL)
	{
		head = p;
	}
	else
	{
		p -> next = head;
		head = p;
	}
}
void SLLPinnacle::addatend(Student s)
{
	Node * p = new Node(s);
	if(head == NULL)
	{
		head = p;
	}
	else
	{
		Node * q = head;
		while( q -> next != NULL)
		{
			q = q -> next;
		}
		q -> next = p;	
	}
}
int SLLPinnacle::count()
{
	int c;
	Node * p = head;
	while(p != NULL)
	{
		c++;
		p = p -> next;
	}
	return c;
	
}
void SLLPinnacle::show()
{	
	Node * p = head;
	while(p != NULL)
	{
    	p -> Std.showdata();	
    	p = p -> next;
	}
}
void SLLPinnacle :: delbyprn(int r)
{
	if(head == NULL)
	{
		return;
	}
	else
	{
		Node * p = head;
		Node * q;
		while(p != NULL)
		{
		
			if(p ->Std.prn == r)
			{
				
				q -> next =  p -> next;
				delete p;
			}
			q = p;
			p = p -> next;
		}
	}
}
int main()
{
	SLLPinnacle Second ,Third , Fourth , pinnacle;
	int year , choice;
	while(1)
	{
		cout<<"\n Enter your Choice : ";
		cout<<"\n Enter 1 to add member";
		cout<<"\n Enter 2 to Disply List ";
		cout<<"\n Enter 3 to count all the student";
		cout<<"\n Enter 4 to add president in a list";
		cout<<"\n Enter 5 to add secretary in a list";
		cout<<"\n Enter 6 to disply president and secretary list ";
		cout<<"\n Enter 7 to delete member by PRN No  ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\nWhich year Student you want to add : ";
				cout<<"\n1 for First year ";
				cout<<"\n2 for second year";
				cout<<"\n3 for Third year";
				cout<<"\n4 for Fourth year  ";
				cin>>year;
				switch(year)
				{
					case 1:
						cout<<"\nFirst year student not allowed ";
						break;
					case 2:
						Second.addstudent();
						break;
					case 3:
						Third.addstudent();
						break;
					case 4:
						Fourth.addstudent();
						break;
					default:
						cout<<"Invalid year";
				}
				break;
			case 2:
				cout<<"\nWhich year Student you want disply : ";
				cout<<"\n1 for First year ";
				cout<<"\n2 for second year";
				cout<<"\n3 for Third year";
				cout<<"\n4 for Fourth year  ";
				cin>>year;
				switch(year)
				{
					case 1:
						cout<<"\nFirst year student not allowed ";
						break;
					case 2:
						Second.show();
						break;
					case 3:
						Third.show();
						break;
					case 4:
						Fourth.show();
						break;
					default:
						cout<<"Invalid year";
				}
				break;
			case 3:
				cout<<+Second.count() + Third.count() +Fourth.count();
				break;
			case 4:   //president
				cout<<"\nList to add president : ";
				cout<<"\n1 for First year ";
				cout<<"\n2 for second year";
				cout<<"\n3 for Third year";
				cout<<"\n4 for Fourth year  ";
				cin>>year;
				switch(year)
				{
					case 1:
						cout<<"\nFirst year student not allowed ";
						break;
					case 2:
						Second.addpresident();
						break;
					case 3:
						Third.addpresident();
						break;
					case 4:
						Fourth.addpresident();
						break;
					default:
						cout<<"Invalid year";
				}
				break;
			case 5:    //secretary
				cout<<"\nList to add secretary : ";
				cout<<"\n1 for First year ";
				cout<<"\n2 for second year";
				cout<<"\n3 for Third year";
				cout<<"\n4 for Fourth year  ";
				cin>>year;
				switch(year)
				{
					case 1:
						cout<<"\nFirst year student not allowed ";
						break;
					case 2:
						Second.addsecretary();
						break;
					case 3:
						Third.addsecretary();
						break;
					case 4:
						Fourth.addsecretary();
						break;
					default:
						cout<<"Invalid year";
				}
				break;	
			case 6:
				Second.showpresec();
				Third.showpresec();
				Fourth.showpresec();
				break;
				
			case 7:
				int k;
				cout<<"\nWhich year Student you want to delete: ";
				cout<<"\n1 for First year ";
				cout<<"\n2 for second year";
				cout<<"\n3 for Third year";
				cout<<"\n4 for Fourth year  ";
				cin>>year;
				switch(year)
				{
					case 1:
						cout<<"\nFirst year student not have here";
						break;
					case 2:
						cout<<"\n\nEnter PRN number to delete = ";
	                    cin>>k;
						Second.delbyprn(k);
						break;
					case 3:
						cout<<"\n\nEnter PRN number to delete = ";
	                    cin>>k;
						Third.delbyprn(k);
						break;
					case 4:
						cout<<"\n\nEnter PRN number to delete = ";
	                    cin>>k;
						Fourth.delbyprn(k);
						break;
					default:
						cout<<"Invalid year";
				}
				break;	
				
			default:
				cout<<"Invalid choice";
				break;
					
		}
	}
	return 0;
}

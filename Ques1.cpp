#include<iostream>
#include<stdio.h>
#include <fstream>
#include <string>
#include<cmath>
#include <sstream>
using namespace std;
class vehicle
{
private:
struct info
{
string vehicle_no="";
string first_name="",last_name="";
int age;
string gender="";
string address="";
};
public:
struct info data[2000];
int k=1;

vehicle()
{
int i=0;
            ifstream file("A4-Q1.csv"); 
	    if (!file.is_open()) 
	    {
		cout<< "Error opening file." <<endl;
		return ;
	    }
	    string line;
	    while (getline(file, line)) 
	    {
		stringstream ss(line);
		string field;
		if(k==1)
		{
		k=0;
		continue;
		}
		else
		{
	        getline(ss,field,',');
	        data[i].vehicle_no=field+',';
	        getline(ss,field,',');
	        data[i].vehicle_no+=field;
	        getline(ss,field,',');
	        data[i].first_name=field;
	        getline(ss,field,',');
	        data[i].last_name=field;
	        getline(ss,field,',');
	        data[i].age=stoi(field);
	        getline(ss,field,',');
	        data[i].gender=field;
	        getline(ss,field,',');
	        data[i].address=field;
	       i++;
	      }
	    }
	k=i;	      
	file.close();
	     }
void add()
{
cout<<"Enter the vehicle no: ";
cin>> data[k].vehicle_no;
cout<<"Enter the First name. ";
 cin>>data[k].first_name;
cout<<"Enter the Last name. ";
  cin>>data[k].last_name;
cout<<"Enter the age. ";
    cin>>data[k].age;
cout<<"Enter the gender. ";
  cin>>data[k].gender;
cout<<"Enter the address. ";
 cin>>data[k].address;
 k++;
}
void print()
{
for(int i=0;i<k;i++)
{
cout<<i<<"  "<<data[i].vehicle_no<<"  "<<data[i].first_name<<"  "<<data[i].last_name<<"  "<< data[i].age<<"  "<<data[i].gender<<"  "<<data[i].address<<endl;

}
}
void change(string vehicle_no)
{
int k1=0;
for(int i=0;i<k;i++)
{
if(data[i].vehicle_no==vehicle_no)
{
int choice;
cout<<"Which change you want to perform in the database "<<endl;
cout<<"Enter 1 for editing first name "<<endl;
cout<<"Enter 2 for editing last name "<<endl;
cout<<"Enter 3 for editing age "<<endl;
cout<<"Enter 4 for editing gender"<<endl;
cout<<"Enter 5 for editing address"<<endl;
cout<<"Enter the choice : ";
cin>>choice;
switch(choice)
{
case 3: 
{
cout<<"Enter the new age : ";
cin>>data[i].age;
break;
}
case 1:
{
cout<<"Enter the First name : ";
cin>>data[i].first_name;
break;
}
case 2:
{
cout<<"Enter the last name : ";
cin>>data[i].last_name;
break;
}
case 4:
{
cout<<"Enter the gender : ";
cin>>data[i].gender;
break;
}
case 5:
{
cout<<"Enter the address : ";
cin>>data[i].address;
}
default :
{
cout<<"Wrong choice "<<endl;
}
}
k1=1;
}
}
if(k1==0)
{
cout<<"Wrong choice ,Try again!!";
}
}
};

int main()
{
int choice;
vehicle t1;
while(1)
{
cout<<"Enter 1 to display the info :"<<endl;
cout<<"Enter 2 to enter the vehicle info "<<endl;
cout<<"Enter 3 to get changes in the data"<<endl;
cout<<"Enter any number for exist"<<endl;
cin>>choice;
switch(choice)
{
case 1:
{
cout<<"The existing information is : "<<endl;
t1.print();
break;
}
case 2:
{
cout<<"Enter the info : "<<endl;
t1.add();
break;
}
case 3:
{
string vehicle_no="";
cout<<"Enter the Vehicle No : ";
cin>>vehicle_no;
t1.change(vehicle_no);
break;
}
case 4:
{
cout<<"Wrong choice , Try again!!";
exit ;
}
}
}
}

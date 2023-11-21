#include<iostream>
#include<stdio.h>
#include <fstream>
#include <string>
#include<cmath>
#include <sstream>
using namespace std;
class traffic_details
{
private :
struct data1
{
string  vehicle_no="";
string report_type="";
string report_loc="";
};
public :
struct data1 info[1000];
int k1=1;
traffic_details()
{
            int i=0;
            ifstream file("A4-Q2.csv"); 
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
		if(k1==1)
		{
		k1=0;
		continue;
		}
		else
		{
	        getline(ss,field,',');
	        info[i].vehicle_no=field+',';
	        getline(ss,field,',');
	        info[i].vehicle_no+=field;
	        getline(ss,field,',');
	        info[i].report_type=field;
	        getline(ss,field,',');
	        info[i].report_loc=field;
	       i++;
	        }
	    }
	k1=i;	      
	file.close();
	     }
void print()
{
for(int i=0;i<k1;i++)
cout<<i<<"  "<<info[i].vehicle_no<<"  "<<info[i].report_type<<"  "<<info[i].report_loc<< endl;
}
void add()
{
int choice;
cout<<"Enter the vehicle no : ";
cin>>info[k1].vehicle_no;
cout<<"Enter the Type of report : ";
cin>>info[k1].report_type;
cout<<"Report location : ";
cin>>info[k1].report_loc;
k1++;
}
void change(string vehicle_no)
{
int c=0,choice;
for(int i=0;i<k1;i++)
{
if(info[i].vehicle_no==vehicle_no)
{
c=1;
cout<<"Enter 1 to change the vehicle no "<<endl;
cout<<"Enter 2 to change the Report type "<<endl;
cout<<"Enter 3 to change the report_loc "<<endl;
cout<<"Enter any digit to return to the main menu"<<endl;
cout<<"Enter the choice : ";
cin>>choice;
switch(choice)
{
case 1:
{
cout<<"Enter the new vehicle no : ";
cin>>info[i].vehicle_no;
break;
}
case 2:
{
cout<<"Enter the new report type : ";
cin>>info[i].report_type;
break;
}
case 3:
{
cout<<"Enter the new evidence location : ";
cin>>info[i].report_loc;
break;
}
default:
{
cout<<"Wrong choice,Try again!!";
return ;
}
}
}
}
if(c==0)
{
cout<<"Wrong vehicle no ,Better choice next time "<<endl;
return ;
}
}

};
int main()
{
int choice;
traffic_details t1;
while(1)
{
cout<<"Enter 1 to print the case data : "<<endl;
cout<<"Enter 2 to change the data in the file : "<<endl;
cout<<"Enter any digit for exist "<<endl;
cout<<"Enter the choice : ";
cin>>choice;
switch(choice)
{
case 1:
{
cout<<"The existing data is : ";
t1.print();
break;
}
case 2:
{
string vehicle_no="";
cout<<"Please enter the vehicle no. to which you want to change the details : ";
cin>>vehicle_no;
t1.change(vehicle_no);
break;
}
case 3:
{
cout<<"Wrong choice,Try again !!"<<endl;
break;
}
}
}
}

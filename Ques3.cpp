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
struct info data[1000];
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
void print()
{
for(int i=0;i<k;i++)
{
cout<<i<<"  "<<data[i].vehicle_no<<"  "<<data[i].first_name<<"  "<<data[i].last_name<<"  "<< data[i].age<<"  "<<data[i].gender<<"  "<<data[i].address<<endl;

}
}
};

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
};
class problem_case: private vehicle ,private traffic_details 
{
private :
struct data2
{
string first_name="";
string last_name="";
int age;
string gender="";
string address="";
};
public :
struct data2 prob[1000];
int k2=1;
problem_case()
{
            int i=0;
            ifstream file("A4-Q3.csv"); 
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
		if(k2==1)
		{
		k2=0;
		continue;
		}
		else
		{
	        getline(ss,field,',');
	        prob[i].first_name=field;
	        getline(ss,field,',');
	        prob[i].last_name=field;
	        getline(ss,field,',');
	        prob[i].age=stoi(field);
	        getline(ss,field,',');
	        prob[i].gender=field;
	        getline(ss,field,',');
	        prob[i].address=field;
	       i++;
	        }
	    }
	k2=i;	      
	file.close();
	}
string search(string prob)
{
for(int i=0;i<k;i++)
{
if(data[i].vehicle_no==prob)
{
string sec= next_search(data[i].first_name,data[i].last_name,data[i].age,data[i].gender);
if(sec =="0")
{
return data[i].address;
}
else 
{
return sec;
}
}
}
return "Vechicle details not present ";
}
string next_search(string fname,string lname ,int age, string gen)
{
for(int i=0;i<k2;i++)
{
if((prob[i].first_name==fname) && (prob[i].last_name==lname) && (prob[i].age==age) && (prob[i].gender==gen))
{
return prob[i].address;
}
}
return "0";
}	    
void print()
{
for(int i=0;i<k2;i++)
cout<<i<<"  "<<prob[i].first_name<<"  "<<prob[i].last_name<<"  "<< prob[i].age<<"  "<<prob[i].gender<<"  "<<prob[i].address<<endl;
}
};

int main()
{
traffic_details t1;
vehicle v1;
problem_case pb;
string case_no=" ";
cout<<"Input the case no. : ";
cin>>case_no;
cout<<endl<<pb.search(case_no)<<endl;
//cout<<"The existing data is : "<<endl;
//pb.print();
}

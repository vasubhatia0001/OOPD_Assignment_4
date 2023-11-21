#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
class challenge
{
private:
struct evidence 
 {
 string date ;
 string issue ;
 string punishments;
 };
struct person
{
string fname=" ", lname=" ";
int age;
string address;
int case1=0;
evidence e1[100];
};
public:
struct person p1[100];
int k=0;
void find(string fname, string lname)
{
for(int i=0;i<k;i++)
{
if((p1[i].fname==fname)&&(p1[i].lname==lname))
{
int m;
m=p1[i].case1;
cout<<"Issue happened date  : ";
cin>>p1[i].e1[m].date;
cout<<"Issue happened :";
cin>>p1[i].e1[m].issue;
cout<<"Action performed :";
cin>>p1[i].e1[m].punishments;
m++;
p1[i].case1=m;
return ;
}
}
cout<<"Evidence is not present "<<endl;
return insert(fname,lname);
}
void insert (string fname , string lname)
{
cout<<k;
int m=p1[k].case1;
p1[k].fname=fname;
p1[k].lname=lname;
cout<<"Age of the performer : ";
cin>>p1[k].age;
cout<<"Issue happened date  : ";
cin>>p1[k].e1[m].date;
cout<<"Issue happened : ";
cin>>p1[k].e1[m].issue;
cout<<"Action performed : ";
cin>>p1[k].e1[m].punishments;
m++;
p1[k].case1=m;
k++;
}
void print()
{
if(k==0)
{
cout<<"Evidence is not present ";
}
else
{
for(int i=0;i<k;i++)
{
cout<<i+1<<". First name is : "<<p1[i].fname<<endl;
cout<<i+1<<". Last name is : "<<p1[i].lname<<endl;
cout<<i+1<<". Age is : "<<p1[i].age<<endl;
for(int j=0;j<p1[i].case1;j++)
{
cout<<p1[i].case1<<endl;
cout<<"\t\t"<<j+1<<". Case Date : "<<p1[i].e1[j].date<<endl;
cout<<"\t\t"<<j+1<<". Issue Happened : "<<p1[i].e1[j].issue<<endl;
cout<<"\t\t"<<j+1<<". Action Done : "<<p1[i].e1[j].punishments<<endl;
}
}
}
}
};
int main()
{
challenge c1;
int choice;
while(1)
{
cout<<"Enter 1 for inserting the information "<<endl;
cout<<"Enter 2 for printing the information "<<endl;
cout<<"Enter any no for exist "<<endl;
cout<<"Enter the choice : ";
cin>>choice;
switch(choice)
{
case 1:
{
cout<<"Enter the information :- "<<endl;
string fname="",lname="";
cout<<"Enter the first name of the person : ";
cin>>fname ;
cout<<"Enter the last name of the person : ";
cin>>lname ;
c1.find(fname,lname);
break;
}
case 2:
{
cout<<"The existing data is :- "<<endl;
c1.print();
break;
}
default:
{
cout<<"Wrong choice "<<endl;
exit(0);
}
}
}
}




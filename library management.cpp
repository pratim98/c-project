#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdlib.h>
#include<stdio.h>
		      
class book
{
char bnm[30];
int bno;
char ban[30];
public:
void inputbook()
{
cout<<"Enter book name=";
gets(bnm);
cout<<"Enter book number=";
cin>>bno;
cout<<"Enter author name=";
gets(ban);
}
void displaybook()
{
cout<<"\t";
cout<<"\n\nBOOK NAME:"<<bnm;
cout<<"\nBOOK NUMBER:"<<bno;
cout<<"\nBOOK AUTHOR NAME:"<<ban;
}
char* rebnm()
{
return bnm;
}
char* reban()
{
return ban;
}
int rebno()
{
return bno;
}
}obj;
void inputbookfile()
{
clrscr();
ofstream fout;
fout.open("book4.dat",ios::app);
obj.inputbook();
fout.write((char*)&obj,sizeof(obj));
fout.close();
getch();
}                                    
void displaybookfile()
{
clrscr();
ifstream fin;
fin.open("book4.dat",ios::in);
while(fin.read((char*)&obj,sizeof(obj)))
{
obj.displaybook();
}
fin.close();
getch();
}
void modify_book()
{
	int n;
	int found=0;
	clrscr();
	cout<<"\n\n\tMODIFY BOOK REOCORD.... ";
	cout<<"\n\n\tEnter The book no. of The book";
	cin>>n;
	fstream fp;
	fp.open("book4.dat",ios::in|ios::out);
	while(fp.read((char*)&obj,sizeof(obj)))
	{
		if(obj.rebno()==n)
		{
			obj.displaybook();
			cout<<"\nEnter The New Details of book"<<endl;
			obj.inputbook();
			int pos=-1*sizeof(obj);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&obj,sizeof(obj));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}

	fp.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
	getch();

}
void delete_book()
{
	int n,flag=0;
	clrscr();
	fstream file,file1;
	cout<<"\n\n\n\tDELETE BOOK ...";
	cout<<"\n\nEnter The Book no. of the Book You Want To Delete : ";
	cin>>n;
	file.open("book4.dat",ios::in|ios::out);
	file1.open("Temp.dat",ios::out);
	while(file.read((char*)&obj,sizeof(obj)))
	{
		if(obj.rebno()!=n)

			file1.write((char*)&obj,sizeof(obj));
		else
		flag=1;
	}

	file1.close();
	file.close();
	remove("book4.dat");
	rename("Temp.dat","book4.dat");
	if(flag==1)
	cout<<"\n\n\tRecord Deleted ..";
	else
	cout<<"\n\nRecord not found..";
	getch();
}



			
class student
{
char snm[30];
int sadm;
int token;
int stbno;
public:
student()
{
token=0;
}
void enterstudent()
{
cout<<"\n\n";
cout<<"Enter Student Name:\t";
gets(snm);
cout<<"Enter Student Admission Number:\t";
cin>>sadm;
token=0;
}
void displaystudent()
{
cout<<"\n\nSTUDENT NAME:"<<snm;
cout<<"\nSTUDENT ADMISSION NUMBER:"<<sadm;
cout<<"\nBOOK ISSUED:"<<token;
if(token==1)
cout<<"\nBOOK NUMBER:"<<stbno;
}
int resadm()
{
return sadm;
}
	int rettoken()
	{
		return token;
	}

	void addtoken()
	{token=1;}

	void resettoken()
	{token=0;}

       void getstbno(int t)
	{
	stbno=t;
	}
	int restbno()
	{
	return stbno;
	}

}std;//OBJECT CREATED GLOBALLY
void enterstudentfile()
{
clrscr();
ofstream fout;
char ch;
fout.open("student4.dat",ios::out|ios::app);
do
{
std.enterstudent();
fout.write((char*)&std,sizeof(std));
cout<<"\n\nDo you want to add more record ENTER [y/n]"<<endl;
cin>>ch;
}while(ch=='y'||ch=='Y');
fout.close();
getch();
}
void displaystudentfile()
{
clrscr();
ifstream fin;
fin.open("student4.dat",ios::in);
while(fin.read((char*)&std,sizeof(std)))
{
std.displaystudent();
}
fin.close();
getch();
}


void modify_student()
{
	int n;
	int found=0;
	clrscr();
	fstream file;
	cout<<"\n\n\tMODIFY STUDENT RECORD... ";
	cout<<"\n\n\tEnter The admission no. of The student";
	cin>>n;
	file.open("student4.dat",ios::in|ios::out);
	while(file.read((char*)&std,sizeof(std)))
	{
		if(std.resadm()==n)
		{
			std.displaystudent();
			cout<<"\nEnter The New Details of student"<<endl;
			std.enterstudent();
			int pos=-1*sizeof(std);
			file.seekp(pos,ios::cur);
			file.write((char*)&std,sizeof(std));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}

	file.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
	getch();
}
void delete_student()
{
	int n;
	int flag=0;
	clrscr();
	fstream file,file1;
	cout<<"\n\n\n\tDELETE STUDENT...";
	cout<<"\n\nEnter The admission no. of the Student You Want To Delete : ";
	cin>>n;
	file.open("student4.dat",ios::in|ios::out);
	file1.open("Temp1.dat",ios::out);
	//fp.seekg(0,ios::beg);
	while(file.read((char*)&std,sizeof(std)))
	{
		if(std.resadm()!=n)
			file1.write((char*)&std,sizeof(std));
		else
			flag=1;
	}

	file1.close();
	file.close();
	remove("student4.dat");
	rename("Temp1.dat","student4.dat");
	if(flag==1)
		cout<<"\n\n\tRecord Deleted ..";
	else
		cout<<"\n\nRecord not found";
	getch();
}
fstream file,file1;
void book_issue()
{
	int sn,bn;
	int found=0,flag=0;
	clrscr();
	cout<<"\n\nBOOK ISSUE ...";
	cout<<"\n\n\tEnter The student's admission no.";
	cin>>sn;
	file.open("student4.dat",ios::in|ios::out);
	file1.open("book4.dat",ios::in|ios::out);
	while(file.read((char*)&std,sizeof(std)))
	{
	if(std.resadm()==sn)
	{
	found=1;
	if(std.rettoken()==0)
	{
	cout<<"\n\n\tEnter the book no. ";
	cin>>bn;
	while(file1.read((char*)&obj,sizeof(book)))
	{
	if(obj.rebno()==bn)
	{
	obj.displaybook();
	flag=1;
	std.addtoken();
	std.getstbno(obj.rebno());
	int pos=-1*sizeof(std);
	file.seekp(pos,ios::cur);
	file.write((char*)&std,sizeof(student));
	cout<<"\n\n\t Book issued successfully\n\nPlease Note: Write the current date 						in backside of your book and submit within 15 days fine Rs. 5 for each day 							after 15 days period";
	}
	}
	if(flag==0)
	cout<<"Book no does not exist";
	}
	else
	cout<<"You have not returned the last book ";

	}
	}
	if(found==0)
	cout<<"Student record not exist...";
	file.close();
	file1.close();
	getch();
}
void book_deposit()
{
    int sn,bn;
    int found=0,flag=0,day,fine;
    clrscr();
    cout<<"\n\nBOOK DEPOSIT ...";
    cout<<"\n\n\tEnter The student’s admission no.";
    cin>>sn;
    file.open("student4.dat",ios::in|ios::out);
    file1.open("book4.dat",ios::in|ios::out);
    while(file.read((char*)&std,sizeof(std)))
       {
       if(std.resadm()==sn)
       {
       found=1;
       if(std.rettoken()==1)
       {
       while(file1.read((char*)&obj,sizeof(book)))
       {
       if(obj.rebno()==std.restbno())
       {
       obj.displaybook();
       flag=1;
       cout<<"\n\nBook deposited in no. of days";
       cin>>day;
       if(day>15)
       {
       fine=(day-15)*5;
       cout<<"\n\nFine has to deposited Rs. "<<fine;
       }
       std.resettoken();
       int pos=-1*sizeof(std);
       file.seekp(pos,ios::cur);
       file.write((char*)&std,sizeof(std));
       cout<<"\n\n\t Book deposited successfully";
       }
       }
       if(flag==0)
       cout<<"Book no does not exist";
       }
       else
       cout<<"No book is issued..please check!!";
       }
       }
      if(found==0)
	cout<<"Student record not exist...";

  file.close();
  file1.close();
  getch();
  }

void admin()
{
clrscr();
int n;
do
{
clrscr();
cout<<"lllllllllllllllllllllll  ADMINISTRATION MENUE  llllllllllllllllllllllll";
cout<<"\n\n";
cout<<"\n\n\t\t1.TO ENTER NEW STUDENT RECORD";
cout<<"\n";
cout<<"\n\t\t2.TO ENTER NEW BOOK RECORD";
cout<<"\n";
cout<<"\n\t\t3.TO DISPLAY STUDENT INFORMATION";
cout<<"\n";
cout<<"\n\t\t4.TO DISPLAY BOOK INFORMATION";
cout<<"\n";
cout<<"\n\t\t5.TO MODIFY BOOK RECORD";
cout<<"\n";
cout<<"\n\t\t6.TO MODIFY STUDENT RECORD";
cout<<"\n";
cout<<"\n\t\t7.TO DELETE STUDENT RECORD";
cout<<"\n";
cout<<"\n\t\t8.TO DELETE BOOK RECORD";
cout<<"\n";
cout<<"\n\t\t9.TO EXIT ADMIN MENUE"<<endl<<"\t\t\t\t\t";
cin>>n;
switch(n)
{
case 1:enterstudentfile();
break;
case 2:inputbookfile();
break;
case 3:displaystudentfile();
break;
case 4:displaybookfile();
break;
case 5:modify_book();
break;
case 6:modify_student();
break;
case 7:delete_student();
break;
case 8:delete_book();
break;
case 9:getch();
break;
}
}while(n!=9);
}
void main()
{
clrscr();
int ch;
do
{
clrscr();
cout<<"\nllllllllllllllllll SCHOOL  LIBRARY  MANAGMENT lllllllllllllllllllllllllllllll\t";
cout<<"\n\n\n\n\n\n\n\t\t\t1.TO ISSUE BOOK";
cout<<"\n\n";
cout<<"\n\t\t\t2.TO DEPOSIT BOOK";
cout<<"\n\n";
cout<<"\n\t\t\t3.TO ACCES ADMINISTRATIVE DEPARTMENT";
cout<<"\n\n";
cout<<"\n\t\t\t4.TO Exit the program"<<endl<<"\t\t\t\t\t";
cin>>ch;
switch(ch)
{
case 1:book_issue();
break;
case 2:book_deposit();
break;
case 3:admin();
break;
case 4:exit(0);
break;
}
}while(ch!=4);
getch();
}


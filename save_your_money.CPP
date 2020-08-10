#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<process.h>
#include<fstream.h>
#include<stdio.h>
#include<time.h>
#include<stdio.h>
int menu();
void create_usr();
void login();
void border();
void ins();
int has_space(char[]);
int info(char[], char[]="", char[]="", char[]="", char[]="");
int is_empty(char[]);
void ins_file(char[], char[], char[], char[], char[]);
void dashboard(char[], char[], char[], char[]);
int total_amount(char[]);
void dash_info(int, char[], char[], char[], char[]);
void money(char[], char);
void acc_stat(char[]);
void usr_profile(char[], char[], char[], char[]);
void cin_pass(char[]);
void intro();
void load_bar();
char date[9];
void main()
{
	clrscr();
	intro();
	int ch;
	while(ch!=4)
	{
	clrscr();
	ch=menu();
	switch(ch)
	{
		case 1:
			create_usr();
			break;
		case 2:
			login();
			break;
		case 3:
		  //	ins();
			break;
		case 4:
			clrscr();
			cout<<"\nExiting";
			for(int i=0;i<3;i++)
			{
			cout<<".";
			delay(600);
			}
			exit(0);
			break;
		default:
			cout<<"\n\t\t\tWrong choice entered.";
			getch();
			break;
	}
	}
}
//INTRO
//---------------------------------------------------------
void intro()
{
	clrscr();
	cout<<"\n\t\t\t*****************************\n\t\t\t    ----Money Manager----\n\t\t\t*****************************";
	delay(300);
	cout<<"\n\n\n\t\t\t______________________________";
	delay(300);
	cout<<"\n\t\t\tMade By--Shubham Yadav";
	delay(300);
	cout<<"\n\n\t\t\tRoll No.-33";
	delay(300);
	cout<<"\n\n\t\t\tClass-XI C";
	delay(300);
	cout<<"\n\n\nPress any key to continue..." ;
	getch();
}
//---------------------------------------------------------
//MENU FUNCTION
int menu()
{
	clrscr();
	int ch;
	cout<<"\n\t\t===============================================";
	cout<<"\n\n\n\t\t\t1. Create new user.";
	cout<<"\n\n\t\t\t2. Existing User. (Login here)";
	cout<<"\n\n\t\t\t3. Instructions.";
	cout<<"\n\n\t\t\t4. Exit.";
	cout<<"\n\n\n\t\t\tEnter your choice: ";
	cin>>ch;
	return ch;
}

// CREATE USER FUNCTION
//-----------------------------------------------------
void create_usr()
{
	clrscr();
	cout<<"\t\t\t\tCREATE ACCOUNT";
	cout<<"\n\n\t\t";
	for(int i=0;i<50;i++)
		cout<<"=";
	char f_name[41], l_name[40], username[41], password[41], repass[41], ch_usr[41], url[100];
	cout<<"\n\n\t\t\tEnter your first Name: ";
	cin.ignore();
	while(1)
	{
	cin.getline(f_name, 100);
	if(has_space(f_name))
	{
		cout<<"Name cannot have a space in it.";
		cout<<"\nEnter again: ";
		continue;
	}
	else if(is_empty(f_name))
	{
		cout<<"Name cannot be empty.";
		cout<<"\nEnter again: ";
		continue;
	}
	break;
	}
	cout<<"\t\t\tEnter your last name: ";
	while(1)
	{
	cin.getline(l_name, 41);
	if(has_space(l_name))
	{
		cout<<"Name cannot have a space in it.";
		cout<<"\nEnter again: ";
		continue;
	}
		else if(is_empty(l_name))
	{
		cout<<"Name cannot be empty.";
		cout<<"\nEnter again: ";
		continue;
	}
	break;
	}
	cout<<"\n\t\t\tEnter a username: ";
	while(1)
	{
	//cin.ignore();
	cin.getline(username, 100);
	if(has_space(username))
		{
		cout<<"Wrong format.\nEnter again: ";
		continue;
		}
		else if(is_empty(username))
	{
		cout<<"Username cannot be empty.";
		cout<<"\nEnter again: ";
		continue;
	}
	if(info(username))
		{
		cout<<"Username already used.";
		cout<<"Enter again: ";
		continue;
		}
		break;
	}

	strcpy(url, username);
	strcat(url, ".txt");
	//cout<<url;
	cout<<"\n\t\t\tEnter your password: ";
	while(1)
	{
	cin_pass(password);
	if(is_empty(password))
	{
		cout<<"Password cannot be empty.";
		cout<<"\nEnter again: ";
		continue;
	}
	else if(has_space(password))
	{
		cout<<"Password cannot have space in it.";
		cout<<"\nEnter again: ";
		continue;
	}
	break;
	}
	cout<<"\n\t\t\tReenter your password: ";
	cin_pass(repass);
	while(strcmp(repass, password))
	{
		cout<<"Password didn't match.";
		cout<<"\nEnter again: ";
		cin_pass(password);
		cout<<"Re enter your password: ";
		cin_pass(repass);
	}
	ins_file(username, password, url, f_name, l_name);
	cout<<"\n\n\t\t\tUser Registered.";
	getch();
}
//-------------------------------------------------------
//LOGIN
void login()
{
	clrscr();
	char username[41], password[41], ch_pass[41], url[100], fname[41], lname[41];
	cout<<"\n\t\t\t\tLOGIN";
	cout<<"\n\n\t\t==========================================";
	cout<<"\n\n\t\tEnter your username: ";
	cin.ignore();
	cin.getline(username, 41);
	if(info(username, ch_pass, url, fname, lname))
	{
		cout<<"\n\t\tEnter password: ";
		cin_pass(password);
		if(!strcmp(password,ch_pass))
		{
			load_bar();
			dashboard(fname, lname, username, url);
		}
		else
			cout<<"\t\tWrong password.";
	}
	else
		cout<<"\n\t\tNo user with this username.";
	getch();
	}
//-------------------------------------------------------
// HAS SPACE FUNCTION
int has_space(char username[])
{
	for(int i=0;username[i]!='\0';i++)
	{
		if(username[i]==' ')
		{
			return 1;
		}
	}
	return 0;
}

//--------------------------------------------------------
//USER INFO
int info(char username[],char ch_pass[41], char ch_url[100], char ch_name[], char ch_lname[])
{
	int ch;
	char ch_usr[41];
	ifstream check;
	check.open("users.txt");
	while(check>>ch_usr>>ch_pass>>ch_url>>ch_name>>ch_lname)
	{
		if(!strcmp(ch_usr, username))
		{
			check.close();
			return 1;
		}
	}
			check.close();
			return 0;
}

//-----------------------------------------------------------
//Insert into file
void ins_file(char usr_name[], char pass[], char url[], char usr[], char usr1[])
{
	ofstream input("users.txt", fstream::app);
	input<<usr_name<<' '<<pass<<' '<<url<<' '<<usr<<' '<<usr1<<endl;
	input.close();
	ofstream create(url);
  //	create<<0<<" "<<"CREDIT"<<" "<<"NOTHING"<<endl;
	create.close();
}

//-----------------------------------------------------------
//DASHBOARD
void dashboard(char fname[], char lname[], char username[], char url[])
{
	clrscr();
	_strdate(date);
	int ch;
	cout<<"Welcome, "<<fname;
	cout<<"\t\t Dashboard ";
	cout<<"\t\t\t "<<date;
	cout<<"\n";
	for(int i=0;i<75;i++)
		cout<<"_";
	cout<<endl<<endl;
	for(i=0;i<75;i++)
		cout<<"=";
	cout<<"\nTotal amount left in your account is Rs. "<<total_amount(url);
	cout<<endl;
	for(i=0;i<75;i++)
		cout<<"=";
	cout<<endl;
	cout<<"\n\n\t1. Add Money.\t\t\t2. Withdraw.";
	cout<<"\n\n\t3. Account Statement\t\t4. User Profile.";
	cout<<"\n\n\t5. LOGOUT.";
	cout<<"\n\n\t Choose from following list: ";
	cin>>ch;
	dash_info(ch, fname, lname, username, url);
}

//-----------------------------------------------------------
//Total Amount Calculator
int total_amount(char url[])
{
	int t_c=0, t_d=0, amount;
	char type[10], date[9], onwhich[20];
	ifstream sum(url);
	while(sum>>amount>>type>>date>>onwhich)
	{
		if(!strcmp(type, "CREDIT"))
			t_c+=amount;

		else if(!strcmp(type, "DEBIT"))
			t_d+=amount;
	}
	sum.close();
	return t_c-t_d;;
}

//-----------------------------------------------------------
//DASHBOARD INFORMATION
void dash_info(int ch, char fname[], char lname[], char username[], char url[])
{

	clrscr();
	switch(ch)
	{
		case 1:
			money(url, 'c');
			dashboard(fname, lname, username, url);
			break;
		case 2:
			money(url, 'd');
			dashboard(fname, lname, username, url);
			break;
		case 3:
			acc_stat(url);
		  dashboard(fname, lname, username, url);
		  break;
		case 4:
			usr_profile(fname, lname, username, url);
			dashboard(fname, lname, username, url);
			break;
		case 5:
			menu();
			break;
		default:
			cout<<"\n\nWrong input.";
			cout<<"\nEnter again";
			for(int i=0;i<3;i++)
			{
				cout<<".";
				delay(600);
			}
			dashboard(fname, lname, username, url);
			break;
	}
}
//---------------------------------------------------------
// MONEY
void money(char url[], char ch)
{
	clrscr();
	int amount;
	char on_which[20];
	_strdate(date);
	cout<<"Enter amount: ";
	cin>>amount;
	ofstream input(url, fstream::app);
	if(ch=='c')
	{
		input<<amount<<" "<<"CREDIT"<<" "<<date<<" "<<"CREDIT"<<endl;
		cout<<"Rs. "<<amount<<" added Successfully.";
		getch();
	}
	else if(ch=='d')
	{
		if(amount<=total_amount(url))
		{
			cout<<"On which you want to expend: ";
			cin>>on_which;
			input<<amount<<" "<<"DEBIT"<<" "<<date<<" "<<on_which<<endl;
			cout<<"Rs. "<<amount<<" withdrawn successfully." ;
			getch();
		}
		else
		{
			cout<<"Insufficient money.";
			cout<<"\nYou cannot withdraw more than "<<total_amount(url)<<" rupees";
			getch();
		}
	}
	input.close();
}

//---------------------------------------------------------------
//ACCOUNT STATEMENT
void acc_stat(char url[])
{
	int amount;
	char type[10], on_which[20];
	ifstream data(url);
	cout<<"\n\tAmount\t\tType\t\tDate\t\tOn Which\n";
	for(int i=0;i<75;i++)
		cout<<"_";
	while(data>>amount>>type>>date>>on_which)
	{
		if(!strcmp(type, "CREDIT"))
			strcpy(on_which, "");
		cout<<"\n\tRs. "<<amount<<"\t\t"<<type<<"\t\t"<<date<<"\t"<<on_which;
	}
	data.close();
	getch();
}

//---------------------------------------------------------------
//PASSWORD INPUT
void cin_pass(char pass[])
{
	char ch;
	int i=0;
	while(ch!=13)
	{
		ch=getch();
		if(ch!=8)
		{
			pass[i]=ch;
			i++;
		}
		else if(ch==8)
			if(i>0)
			i--;
	}
	pass[i-1]='\0';
}
//--------------------------------------------------------------
//EMPTY STRING CHECKER
int is_empty(char ch[])
{
	if(!strcmp(ch, ""))
		return 1;
	else
		return 0;
}
//--------------------------------------------------------------
//LOADING BAR
void load_bar()
{
	clrscr();

	for(int i=0;i<100;i+=2)
	{
		cout<<"\n\n\n\n\n\n\n\n\n\t";
		cout<<i<<"%"<<endl<<"\t";
		for(int j=0;j<i/2;j++)
		{
		cout<<"|";
		}
		cout<<"\n\t\t\t\tEXTRACTING DATA...";
		delay(100);
		clrscr();
	}
}

//--------------------------------------------------------------
//USER PROFILE
void usr_profile(char name[], char lname[], char username[], char url[])
{
	clrscr();
	cout<<"\t\t\t\tUSER PROFILE";
	cout<<"\n\nName: "<<name<<" "<<lname;
	cout<<"\n\nUsername: "<<username;
	cout<<"\n\nURL: "<<url;
	cout<<"\n\n\n\n Nothing else to show.";
	getch();
}
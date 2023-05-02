#include <iostream> 	//For Basic Input Output 
#include <fstream>		//For Filling
#include <ctime>		//For Current Time
#include <conio.h>      //For Getch
#include <unistd.h>		//For Sleep
#include <windows.h> 	//For Clear Screen & Colouring


using namespace std;

	int pin, pin1=1234, pin2=2468, pin3=1357, option,
	balance=10000,
	withdraw, deposit,
	trans1, trans2, trans3;
	
	string ac_t, ac="0", ac_1="567891234", ac_2="567894321", ac_3="5678998765";
	
	string bank_name, name0, name1="Siraj Dujana", name2="Aaqib Abbasi", name3="Noor Mustafa", store;


void menu();
void balance_inquiry();
void acceed();
void cash_withdrawal();
void deposit_();
void transfer_money();
void change_pin();
void history();
void exit();
void back_func();
void tim();



void menu()
{
	system("color 6");
	cout<<"\n\n\n\t\t\t				  ACCOUNT HOLDER NAME : "<<name0<<endl<<endl<<endl;
	cout<<"\t\t\t				  ==== Welcome At ATM Machine ===="<<endl;
	cout<<"\t\t\t				  ================================"<<endl;
	cout<<"\t\t\t				  *                              *"<<endl;
	cout<<"\t\t\t				  *                              *"<<endl;
	cout<<"\t\t\t				  *     ATM Main Manu Screen     *"<<endl;
	cout<<"\t\t\t				  *                              *"<<endl;
	cout<<"\t\t\t				  *     1. Balance Inquiry       *"<<endl;
	cout<<"\t\t\t				  *     2. Cash Withdrawal       *"<<endl;
	cout<<"\t\t\t				  *     3. Deposit               *"<<endl;
	cout<<"\t\t\t				  *     4. Transfer Money        *"<<endl;
	cout<<"\t\t\t				  *     5. Change Pin            *"<<endl;
	cout<<"\t\t\t				  *     6. Transaction History   *"<<endl;
	cout<<"\t\t\t				  *     0. Exit                  *"<<endl;
	cout<<"\t\t\t				  *                              *"<<endl;
	cout<<"\t\t\t				  *                              *"<<endl;
	cout<<"\t\t\t				  *                              *"<<endl;
	cout<<"\t\t\t				  ================================"<<endl<<endl;
	
	cout<<"\t\t\t				\n\t\t\t				  Please Select Transaction Method "<<endl;
	cout<<"\t\t\t					       "; cin>>option;
	
	switch (option)
	{
		case 0 : exit();
		break;
		case 1 : balance_inquiry();
		break;
		case 2 : cash_withdrawal();
		break;
		case 3 : deposit_();
		break;
		case 4 : transfer_money();
		break;
		case 5 : change_pin();
		break;
		case 6:  history();
		break;
		
		default : 	cout<<"				  You Entered Wrong Number \n				  Please Wait...";
		sleep(4);
		system("cls");
		menu();
	}
}




void balance_inquiry()
{
	system("color B");
	(system("CLS"));
	cout<<endl<<endl<<endl;
	
	cout<<"\t\t\t				TRANSACTION        : Balance Inquiry"<<endl;
	cout<<"\t\t\t				ACCOUNT NAME       : "<<name0<<endl;
	cout<<"\t\t\t				ACCOUNT NUMBER     : "<<ac<<endl;
	cout<<"\t\t\t				AVAILABLE BALANCE  : "<<balance<<endl;
	cout<<"\t\t\t				CARD TYPE          : Mastercard"<<endl;
	cout<<"\t\t\t				WITHDRAW TIME      : "; tim();
	
	back_func();
}

void cash_withdrawal()
{
	system("color C");
	(system("CLS"));
	cout<<"\n\n\n\t\t\t				Enter Withdraw Amount "; cin>>withdraw;
	
	ofstream file("history.txt", ios::app);
	
	if(withdraw<=balance)
	{
		// current Timing
		time_t current_time;
		current_time = time(NULL);
		
		char *tm = ctime(&current_time);
		
		balance = balance-withdraw;
		cout<<endl<<endl<<endl;
		cout<<"\t\t\t				TRANSACTION         : Cash Withdrawal"<<endl;
		cout<<"\t\t\t				ACCOUNT NUMBER      : "<<ac<<endl;
		cout<<"\t\t\t				ACCOUNT HOLDER NAME : "<<name0<<endl;
		cout<<"\t\t\t				AVAILABLE BALANCE   : "<<balance<<endl;
		cout<<"\t\t\t				CARD TYPE           : Debit Mastercard"<<endl;
		cout<<"\t\t\t				WITHDRAW TIME       : "; tim();
		
		file<<"\n\n"<<endl;
		file<<"	WITHDRAW           : "<<withdraw<<endl;
		file<<"	TRANSACTION        : Cash Withdrawal"<<endl;
		file<<"	ACCOUNT NUMBER     : "<<ac<<endl;
		file<<"	ACCOUNT NAME       : "<<name0<<endl;
		file<<"	AVAILABLE BALANCE  : "<<balance<<endl;
		file<<"	CARD TYPE          : Debit Mastercard"<<endl;
		file<<"\tWITHDRAW TIME      : "<<tm<<endl;
		file<<"_________________________________________________________________________________________"<<endl<<endl;
		file.close();
		back_func();
	}
	
	else
	{
		acceed();
	}	
}

void acceed()
{
	(system("CLS"));
	cout<<"\n\n\t\t\t				You Have Not Enough Money\n\t\t\t				Try Again"<<endl;
	cout<<"\n\n\t\t\t				Please Wait..."<<sleep(6)<<"\n\t\t\t				Try Again";
	
	cash_withdrawal();
}

void deposit_()
{
	system("color C");
	(system("CLS"));
	cout<<"\n\n\n\t\t\t				Enter Deposit Amount "; cin>>deposit;
	if (deposit<0)
	{
		cout<<"\n\n\n\t\t\t				Its a Negative number \n\t\t\t				Please Enter Positive number"<<endl;
		cout<<"\n\t\t\t				Please Wait..."<<sleep(4);
		deposit_();
	}
	else
	{
		// current Timing
		time_t current_time;
		current_time = time(NULL);
		
		char *tm = ctime(&current_time);
		
	balance=balance+deposit;
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t				TRANSACTION        : Cash Deposit"<<endl;
	cout<<"\t\t\t				ACCOUNT NUMBER     : "<<ac<<endl;
	cout<<"\t\t\t				ACCOUNT NAME       : "<<name0<<endl;
	cout<<"\t\t\t				AVAILABLE BALANCE  : "<<balance<<endl;
	cout<<"\t\t\t				CARD TYPE          : Debit Mastercard"<<endl;
	cout<<"\t\t\t				WITHDRAW TIME      : "; tim();
	
	ofstream file("history.txt", ios::app);
	file<<"	DEPOSITED AMOUNT   : "<<deposit<<endl;
	file<<"	TRANSACTION        : Cash Deposit"<<endl;
	file<<"	ACCOUNT NUMBER     : "<<ac<<endl;
	file<<"	ACCOUNT NAME       : "<<name0<<endl;
	file<<"	AVAILABLE BALANCE  : "<<balance<<endl;
	file<<"	CARD NAME          : Debit Mastercard"<<endl;
	file<<"\tDEPOSIT TIME       : "<<tm<<endl;
	file<<"_________________________________________________________________________________________"<<endl<<endl;
	file.close();
	back_func();
	}
}

void transfer_money()
{
	    // current Timing
		time_t current_time;
		current_time = time(NULL);
		
		char *tm = ctime(&current_time);
		
	system("color D");
	(system("CLS"));
	cout<<endl<<endl<<endl;
	
	getline(cin,bank_name);
	cout<<"\n\n\n\t\t\t				Enter Bank Name  : "; getline(cin, bank_name);
	wrong:
	cout<<"\n\t\t\t				Enter Account Number : "; cin>>ac_t; cout<<endl;
	
	if (ac_t==ac_2)
	{
		t1:
		cout<<"						Enter Amount You Want To Transfer : "; cin>>trans2; cout<<endl;
		
		ofstream file("history.txt", ios::app);
		file<<endl<<endl;
		file<<"\n\nBank Name          : "<<bank_name<<endl;
		file<<"Transfered Amount  : "<<trans2<<endl;
		file<<"Account Number     : "<<ac_t<<endl;
		file<<"TRANSFER TIME      : "<<tm<<endl;
		file<<"_________________________________________________________________________________________"<<endl<<endl;
		file.close();
		
		
		if (trans2>=balance)
		{
			cout<<"\n\n\t\t\t				You Have Enough Money "<<endl;
			cout<<"\t\t\t				Please Enter Less Than Account Balance";
			goto t1;
		}
		else
		{
			cout<<"\n\t\t\t				\n\t\t\t				Please Wait..."<<sleep(4)<<endl;
			(system("CLS"));
			
			cout<<"\n\n\n\n\n"<<endl<<endl<<endl;
			cout<<"\t\t\t				Money Has Been Transfered "<<endl;
			cout<<"\t\t\t				Thank You For Using Our ATM System "<<endl;
			balance=balance-trans2;
			cout<<"\t\t\t				Your Remaining Balance is : "<<balance<<endl;
			cout<<"\t\t\t				\n\t\t\t				Press Any key to continue"; getch();
			system ("cls");
			menu();	
		}
	}
	else if (ac_t==ac_3)
		{
			
			t2:
			cout<<"\t\t\t				\n\t\t\tEnter Amout You Want To Transfer : "; cin>>trans3;
			
		ofstream file("history.txt", ios::app);
		file<<endl<<endl;
		file<<"\n\nBank Name          : "<<bank_name<<endl;
		file<<"Transfered Amount  : "<<trans3<<endl;
		file<<"Account Number     : "<<ac_t<<endl;
		file<<"TRANSFER TIME      : "<<tm<<endl;
		file<<"_________________________________________________________________________________________"<<endl<<endl;
		file.close();
			
			if (trans3>=balance)
			{
				cout<<"\n\t\t\t				You Have not Enough Money "<<endl;
				cout<<"	\t\t\t			Please Enter Less Than Account Balance";
				goto t2;
			}
			else
			{
				cout<<"\t\t\t				\n\t\t\t				Please Wait..."<<sleep(4)<<endl;
				(system("CLS"));
				cout<<"\t\t\t\n\n\n				Money Has Been Transfered "<<endl;
				cout<<"\t\t\t				Thank You For Using Our ATM System "<<endl;
				balance=balance-trans3;
				cout<<"\t\t\t				Your Remaining Balance is : "<<balance;
				cout<<"\t\t\t				\n\t\t\t				Press Any key to continue"; getch();
				(system("CLS"));
				
				menu();
			}
		}
	
	else if (ac_t==ac_1)
		{
			t3:
			cout<<"\t\t\t				\n\t\t\tEnter Amout You Want To Transfer : "; cin>>trans1;
			
		ofstream file("history.txt", ios::app);
		file<<endl<<endl;
		file<<"\n\nBank Name          : "<<bank_name<<endl;
		file<<"Transfered Amount  : "<<trans1<<endl;
		file<<"Account Number     : "<<ac_t<<endl;
		file<<"TRANSFER TIME      : "<<tm<<endl;
		file<<"_________________________________________________________________________________________"<<endl<<endl;
		file.close();
			
			if (trans1>=balance)
			{
				cout<<"\n\t\t\t				You Have not Enough Money "<<endl;
				cout<<"\t\t\t				Please Enter Less Than Account Balance";
				goto t3;
			}
			else
			{
				cout<<"\n\t\t\t				\n\t\t\t				Please Wait..."<<sleep(4)<<endl;
				(system("CLS"));
				
				cout<<"\n\n\n\n\n"<<endl<<endl<<endl;
				cout<<"\t\t\t				Money Has Been Transfered "<<endl;
				cout<<"\t\t\t				Thank You For Using Our ATM System "<<endl;
				balance=balance-trans1;
				cout<<"\n\t\t\t				Your Remaining Balance is : "<<balance;
				cout<<"\n\t\t\t				\n\t\t\t				Press Any key to continue"; getch();
				(system("CLS"));
				
				menu();
			}
		}
	
	else
		{
		cout<<"\n\t\t\t				Please Wait..."<<sleep(4)<<endl;
		cout<<"\n\t\t\t				Please Enter Valid Account Number "<<endl;
		cout<<"\n\t\t\t				Please Wait..."<<sleep(4)<<endl;
		goto wrong;
		}
}

void change_pin()
{
	system("color E");
	(system("CLS"));
	cout<<"\n\t\t\t				Please Wait..."<<sleep(5)<<"\n\t\t\t				This Service Is Curruntly Unavailable"<<endl; sleep(5);
	system("cls");
	menu();	
}

void history()
{
	system("cls");
	ifstream file;
	file.open("history.txt");
	cout<<"\n\n\t\t\t\t   TRANSACTION HISTORY ";
	cout<<"\n\t\t\t\t   ___________________ "<<endl<<endl;
	while(getline(file,store))
	{
		cout<<store<<endl;
	}
	file.close();
	back_func();
}

void exit()
{
	cout<<"	H     H      A   V       V  E E E E           A           NN    N  I   C C C  E E E E       D D D       A    Y     Y   "<<endl;
	cout<<"	H     H     A A   V     V   E                A A          N N   N  I  C       E             D    D     A A    Y   Y    "<<endl;
	cout<<"	H H H H    A   A   V   V    E E E E         A   A         N  N  N  I  C       E E E E       D     D   A   A     Y      "<<endl; 
	cout<<"	H     H   AAAAAAA   V V     E              AAAAAAA        N   N N  I  C       E             D    D   AAAAAAA    Y      "<<endl;
	cout<<"	H     H  A       A   V      E E E E       A       A       N    NN  I   C C C  E E E E       D D D   A       A   Y      "<<endl;
}

void back_func()
{
	
	cout<<"\n		  					Press Any Key to Continue";
	getch();
	(system("CLS"));
	menu();
}

void tim()
{
	time_t current_time;
	current_time = time(NULL);
	
	char *tm = ctime(&current_time);
	cout<<tm;
}


int main ()
{	
	system("color 70");
	// assigned PINS 1234, 2468, 1357
	cout<<"\n\n\n\n\n				    				    Welcome To Manthar Bank ATM System "<<endl<<endl;
	cout<<"										 Enter PIN"<<endl;
	for (int i=1; i<=3; i++)
	{
	cout<<"				    						   "; cin>>pin;
		if(pin==1234 || pin==2468 || pin==1357)
		{
			goto z;
		}
		
		else if (i>3)
		{
			break;
		}
		
		else
		{
			cout<<"\n\n\t\t\t\t\t\t\t\t\t  You Entered Wrong PIN \n\t\t\t\t\t\t\t\t\t  Please wait..."<<sleep(3)<<endl<<"\n\t\t\t\t\t\t\t\t\t Please Enter Again PIN"<<endl; 
		}
	}
	z:
	(system("CLS"));
		switch (pin)
		{
 		case 1234 :
			balance=balance+trans1;
			name0=name1;
			ac=ac_1;
			menu();
			break;
		
		
		case 2468 :
			balance=balance+10000;
			name0=name2;
			ac=ac_2;
			balance=balance+trans2;
			menu();
			break;
			

		case 1357 : 
			balance=balance+20000;
			name0=name3;
			ac=ac_3;
			balance=balance+trans3;
			menu();
			break;

		
		ult : cout<<"\n\n\n\n\n\n\n\t\t\t\t You Enter Wrong Pin 3 Times In A Row So Your Account Has Been Temporary Blocked \n\t\t\t\t For More Details Contact With Developers Muhammad Mubeen & Mehtab ALi ";
		}
}
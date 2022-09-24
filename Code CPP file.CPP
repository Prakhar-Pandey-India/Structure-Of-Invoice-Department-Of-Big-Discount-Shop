//****************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<bits/stdc++.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>
#include<string.h>


//****************************************************************
//         1. CLASS USED IN PROJECT RELATED TO PRODUCT
//****************************************************************

class product
{
	int pno;
	char name[50];
	float price,qty,tax,dis;
	public:
	void create_product()
	{
		cout<<"\nPlease Enter The Product No. of The Product ";
		cin>>pno;
		cout<<"\n\nPlease Enter The Name of The Product ";
		gets(name);
		cout<<"\nPlease Enter The Price of The Product ";
		cin>>price;
		cout<<"\nPlease Enter The Discount (%) ";
		cin>>dis;
	}
	void show_product()
	{
		cout<<"\nThe Product No. of The Product : "<<pno;
		cout<<"\nThe Name of The Product : ";
		puts(name);
		cout<<"\nThe Price of The Product : "<<price;
		cout<<"\nDiscount : "<<dis;
	}

	int  retpno()
	{return pno;}

	float retprice()
	{return price;}

	char* retname()
	{return name;}

	int retdis()
	{return dis;}

};         //class ends here


//****************************************************************
//     2. CLASS USED IN PROJECT RELATED TO AUTHENTICATION
//****************************************************************


class security
{
	char name1[25];
	char password[20];
	char uid[20];
	public:
	void create_security()
	{
		cout<<"Enter Cashiername";
		gets(name1);
		cout<<"Enter Cashier ID";
		gets(uid);
		cout<<"Enter Password";
		gets(password);
	}
	void show_security()
	{
		cout<<"\n Cashier name : ";
		puts(name1);
		cout<<"\n Cashier ID : ";
		puts(uid);
	}
	char* retname1()
	{return name1;}

	char* retuid()
	{return uid;}

	char* retpassword()
	{return password;}
};                      //ends class here


//****************************************************************
//     3. CLASS USED IN PROJECT RELATED TO REPORT
//****************************************************************


class report
{       public:
	char name2[50];
	int dd,mm,yyyy;
	float total;
	//public:
	void create_report()
	{
		fflush(stdin);
		cout<<"Enter Day (01-31): ";
		cin>>dd;
		cout<<"Enter Month (01-12): ";
		cin>>mm;
		cout<<"Enter Year: ";
		cin>>yyyy;
		cout<<"Enter Customer Name: ";
		gets(name2);
		total=0;
		clrscr();
		cout<<"\n\n********************************INVOICE********************************\n";
		cout<<"\nDate : "<<dd<<"-"<<mm<<"-"<<yyyy<<"\t\tCustomer Name : "<<name2<<endl;
	}
	void create_report1()
	{       //float a;
		fflush(stdin);
		cout<<"Enter total:";
		/*cin>>a;
		total=a;*/
		cin>>total;
		cout<<"total: "<<total<<"\n";
	}

	void show_report()
	{
		cout<<"\nDate : "<<dd<<"-"<<mm<<"-"<<yyyy<<"\tCustomer Name : "<<name2<<"\t\ttotal : "<<total;
	}

	char* retname2()
	{return name2;}

	int  retdd()
	{return dd;}

	int retmm()
	{return mm;}

	int retyyyy()
	{return yyyy;}

	float rettotal()
	{return total;}

};      //ends class here


//***************************************************************
//    	global declaration for stream object, object
//			used in project
//****************************************************************


/*1->*/	 fstream fp;
/*2->*/	product pr;
/*3->*/	security sc;
/*4->*/	report re;
void admin_menu();
void main_menu();

//***************************************************************
//    	functions used in project
//***************************************************************

/*01.*/void write_report();					//To write report information in file
/*02.*/void write_report1();					//To write report information in file
/*03.*/void particular_date_report(int n,int u,int m);		//To show specific date report
/*04.*/void monthly_report(int n,int u);				//To show monthly report
/*05.*/void yearly_report(int n);				//To show yearly report
/*06.*/void report_menu();					//To show report menu
/*07.*/void reset_password();					//To recover password
/*08.*/void remove_Cashier();					//To delete Cashier
/*09.*/void add_Cashier();						//To add Cashier in file
/*10.*/void view_all_Cashier();					//To display all Cashier
/*11.*/void Cashier_menu();					//To show Cashier menu
/*12.*/void modify_product_details();				//To update record
/*13.*/void delete_product();					//To delete record
/*14.*/void write_product();					//To write product in file
/*15.*/void display_pp(int n);					//To show specific product information
/*16.*/void display_all_product();				//To show all product
/*17.*/void product_menu();					//To show product menu
/*18.*/void admin_menu();					//To show admin menu
/*19.*/void admin_login();					//To login admin
/*20.*/void menu();						//To show price list of product
/*21.*/void place_order();					//To place order and generating invoice
/*22.*/void counter();						//To show counter menu
/*23.*/void Cashier_login();					//To login Cashier
/*24.*/void intro();						//To show introduction
/*25.*/void main_menu();					//To show main menu
/*26.*/void main();						//THE MAIN FUNCTION OF PROGRAM


//***************************************************************
//    	function to write in file of report
//***************************************************************

void write_report()
{
	fp.open("Report.dat",ios::out|ios::app|ios::cur);
	re.create_report();
	fp.write((char*)&re,sizeof(report));
	fp.close();
}

void write_report1()
{
	fp.open("Report.dat",ios::out|ios::app|ios::cur);
	re.create_report1();
	fp.write((char*)&re,sizeof(report));
	fp.close();
}


//***************************************************************
//    	function to show specific date report from report file
//****************************************************************

void particular_date_report(int n,int u,int m)
{
	int flag=0;
	cout<<"\nReport Of Day :- "<<n<<"-"<<u<<"-"<<m<<"\n";
	fp.open("Report.dat",ios::in);
	while(fp.read((char*)&re,sizeof(report)))
	{
		if(re.retdd()==n && re.retmm()==u && re.retyyyy()==m)
		{
			re.show_report();
			cout<<"\n_-_-_-_-_-_-_-_-_-_-_-_-_-";
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
	cout<<"\n\nrecord not exist";
	getch();
}


//***************************************************************
//    	function to show monthly report from report file
//****************************************************************

void monthly_report(int n,int u)
{
	int flag=0;
	cout<<"\nReport Of Month :- 00-"<<n<<"-"<<u<<"\n";
	fp.open("Report.dat",ios::in);
	while(fp.read((char*)&re,sizeof(report)))
	{
		if(re.retmm()==n && re.retyyyy()==u)
		{
			re.show_report();
			cout<<"\n_-_-_-_-_-_-_-_-_-_-_-_-_-";
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
	cout<<"\n\nrecord not exist";
	getch();
}


//***************************************************************
//    	function to show yearly report from report file
//****************************************************************

void yearly_report(int n)
{
	int flag=0;
	cout<<"\nReport Of Year :- "<<n<<"\n";
	fp.open("Report.dat",ios::in);
	while(fp.read((char*)&re,sizeof(report)))
	{
		if(re.retyyyy()==n)
		{       //show_report();
			re.show_report();
			cout<<"\n_-_-_-_-_-_-_-_-_-_-_-_-_-";
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
	cout<<"\n\nrecord not exist";
	getch();
}


//***************************************************************
//    		report menu function
//****************************************************************

void report_menu()
{
	char ch;
	{
		do{
			clrscr();/*++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
			cout<<"\n\n\n\tREPORT MENU";
			cout<<"\n\n\t01. YEARLY REPORT";
			cout<<"\n\n\t02. MONTHLY REPORT";
			cout<<"\n\n\t03. DAILY REPORT";
			cout<<"\n\n\t04. EXIT";
			cout<<"\n\n\tENTER  YOUR CHOICE:";
			ch=getche();
			switch(ch)
			{
				case '1':int num;
					clrscr();
					cout<<"Enter Year: ";
					cin>>num;
					yearly_report(num);
					getch();
					break;
				case '2':int num1,num2;
					clrscr();
					cout<<"Enter Month: ";
					cin>>num1;
					cout<<"Enter Year: ";
					cin>>num2;
					monthly_report(num1,num2);
					getch();
					break;
				case '3':int num3,num4,num5;
					clrscr();
					cout<<"Enter Day: ";
					cin>>num2;
					cout<<"Enter Month: ";
					cin>>num3;
					cout<<"Enter Year: ";
					cin>>num4;
					particular_date_report(num2,num3,num4);
					break;
				case '4': admin_menu();
				default :cout<<"\a";
			}
		}while(ch!='4');
	}
}


//****************************************************************
//  		 function to recover password
//****************************************************************

void reset_password()
{
	char* no,found=0;
	clrscr();
	cout<<"\n\n\tReset Password ";
	cout<<"\n\n\tPlease Enter The Cashier Name";
	cin>>no;
	fp.open("Security.dat",ios::in|ios::out);
	while(fp.read((char*)&pr,sizeof(security)) && found==0)
	{
		if((strcmp(sc.retname1(),no)!=0))
		{
			sc.show_security();
			cout<<"\nPlease Enter The New Details of Cashier"<<endl;
			sc.create_security();
			int pos=-1*sizeof(sc);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&sc,sizeof(security));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}
	fp.close();
	if(found==0)
	cout<<"\n\n Record Not Found ";
	getch();
}


//***************************************************************
//    	function to delete Cashier from file of security
//***************************************************************

void remove_Cashier()
{
	char* no;
	clrscr();
	cout<<"\n\n\n\tDelete Record";
	cout<<"\n\nPlease Enter The Cashier Name of The Cashier You Want To Delete";
	gets(no);
	fp.open("Security.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&sc,sizeof(security)))
	{
		if((strcmp(sc.retname1(),no)!=0))
		{
			fp2.write((char*)&sc,sizeof(security));
		}
	}
	fp2.close();
	fp.close();
	remove("Security.dat");
	rename("Temp.dat","Security.dat");
	cout<<"\n\n\tRecord Deleted ..";
	getch();
}


//***************************************************************
//    	function to write in file of security
//***************************************************************

void add_Cashier()
{
	fp.open("Security.dat",ios::out|ios::app);
	sc.create_security();
	fp.write((char*)&sc,sizeof(security));
	fp.close();
	cout<<"The New Cashier Has Been Added ";
	getch();
}


//***************************************************************
//    	function to display all Cashier
//****************************************************************

void view_all_Cashier()
{
	clrscr();
	cout<<"\n\n\n\t\tDISPLAY ALL USERS !!!\n\n";
	fp.open("Security.dat",ios::in);
	while(fp.read((char*)&sc,sizeof(security)))
	{
		sc.show_security();
		cout<<"\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-";
		getch();
	}
	fp.close();
	getch();
}


//***************************************************************
//			Cashier menu function
//****************************************************************

void Cashier_menu()
{
	char ch;
	{
		do{
			clrscr();/*++++++++++++++++++++++++++++++++++++++++++++++++++++*/
			cout<<"\n\n\n\tCASHIER MENU";
			cout<<"\n\n\t01. VIEW ALL CASHIER";
			cout<<"\n\n\t02. ADD CASHIER";
			cout<<"\n\n\t03. REMOVE CASHIER";
			cout<<"\n\n\t04. RESET PASSWORD";
			cout<<"\n\n\t05. EXIT";
			cout<<"\n\n\tENTER  YOUR CHOICE:";
			ch=getche();
			switch(ch)
			{
				case '1': clrscr();
					view_all_Cashier();
					getch();
					break;
				case '2': clrscr();
					add_Cashier();
					break;
				case '3': clrscr();
					remove_Cashier();
					break;
				case '4': clrscr();
					reset_password();
					break;
				case '5': admin_menu();
				default :cout<<"\a";
			}
		}while(ch!='3');
	}

}


//***************************************************************
//    	function to modify record of file of product
//****************************************************************

void modify_product_details()
{
	int no,found=0;
	clrscr();
	cout<<"\n\n\tTo Modify ";
	cout<<"\n\n\tPlease Enter The Product No. of The Product";
	cin>>no;
	fp.open("Shope.dat",ios::in|ios::out);
	while(fp.read((char*)&pr,sizeof(product)) && found==0)
	{
		if(pr.retpno()==no)
		{
			pr.show_product();
			cout<<"\nPlease Enter The New Details of Product"<<endl;
			pr.create_product();
			int pos=-1*sizeof(pr);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&pr,sizeof(product));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}
	fp.close();
	if(found==0)
	cout<<"\n\n Record Not Found ";
	getch();
}


//***************************************************************
//    	function to delete record from file of product
//***************************************************************

void delete_product()
{
	int no;
	clrscr();
	cout<<"\n\n\n\tDelete Record";
	cout<<"\n\nPlease Enter The product no. of The Product You Want To Delete";
	cin>>no;
	fp.open("Shope.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&pr,sizeof(product)))
	{
		if(pr.retpno()!=no)
		{
			fp2.write((char*)&pr,sizeof(product));
		}
	}
	fp2.close();
	fp.close();
	remove("Shope.dat");
	rename("Temp.dat","Shope.dat");
	cout<<"\n\n\tRecord Deleted ..";
	getch();
}


//***************************************************************
//    	function to write in file of product
//****************************************************************

void write_product()
{
	fp.open("Shope.dat",ios::out|ios::app);
	pr.create_product();
	fp.write((char*)&pr,sizeof(product));
	fp.close();
	cout<<"\n\nThe Product Has Been Created ";
	getch();
}


//***************************************************************
//    	function to read specific record from product file
//****************************************************************

void display_pp(int n)
{
	int flag=0;
	fp.open("Shope.dat",ios::in);
	while(fp.read((char*)&pr,sizeof(product)))
	{
		if(pr.retpno()==n)
		{
			pr.show_product();
			cout<<"\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-";
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
	cout<<"\n\nrecord not exist";
	getch();
}


//***************************************************************
//    	function to read all records from file of product
//****************************************************************

void display_all_product()
{
	clrscr();
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	fp.open("Shope.dat",ios::in);
	while(fp.read((char*)&pr,sizeof(product)))
	{
		pr.show_product();
		cout<<"\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-";
		getch();
	}
	fp.close();
	getch();
}


//***************************************************************
//    	product menu function
//****************************************************************

void product_menu()
{
	clrscr();
	char ch2;
	cout<<"\n\n\n\tPRODUCT MENU";
	cout<<"\n\n\t1.VIEW ALL PRODUCTS";
	cout<<"\n\n\t2.VIEW PARTICULAR PRODUCTS";
	cout<<"\n\n\t3.ADD PRODUCT";
	cout<<"\n\n\t4.DELETE PRODUCT";
	cout<<"\n\n\t5.MODIFY PRODUCT DETAILS";
	cout<<"\n\n\t6.EXIT";
	cout<<"\n\n\tENTER YOUR CHOICE ";
	ch2=getche();
	switch(ch2)
	{
		case '1': clrscr();
			display_all_product();
			break;
		case '2': int num;
			clrscr();
			cout<<"\n\n\tPlease Enter The Product No. ";
			cin>>num;
			display_pp(num);
			break;
		case '3': clrscr();
			write_product();break;
		case '4': clrscr();
			delete_product();break;
		case '5': clrscr();
			modify_product_details();break;
		case '6': admin_menu();
		default:  cout<<"\a";
	}
}


//***************************************************************
//    	function for admin menu
//****************************************************************

void admin_menu()
{
	char ch;
	do{
		clrscr();
		cout<<"\n\n\n\tADMIN MENU";
		cout<<"\n\n\t01. PRODUCT";
		cout<<"\n\n\t02. CASHIER";
		cout<<"\n\n\t03. REPORT";
		cout<<"\n\n\t04. EXIT";
		cout<<"\n\n\tENTER YOUR CHOICE:";
		ch=getche();
		switch(ch)
		{
			case '1': clrscr();
				product_menu();
				getch();
				break;
			case '2': clrscr();
				Cashier_menu();
				break;
			case '3': clrscr();
				report_menu();
				break;
			case '4':main_menu();
			default :cout<<"\a";
		}
	}while(ch!='3');
}


//***************************************************************
//    	function to login admin
//****************************************************************

void admin_login()
{
	clrscr();
	char admin1[9]="ad", pasw[13]="ap",au[9],ap[13];
	cout<<"\n\n\n@@@@@___Admin Login Page___@@@@@\n\n\n";
	cout<<"\nEnter Admin ID\n";
	gets(au);
	cout<<"Enter Password\n";
	gets(ap);
	if((strcmp(admin1,au))==0 && (strcmp(pasw,ap))==0)
	{
		admin_menu();
	}
	else
	{
		clrscr();
		cout<<"\n!!!.....OOPs--Your Admin ID 'or'Password Is 'WRONG'.....!!!";
		cout<<"\n\nPress any key to go to main menu...........";
		getch();
	}
}


//***************************************************************
//    	function to display all products price list
//****************************************************************

void menu()
{
	clrscr();
	fp.open("Shope.dat",ios::in);
	if(!fp)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File";
		cout<<"\n\n\n Program is closing ....";
		getch();
		exit(0);
	}

	cout<<"\t\tProduct MENU\n";
	cout<<"_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
	cout<<"P.NO.\t\tNAME\t\t\t\t\tPRICE\n";
	cout<<"_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";

	while(fp.read((char*)&pr,sizeof(product)))
	{
		cout<<pr.retpno()<<"\t\t"<<pr.retname()<<"\t\t\t\t"<<pr.retprice()<<endl;
	}
	fp.close();
}


//***************************************************************
//    	function to place order and generating invoice for Products
//****************************************************************

void place_order()
{
	int  order_arr[50],quan[50],c=0;
	float amt,damt,total=0,paid;
	char ch='Y';
	menu();
	cout<<"\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
	cout<<"\n    PLACE YOUR ORDER";
	cout<<"\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	do{
		cout<<"\nEnter The Product No. Of The Product : ";
		cin>>order_arr[c];
		cout<<"Quantity in number : ";
		cin>>quan[c];
		c++;
		cout<<"Do You Want To Order Another Product ? (y/n)";
		cin>>ch;
	}while(ch=='y' ||ch=='Y');
	cout<<"\n\nThank You For Placing The Order";getch();clrscr();
	cout<<"\n\n**********************Customer Details*************************\n";
	write_report();
	cout<<"\nPr No.\tPr Name\t\tQuantity \tPrice \tAmount  \tAmount_after_discount\n";
	for(int x=0;x<=c;x++)
	{
		fp.open("Shope.dat",ios::in);
		fp.read((char*)&pr,sizeof(product));
		while(!fp.eof())
		{
			if(pr.retpno()==order_arr[x])
			{
				amt=pr.retprice()*quan[x];
				damt=amt-(amt*pr.retdis()/100);
				cout<<"\n"<<order_arr[x]<<"\t"<<pr.retname()<<"\t"<<quan[x]<<"\t\t"<<pr.retprice()<<"\t"<<amt<<"\t\t"<<damt;
				total+=damt;
			}
			fp.read((char*)&pr,sizeof(product));
		}
		fp.close();
	}
	cout<<"\n\n\t\t\t\t\tTOTAL = "<<total;
	cout<<"\n\nTHANKYOU !! \nVISIT AGAIN";
	getch();
	clrscr();
	cout<<"TOTAL = "<<total<<"\n";
	write_report1();
	re.show_report();
	fp.open("Report.dat",ios::in|ios::out);
		fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&re,sizeof(report)))
	{
		if(re.rettotal()!=0)
		{
			fp2.write((char*)&re,sizeof(report));
		}
	}
	fp2.close();
	fp.close();
	remove("Report.dat");
	rename("Temp.dat","Report.dat");
}


//***************************************************************
//    	function of counter menu
//****************************************************************

void counter()
{
	char ch;
	do
	{
		clrscr();
		cout<<"\n\n\t01. PLACE ORDER";
		cout<<"\n\n\t02. EXIT";
		cout<<"\n\n\tENTER YOUR CHOICE:";
		ch=getche();
		switch(ch)
		{
			case '1': clrscr();
				  place_order();
				  getch();
				  break;
			case '2': main_menu();
			default :counter();
		}
	}while(ch!='3');
}


//***************************************************************
//    	function to login Cashier
//***************************************************************

void Cashier_login()
{

	cout<<"\n\n\n*****.....Cashier Login Page*****.....\n\n\n";
	char un[12],id[12],up[12];
	int flag=0;
	cout<<"\nEnter Cashier ID\n";
	gets(id);
	cout<<"\nEnter Password\n";
	gets(up);
	fp.open("Security.dat",ios::in);
	while(fp.read((char*)&sc,sizeof(security)))
	{
		if((strcmp(sc.retuid(),id))==0 && (strcmp(sc.retpassword(),up))==0)
		{
			clrscr();
			flag++;
		}
	}
	fp.close();

	if(flag==1)
	{
		counter();
	}
	else
	{
		clrscr();
		cout<<"\n!!!.....OOPs--Your Cashier ID 'or'Password Is 'WRONG'.....!!!";
		cout<<"\n\nPress any key to go to main menu...........";
		getch();
	}
}


//***************************************************************
//    	INTRODUCTION FUNCTION
//***************************************************************

void intro()
{
	clrscr();
	gotoxy(32,1);
	cout<<"\\/\\/�|CO/\\/\\�";
	gotoxy(28,3);
	cout<<"MAJOR PROJECT TOPIC --";
	gotoxy(33,6);
	cout<<"STRUCTURE OF";
	gotoxy(30,8);
	cout<<"INVOICE DEPARTMENT";
	gotoxy(38,10);
	cout<<"OF";
	gotoxy(30,12);
	cout<<"BIG DISCOUNT SHOP";
	gotoxy(1,14);
	cout<<"\n\nDEVELOPED BY  : PRAKHAR PANDEY";
	cout<<"\n\nCOURSE        : BACHELOR OF COMPUTER APPLICATION";
	cout<<"\n\nROLL NO.      : 11818407081";
	cout<<"\n\nCOLLEGE       : RAJARSHI SCHOOL OF MANAGEMENT AND TECHNOLOGY";
	cout<<"\n\n\n\t\t....!!! PRESS ANY KEY TO PROCEED !!!....";
	getch();
}
void main_menu()
{
	char ch;
	do
	{
		clrscr();
		cout<<"\n\n\n\tSTART";
		cout<<"\n\n\t01. CASHIER";
		cout<<"\n\n\t02. ADMIN";
		cout<<"\n\n\t03. CLOSE";
		cout<<"\n\n\tENTER YOUR CHOICE:";
		ch=getche();
		switch(ch)
		{
			case '1': clrscr();
				fflush(stdin);
				Cashier_login();
				getch();
				break;
			case '2': clrscr();
				admin_login();
				break;
			case '3': exit(0);
				default :cout<<"\a";
		}
		}while(ch!='3');
}


//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************

void main()
{
	char ch;
	intro();
	main_menu();
}


//***************************************************************
//    			END OF PROJECT
//***************************************************************
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<fstream>
using namespace std;

//Global variables to use inside functions
double total_bill_category,category_bill; 
char mul_choice;

//Function declarations 
int Drinks();
int KT_equipment();
int BW_equipment();
int BR_equipment();
int beauty_products();
int stationary();
int home_equipment();
int perfumes();
int control_loop(int user_ch, int multiple,int array[]);

//main funtion
main()
{
	//opening messages to the online Customer!
	
	cout<<"\tWELCOME TO ONLINE SHOPPING CART BILLING SYSTEM!"<<endl<<
		"You can select multiple items whatever you want from the menu\n"<<endl;
	
	//Variable declarations
	char further;
	int choice;
	double discount=0.0;
	int total_bill,drinks_bill=0,perfumes_bill=0,HE_bill=0,Stationary_bill=0,BP_bill=0;
	string const disc_coupon="save%10";
	string disc_validation,name,stringfile;
	
	cout<<"Tell us what is your name: ";
	getline(cin,name);
	
	//Loop to make Customer atleast shop once	
	do{
	
	// MENU msg to the user and ask for input!
	
		cout<<setfill(' ')<<"You can select the options from the menu and inside menu you can select multiple items of your choice\n"<<endl<<
			"Items"<<setw(30)<<"Selection Input"<<endl<<
			"1. Drinks"<<setw(20)<<"1"<<endl<<
			"2. Beauty_products"<<setw(11)<<"2"<<endl<<
			"3. Stationary"<<setw(16)<<"3"<<endl<<
			"4. Home Eqipment"<<setw(13)<<"4"<<endl<<
			"5. Perfumes"<<setw(18)<<"5"<<endl<<
			"\nYour Choice: ";
		cin>>choice;
		
	//Checking validation of the user's entered choice and Evaluating accordingly
	
		switch(choice)
			{
			case 1:
				{
					drinks_bill+=Drinks();
					break;
				}
			case 2:
				{
					BP_bill+=beauty_products();
					break;
				}
			case 3:
				{
					Stationary_bill+=stationary();
					break;
				}
			case 4:
				{
					HE_bill+=home_equipment();
					break;
				}
			case 5:
				{
					perfumes_bill+=perfumes();
					break;
				}
			default:
					cout<<"\nInvalid Selection Input!";
			}
		
	//Asking If He/She want to go into another Category!
		
		cout<<"Do you want to Shop in any other category! (Y/N): ";
		cin>>further;
		if(further=='y' || further=='Y')
			system("cls");
	}while(further=='Y' || further=='y');                          // Loop validation!
	
	//Discounts calculations
	cout<<"Enter your Discount Coupon if you have any!:";
	cin>>disc_validation;
	
	//Final calculations
	total_bill=drinks_bill+perfumes_bill+HE_bill+Stationary_bill+BP_bill;
	if(disc_validation==disc_coupon)
		discount=total_bill*0.10;
	stringfile=name+"_receiptfile.txt";
	
	//Output msg 
	cout<<setfill(' ')<<"Your Bill Reciept of Purchasing is as Follow"<<endl<<
		"Category"<<setw(25)<<"Price in Total"<<endl<<
		"Drinks"<<setw(20)<<drinks_bill<<endl<<
		"Perfumes"<<setw(18)<<perfumes_bill<<endl<<
		"Home Equipment"<<setw(12)<<HE_bill<<endl<<
		"Stationary"<<setw(16)<<Stationary_bill<<endl<<
		setfill(' ')<<endl<<
		"Discount Granted:"<<setw(8)<<discount<<" or "<<fixed<<setprecision(2)<<double(discount)/280<<"$"<<endl<<
		"Total Bill: "<<setw(12)<<"Rs "<<(total_bill-discount)<<" or "<<fixed<<setprecision(2)<<double(total_bill-discount)/280<<"$";
	
	//Saving receipt to a text file
	ofstream receipt(stringfile.c_str());
	
	receipt << "***** ONLINE SHOPPING CART BILL RECEIPT *****\n"<<endl;
	receipt << "Category" << setw(25) << "Price in Total (PKR)\n";
	receipt << "-----------------------------------------------\n";
	receipt << "Drinks" << setw(25) << drinks_bill << endl;
	receipt << "Perfumes" << setw(23) << perfumes_bill << endl;
	receipt << "Home Equipment" << setw(17) << HE_bill << endl;
	receipt << "Stationary" << setw(21) << Stationary_bill << endl;
	receipt << "Beauty Products" << setw(16) << BP_bill << endl;
	receipt << "-----------------------------------------------\n";
	receipt << "Discount Granted: " << discount << " PKR\n";
	receipt << "Total Bill: " << (total_bill - discount) << " PKR\n";
	receipt << fixed << setprecision(2);
	receipt << "Total in USD: $" << double(total_bill - discount) / 280 << endl;
	receipt << "\nThank you for shopping with us!\n";
	receipt << "***********************************************\n";
	
	receipt.close();
	cout << "\nYour receipt has been saved to "<<stringfile<<" file.\n";
	system("pause");
	return 0;
}

//defining the Drinks() function
Drinks() 
{
	// variable declarations 
	int user_choice,how_many=1;
	category_bill=0;
	char any_other;
	int price[5]={200,210,180,220,150};
	
	// Output Message to customer
	cout<<setfill(' ')<<"In Beverages Section, We have!\n"<<endl<<
		"Item"<<setw(27)<<"Pricing (Pkr)"<<endl<<
		"1. Coca Cola "<<setw(14)<<"200"<<endl<<
		"2. Pepsi "<<setw(18)<<"210"<<endl<<
		"3. 7up "<<setw(20)<<"180"<<endl<<
		"4. Mountain Dew"<<setw(12)<<"220"<<endl<<
		"5. Sting "<<setw(18)<<"150";
		
	//loop to excecute instructions atleast once
	do{
		cout<<"\nEnter your choice: ";
		cin>>user_choice;
		cout<<"Do you want multiple items or not (y/n): ";
		cin>>mul_choice;
		if(mul_choice=='y' || mul_choice=='Y')
			{
			cout<<"\nHow many do you want: ";
			cin>>how_many;
			}
		category_bill+=control_loop(user_choice,how_many,price);
		cout<<"Any other Drink You wanna choose! (Y/N)";
		cin>>any_other;
	}while(any_other=='Y' || any_other== 'y');
	total_bill_category=category_bill;
	return total_bill_category;
}

//defining Beauty_products() functions
beauty_products()
{
	//Variable Declarations
	int user_choice,how_many=1;
	category_bill=0;
	char any_other;
	int price[5]={150,400,1500,1000,1200};
	
	//Output message to the customer
	cout<<setfill(' ')<<"In Beauty Products Section, We have!\n"<<endl<<
		"Item"<<setw(45)<<"Pricing (Pkr)"<<endl<<
		"1. Lip balm "<<setw(32)<<"150"<<endl<<
		"2. Whitening Cream "<<setw(25)<<"400"<<endl<<
		"3. Makeup_kit "<<setw(31)<<"1500"<<endl<<
		"4. Hair Serum + Conditioner"<<setw(18)<<"1000"<<endl<<
		"5. Shampoo "<<setw(34)<<"1200";
		
	//Loop to execute instructions atleast once
	do{
		cout<<"\nEnter your choice: ";
		cin>>user_choice;
		cout<<"Do you want multiple items or not (y/n): ";
		cin>>mul_choice;
		if(mul_choice=='y' || mul_choice=='Y')
			{
			cout<<"\nHow many do you want: ";
			cin>>how_many;
			}
		category_bill+=control_loop(user_choice,how_many,price);
		cout<<"Any other Product You wanna choose! (Y/N)";
		cin>>any_other;
	}while(any_other=='Y' || any_other=='y');
	total_bill_category=category_bill;
	return total_bill_category;
}

//Defining stationary() function
stationary()
{
	//Variable Declarations
	int user_choice,how_many=1;
	category_bill=0;
	char any_other;
	int price[5]={300,300,350,450,400};
	
	//Output Message to the Customer
	cout<<setfill(' ')<<"In Stationary Section, We have!\n"<<endl<<
		"Item"<<setw(38)<<"Pricing (Pkr)"<<endl<<
		"1. Pencil Box (12 in 1)"<<setw(14)<<"300"<<endl<<
		"2. Pen box (6 in 1)"<<setw(18)<<"300"<<endl<<
		"3. Notes Book "<<setw(23)<<"350"<<endl<<
		"4. Sketch Book"<<setw(23)<<"450"<<endl<<
		"5. Kids Coloring Book"<<setw(16)<<"400";
		
	//Loop to execute instructions atleast once
	do{
		cout<<"\nEnter your choice: ";
		cin>>user_choice;
		cout<<"Do you want multiple items or not (y/n): ";
		cin>>mul_choice;
		if(mul_choice=='y' || mul_choice=='Y')
			{
			cout<<"\nHow many do you want: ";
			cin>>how_many;
			}
		category_bill+=control_loop(user_choice,how_many,price);
		cout<<"Any other Things You wanna choose! (Y/N)";
		cin>>any_other;
	}while(any_other=='Y' || any_other=='y');
	total_bill_category=category_bill;
	return total_bill_category;
}

//Defining home_equipment() function
home_equipment()
{
	//Function variables 
	int user_choice;
	char any_other;
	
	//Output message to the customer
	cout<<"What type of Home Equipment do you want?"<<endl<<
		"1. Kitchen Equipment "<<endl<<
		"2. Bath/Wash room Euipment"<<endl<<
		"3. Bed room Equipment"<<endl;
	
	//Loop to excecute instructions atleast once
	do{
		cout<<"\nEnter your choice: ";
		cin>>user_choice;
		switch(user_choice)
		{
			case 1:
				{
					total_bill_category+=KT_equipment(); break;        //Functions inside funtion
				}
			case 2:
				{
					total_bill_category+=BW_equipment(); break;        //Functions inside funtion
				}
			case 3:
				{
					total_bill_category+=BR_equipment(); break;        //Functions inside funtion
				}
			default:
				cout<<"Invalid Choice Selected!";
		}
		cout<<"Any other Equipment You wanna choose! (Y/N)";
		cin>>any_other;
	}while(any_other=='Y' || any_other=='y');
	return total_bill_category;
}
//                              Defining Sub functions to be used under home_equipment() function
KT_equipment()
{
	//function Variable declaration
	int user_choice,how_many=1;
	category_bill=0;
	char any_other;
	int price[5]={100,150,200,500,250};
	
	//Output message to the customer
	cout<<setfill(' ')<<"In Kitchen Category, We have!\n"<<endl<<
		"Item"<<setw(35)<<"Pricing (Pkr)"<<endl<<
		"1. Glass Cup "<<setw(20)<<"100"<<endl<<
		"2. Serving Plate"<<setw(17)<<"150"<<endl<<
		"3. Tea/Coffee Mug"<<setw(16)<<"200"<<endl<<
		"4. Fry Pan "<<setw(22)<<"500"<<endl<<
		"5. Spoons & knives "<<setw(14)<<"250";
		
	//Loop to execute instructions atleast once
	do{
		cout<<"\nEnter your choice: ";
		cin>>user_choice;
		cout<<"Do you want multiple items or not (y/n): ";
		cin>>mul_choice;
		if(mul_choice=='y' || mul_choice=='Y')
			{
			cout<<"\nHow many do you want: ";
			cin>>how_many;
			}
		category_bill+=control_loop(user_choice,how_many,price);
		cout<<"Any other things You wanna choose! (Y/N)";
		cin>>any_other;
	}while(any_other=='Y' || any_other=='y');
	return category_bill;
}
BW_equipment()
{
	//function variables
	int user_choice,how_many=1;
	category_bill=0;
	char any_other;
	int price[5]={120,250,200,500,250};
	
	//Output message to the customer
	cout<<setfill(' ')<<"In Bath/Wash Category, We have!\n"<<endl<<
		"Item"<<setw(40)<<"Pricing (Pkr)"<<endl<<
		"1. Soap BAR "<<setw(25)<<"150"<<endl<<
		"2. Liquid Soap"<<setw(23)<<"250"<<endl<<
		"3. Scrubber"<<setw(26)<<"200"<<endl<<
		"4. Towel "<<setw(28)<<"500"<<endl<<
		"5. Toothpaste & accessories"<<setw(10)<<"250";
		
	//Loop to execute instructions atleast once
	do{
		cout<<"\nEnter your choice: ";
		cin>>user_choice;
		cout<<"Do you want multiple items or not (y/n): ";
		cin>>mul_choice;
		if(mul_choice=='y' || mul_choice=='Y')
			{
			cout<<"\nHow many do you want: ";
			cin>>how_many;
			}
		category_bill+=control_loop(user_choice,how_many,price);
		cout<<"Any other Things You wanna choose! (Y/N)";
		cin>>any_other;
	}while(any_other=='Y' || any_other=='y');
	return category_bill;
}
BR_equipment()
{
	//function variables
	int user_choice,how_many=1;
	category_bill=0;
	char any_other;
	int price[4]={200,500,200,500};
	
	//Output message to the customer
	cout<<setfill(' ')<<"In Bedroom Category, We have!\n"<<endl<<
		"Item"<<setw(35)<<"Pricing (Pkr)"<<endl<<
		"1. Bedside Lamp light "<<setw(10)<<"200"<<endl<<
		"2. Alarm Clock"<<setw(18)<<"500"<<endl<<
		"3. Charger Extension"<<setw(12)<<"300"<<endl<<
		"4. Book Stand "<<setw(18)<<"500"<<endl;
		
	//Loop to execute instructions atleast once
	do{
		cout<<"\nEnter your choice: ";
		cin>>user_choice;
		cout<<"Do you want multiple items or not (y/n): ";
		cin>>mul_choice;
		if(mul_choice=='y' || mul_choice=='Y')
			{
			cout<<"\nHow many do you want: ";
			cin>>how_many;
			}
		category_bill+=control_loop(user_choice,how_many,price);
		cout<<"Any other Thing You wanna choose! (Y/N)";
		cin>>any_other;
	}while(any_other=='Y' || any_other=='y');
	return category_bill;
}

//Defining perfumes() functions
perfumes()
{
	//Function variables
	int user_choice,how_many=1;
	category_bill=0;
	char any_other;
	int price[5]={600,800,700,900,500};
	
	//Output message to the customer
	cout<<setfill(' ')<<"In Perfumes Section, We have!\n"<<endl<<
		"Item"<<setw(27)<<"Pricing (Pkr)"<<endl<<
		"1. Versace "<<setw(15)<<"600"<<endl<<
		"2. Dior"<<setw(19)<<"800"<<endl<<
		"3. Calvien Klien"<<setw(10)<<"700"<<endl<<
		"4. Terre D Hermes"<<setw(9)<<"900"<<endl<<
		"5. Lattafa "<<setw(15)<<"500";
		
	//Loop to execute instructions atleast once
	do{
		cout<<"\nEnter your choice: ";
		cin>>user_choice;
		cout<<"Do you want multiple items or not (y/n): ";
		cin>>mul_choice;
		if(mul_choice=='y' || mul_choice=='Y')
			{
			cout<<"\nHow many do you want: ";
			cin>>how_many;
			}
		category_bill+=control_loop(user_choice,how_many,price);
		cout<<"Any other Perfume You wanna choose! (Y/N)";
		cin>>any_other;
	}while(any_other=='Y' || any_other=='y');
	total_bill_category=category_bill;
	return total_bill_category;
}

//     ******************************* Control of the calculation for all the categories and sub categories **********************************
control_loop(int user_ch, int multiple,int array[])
{
		for(int i=0;i<=5;i++)
		{
			if(i==0 && user_ch==1)
				{return array[i]*multiple; break;}
			else {
				if(i==user_ch)
				{return array[i-1]*multiple; break;}
			else
				continue;
			}
		}
}

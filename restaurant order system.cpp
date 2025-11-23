#include<iostream>
#include<iomanip>
using namespace std;
int Lunch();
int Dinner();
int Breakfast();
int Breakfast()
{
	int press,i=1,members,sum=0;
	int const arr[6]={250,150,80,200,200,350};
	cout<<setfill(' ')<<"\nIn our breakfast menu, we have following things available!"<<endl<<
		" NAME "<<setw(35)<<" PRICE "<<endl<<
		"1. Omelete paratha with Chai:"<<setw(10)<<"250"<<endl<<
		"2. Paratha with Chai:"<<setw(18)<<"150"<<endl<<
		"3. Chai Only:"<<setw(25)<<"80"<<endl<<
		"4. Paratha with Omelete:"<<setw(15)<<"200"<<endl<<
		"5. Coffee only:"<<setw(24)<<"200"<<endl<<
		"6. Coffee with corrisant"<<setw(15)<<"350"<<endl<<
		"press 0 if you just want to sit beside other members"<<endl<<
		"\nFirst tell us, How many members are you in numbers: ";
	cin>>members;
	while(i<=members)
	{
		cout<<"member "<<i<<" wants: ";
		cin>>press;
		switch(press)
		{	case 0: break;
			case 1: sum+=arr[0]; break;
			case 2: sum+=arr[1]; break;
			case 3: sum+=arr[2]; break;
			case 4: sum+=arr[3]; break;
			case 5: sum+=arr[4]; break;
			case 6: sum+=arr[5]; break;
			default: cout<<"Invalid Value!\n";
		}
		if(press>6)
			continue;
		i++;
	}
	return sum;
}
main()
{
	char choice;
	int total_table_bill=0;
	int total_bill,ch;
	cout<<"\tWELCOME TO ALFAFA RESTAURANT!"<<endl;
	cout<<"This is our New branch So Make yourself Comfortable\n"<<endl;
	
	cout<<"WE OFFER!"<<endl<<
		"Breakfast: press B "<<endl<<
		"Lunch: press L "<<endl<<
		"Dinner: press D \n"<<endl<<
		"Your Choice: ";
	while(true)
	{
		cin.get(choice);
		if(choice=='B')
			{total_bill=Breakfast();
			break;}
		else if(choice=='L')
			{total_bill=Lunch();
			break;}
		else if(choice=='D')
			{total_bill=Dinner();
			break;}
		else 
			cout<<"you entered wrong Key!";
	}
	cout<<"Total Bill for table is: "<<total_bill<<endl;

}
int Lunch()
{
	int press,members,i=1,sum=0;
	int const arr[6]={150,200,350,250,100,250};
	cout<<setfill(' ')<<"\nIn our Lunch menu, we have following things available!"<<endl<<
		"NAME "<<setw(20)<<"PRICE"<<endl<<
		"1. Salad:"<<setw(15)<<"150"<<endl<<
		"2. Coffee:"<<setw(14)<<"200"<<endl<<
		"3. Burger:"<<setw(14)<<"350"<<endl<<
		"4. Shawarma:"<<setw(12)<<"250"<<endl<<
		"5. Chai:"<<setw(16)<<"100"<<endl<<
		"6. Ice-Cream: "<<setw(10)<<"250"<<endl<<
		"press 0 if you just want to sit beside other members"<<endl<<
		"\nFirst tell us, How many members are you in numbers: ";
	cin>>members;
	while(i<=members)
	{
		cout<<"member "<<i<<" wants: ";
		cin>>press;
		switch(press)
		{	case 0: break;
			case 1: sum+=arr[0]; break;
			case 2: sum+=arr[1]; break;
			case 3: sum+=arr[2]; break;
			case 4: sum+=arr[3]; break;
			case 5: sum+=arr[4]; break;
			case 6: sum+=arr[5]; break;
			default: cout<<"Invalid Value!\n";
		}
		if(press>6)
			continue;
		i++;
	}
	return sum;		
}
int Dinner()
{
	int press,members,i=1,sum=0;
	int const arr[6]={200,400,300,400,350,500};
	cout<<setfill(' ')<<"\nIn our Dinner menu, we have following things available!"<<endl<<
		" NAME "<<setw(30)<<" PRICE "<<endl<<
		"1. Biryani"<<setw(24)<<"200"<<endl<<
		"2. Chicken Roast piece"<<setw(12)<<"400"<<endl<<
		"3. Chicken Karahi 1 plate"<<setw(9)<<"300"<<endl<<
		"4. White Karahi 1 plate"<<setw(11)<<"400"<<endl<<
		"5. Pulao"<<setw(26)<<"350"<<endl<<
		"6. Seekh Kabab 3 pieces"<<setw(11)<<"500"<<endl<<
		"press 0 if you just want to sit beside other members"<<endl<<
		"\nFirst tell us, How many members are you in numbers: ";
	cin>>members;
	while(i<=members)
	{
		cout<<"member "<<i<<" wants: ";
		cin>>press;
		switch(press)
		{	case 0: break;
			case 1: sum+=arr[0]; break;
			case 2: sum+=arr[1]; break;
			case 3: sum+=arr[2]; break;
			case 4: sum+=arr[3]; break;
			case 5: sum+=arr[4]; break;
			case 6: sum+=arr[5]; break;
			default: cout<<"Invalid Value!\n";
		}
		if(press>6)
			continue;
		i++;
	}
		return sum;
		
}

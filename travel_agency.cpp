#include<iostream>
#include<conio.h>
#include<iomanip>
#include<cstdlib>
using namespace std;
main()
{
	int economy_class= 125000, business_class=145000;
	double economy_class_dollar,business_class_dollar,business_class_euro,economy_class_euro,window_rate_dollar,window_rate_euro;
	int num_of_passng,ticket_rate,window_rate=10000,window_seat=0,total_bill;
	string which_class,bill_in,signn,task_operation,authorization;
	string const agency_authorization="mughal@497#";
	int const dollar=290,euro=330;
	bool looping=true;
	string class_value,yes_no;
	cout<<setfill(' ')<<setw(10)<<"WELCOME TO MUGHAL TRAVELS AGENCY!\n"<<endl;
	cout<<"What type of task you wanna do?"<<endl<<
		"To change tickets value(Type: changes) "<<endl<<
		"To calculate tickets bill(Type: calculate) "<<endl<<
		"You wanna do: ";
	cin>>task_operation;
	while (looping)
	{

	while (looping)
	{
	if (task_operation=="changes")
		{
			cout<<"\nEnter the Agency's authorization password: ";
			cin>>authorization;
			if(authorization==agency_authorization)
				{
					while (looping)
					{
					
					cout<<"\nWhat ticket class you want to change values of(type:economy or business): ";
					cin>>class_value;
					if(class_value=="economy")
						{
							cout<<"\nStandard amount is "<<economy_class<<"\nset amount of economy class ticket: ";
							cin>>economy_class;
							cout<<"do you want to change values of business class ticket too! (type: yes/no)";
							cin>>yes_no;
							if(yes_no=="yes")
								{
									cout<<"\nStandard amount is "<<business_class<<"\nSet amount of business class ticket: ";
									cin>>business_class;
									
								}
							else if(yes_no=="no")
								{
									exit;
								}
							else
								cout<<"Invalid Input";
						}
					else if(class_value=="business")
						{
							cout<<"\nStandard amount is "<<business_class<<"\nSet amount of business class ticket: ";
							cin>>business_class;
							cout<<"do you want to change values of business class ticket too! (type: yes/no)";
							cin>>yes_no;
							if(yes_no=="yes")
								{
									cout<<"\nStandard amount is "<<economy_class<<"\nSet amount of economy class ticket: ";
									cin>>economy_class;
									
								}
							else if(yes_no=="no")
								{
									exit;
								}
							else
								cout<<"Invalid Input";}
					else
						{
							cout<<"Invalid class typed!";
						}
					cout<<"Would you like to change values of window seat difference? (yes/no): ";
					while (looping)
					{
						cin>>yes_no;
						if(yes_no=="yes")
							{
								cout<<"\nstandard amount is"<<window_rate<<"\nSet amount of window seat difference: ";
								cin>>window_rate;
								break;
							}
						else if(yes_no=="no")
							{
								break;
							}
						else 
							cout<<"Invalid Input!\nInput Again: ";}
					
					break;
					}
					system("cls");
					cout<<"\nchanges Successful\n";
					cout<<setfill('-')<<setw(30)<<endl;
				}
			else
				{cout<<"You entered Incorrect authorization password\nSo, You are not allowed to make any changes"<<endl;
				exit;}
			break;	}
	else if(task_operation=="calculate")
		{
			cout<<"\nEnter in what type you want to calculate your bill in(pkr/usd/euro): ";
			cin>>bill_in;
			if(bill_in=="usd")
				{
					economy_class_dollar=economy_class/dollar;
					business_class_dollar=business_class/dollar;
					window_rate_dollar=window_rate/dollar;
					signn="$";
					cout<<"Enter number of passengers: ";
					cin>>num_of_passng;
					cout<<"Which class would you like to travel in? "<<endl<<
						"\nNote: Economy class and Business class have different prices "<<endl<<
						"Rates are as written below"<<endl<<
						"Economy class: "<<economy_class_dollar<<"$ per person"<<endl<<
						"Business Class: "<<business_class_dollar<<"$ per person"<<endl<<
						"type (economy or business): ";
					while (looping)
						{
						cin>>which_class;
						if(which_class=="economy")
							{
								ticket_rate=economy_class_dollar*num_of_passng;
								break;
							}
						else if(which_class=="business")
						{
							ticket_rate=business_class_dollar*num_of_passng;
							break;}
						else
							cout<<"invalid Input!";}
					cout<<"\nvalues of seats differs too \nby window seat is expensive!"<<endl<<
						"Rate is "<<window_rate_dollar<<"$ for each seat"<<endl<<
						"Do you want seat by window(yes/no): ";
					while (looping)
					{cin>>yes_no;
					if(yes_no=="yes")
						{cout<<"how many passengers want seat by window: ";
						cin>>window_seat;
						break;}
					else if(yes_no=="no")
						{
							break;
						}
					else
						cout<<"Invalid Input!"<<endl;
					}
					total_bill=ticket_rate+window_rate_euro*window_seat;
					cout<<"\nYour total bill is "<<total_bill<<signn;
					break;
				}
			else if(bill_in=="euro")
			{
					economy_class_euro=economy_class/euro;
					business_class_euro=business_class/euro;
					window_rate_euro=window_rate/=euro;
					signn="€";
					cout<<"Enter number of passengers: ";
					cin>>num_of_passng;
					cout<<fixed<<setprecision(2);
					cout<<"Which class would you like to travel in? "<<endl<<
						"\nNote: Economy class and Business class have different prices "<<endl<<
						"Rates are as written below"<<endl<<
						"Economy class: "<<economy_class_euro<<"€ per person"<<endl<<
						"Business Class: "<<business_class_euro<<"€ per person"<<endl<<
						"type (economy or business): ";
					while (looping)
						{
						cin>>which_class;
						if(which_class=="economy")
							{
								ticket_rate=economy_class_euro*num_of_passng;
								break;
							}
						else if(which_class=="business")
						{
							ticket_rate=business_class_euro*num_of_passng;
							break;}
						else
							cout<<"invalid Input!";}
					cout<<"\nvalues of seats differs too \nby window seat is expensive!"<<endl<<
						"Rate is "<<window_rate_dollar<<"€ for each seat"<<endl<<
						"Do you want seat by window(yes/no): ";
					while (looping)
					{cin>>yes_no;
					if(yes_no=="yes")
						{cout<<"how many passengers want seat by window: ";
						cin>>window_seat;
						break;}
					else if(yes_no=="no")
						{
							break;
						}
					else
						cout<<"Invalid Input!"<<endl;
					}
					total_bill=ticket_rate+window_rate*window_seat;
					cout<<"\nYour total bill is "<<total_bill<<signn;
					break;
				}
			else if(bill_in=="pkr")
			{
					signn="Rs";
					cout<<"Enter number of passengers: ";
					cin>>num_of_passng;
					cout<<"Which class would you like to travel in? "<<endl<<
						"\nNote: Economy class and Business class have different prices "<<endl<<
						"Rates are as written below"<<endl<<
						"Economy class: "<<economy_class<<"Rs per person"<<endl<<
						"Business Class: "<<business_class<<"Rs per person"<<endl<<
						"type (economy or business): ";
					while (looping)
						{
						cin>>which_class;
						if(which_class=="economy")
							{
								ticket_rate=economy_class*num_of_passng;
								break;
							}
						else if(which_class=="business")
						{
							ticket_rate=business_class*num_of_passng;
							break;}
						else
							cout<<"invalid Input!";}
					cout<<"\nvalues of seats differs too \nby window seat is expensive!"<<endl<<
						"Rate is "<<window_rate<<"Rs for each seat"<<endl<<
						"Do you want seat by window(yes/no): ";
					while (looping)
					{cin>>yes_no;
					if(yes_no=="yes")
						{cout<<"how many passengers want seat by window: ";
						cin>>window_seat;
						break;}
					else if(yes_no=="no")
						{
							break;
						}
					else
						cout<<"Invalid Input!"<<endl;
					}
					total_bill=ticket_rate+window_rate*window_seat;
					cout<<"\nYour total bill is "<<total_bill<<signn;
					break;
			}
		break;}
	else
		{cout<<"\nINVALID VALUE entered for operation type!"<<endl;
		break;}
	}
	cout<<setfill('-')<<setw(30)<<endl;
	cout<<"\nWould you like to calculate bill \nOr make changes to the per person ticket amount "<<endl<<
		"(Type: yes/no) ";
	cin>>yes_no;
	if(yes_no=="yes")
	{
		cout<<"\n what type of operation you wanna perform (changes / calculate ): ";
		cin>>task_operation;
		continue;
	}
	else if(yes_no=="no")
		break;
	else
		cout<<"Invalid Input!";
}
}

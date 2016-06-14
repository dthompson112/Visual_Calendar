/**********************************************
** File name: visual_calander_driver.cpp
** Description: computes and displays a monthly calender
** Programmer: Dan Thompson
************************************************/

#include <iostream>  //input output
#include <stdio.h>	//floor function
#include <math.h>	//calculations
#include <string>	//string type
#include <limits>
using namespace std; // almost everything


int main()
{

	// declare functions
	int SelectMonth();
	//returns the month selected by the user

	int EnterYear();
	//returns the the year selected by the user

	int CalcFirstDay(double year);
	//returns the first day of the year
	//IN: The year the user wishes to view

	bool IsLeapYear(int year);
	//returns a value that indicates if the selected year is a leap year
	//IN: int version of the year the user whishes to view


	void DisplayCalendar(int first_day, string month, int year, int end_month);
	// generates and displayes the calendar
	// IN: the first day of the month, the string value of the month, the selected year, and the last day of the month
	// OUT: the calendar


	int GetEndMonth(int month, bool leap);
	//returns the last day of the month
	//IN: users selected month
	//IN: the bool value that determines if its a leap year

	string GetMonth(int month);
	//returns the name of the month
	//IN: the users selected month

	int GetFirstDay(int month, int first_day_of_year, bool leap);
	//returns the first day of the month
	//IN: the user selected month
	//IN: the first day of the year
	//IN: the bool value that determines if its a leap year

	bool ViewAgain();
	//returns the user selection either to repeat or not repeat the program.


	// declare variables

	int user_year;// year user enters
	int user_month; // month user enters
	int day_one; // first day of selected year
	int last_day; // last day of selected month
	double user_yeard; // selected year converted to type double for calculations
	bool leap_year; // bool value the show true if it is a leap false otherwise
	int first_day_m; // first day of the selected month
	string user_month_str; // stores a sring value of the selected month
	bool repeat = true; //a flag used for looping through the program


	// main program begins

	// loop the program for as long as the user wants
	while(repeat == true) // while the flag repeat equals true loop the program
	{
		// get month from user
		user_month = SelectMonth();
		// get year from user
		user_year = EnterYear();
		//  convert int year to a double to calculate first day
		user_yeard = user_year;
		// calculat first day of calender and store in a variable
		day_one = CalcFirstDay(user_yeard);
		// determine if the users year is a leap year
		leap_year = IsLeapYear(user_year);
		// get the string version of the user selected month
		user_month_str = GetMonth(user_month);
		// get the end of the month value
		last_day = GetEndMonth(user_month, leap_year);
		// get first day of month
		first_day_m = GetFirstDay(user_month, day_one, leap_year);
		// display calender
		DisplayCalendar(first_day_m, user_month_str, user_year, last_day);
		// prompt user to see if they want to continue change bool expression according to answer
		repeat = ViewAgain();

	 } // while the flag repeat equals true loop the program


return 0;
}

////////////////////////////////EnterYear/////////////////////////////////
//
// Function name: EnterYear
//
// Purpose: gets a year from the user
//
// Input Parameters: cin
//
// Output Parameters: int year, cout
//
// Return Value: int
//
///////////////////////////////////////////////////////////////////////////////

int EnterYear()
{
	//declare local variables
	int year;  // stores the users selected year

	//prompt user for year
	cout << "Please enter the year of the calendar you wish to view. Example '2010': ";
	cin >> year;
	while(!cin || (year < 0)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Please enter a valid year: ";
        cin >> year;
	}
	cout << endl;

	return year;
} // end EnterYear function







////////////////////////////////SelectMonth/////////////////////////////////
//
// Function name: SelectMonth
//
// Purpose: gets a month from the user
//
// Input Parameters: cin
//
// Output Parameters: int month, cout
//
// Return Value: int
//
///////////////////////////////////////////////////////////////////////////////


int SelectMonth()
{
	//declare local variables
	int month; //stores the users selected month

	//give user a menu
	cout << "1. January \n";
	cout << "2. February \n";
	cout << "3. March \n";
	cout << "4. April \n";
	cout << "5. May \n";
	cout << "6. June \n";
	cout << "7. July \n";
	cout << "8. August \n";
	cout << "9. September \n";
	cout << "10. October \n";
	cout << "11. November \n";
	cout << "12. December \n\n";

	// prompt user for selection and store in variable
	cout << "Please select a month by entering a number between 1 and 12: ";
	cin >> month;
	while(!cin || (month < 1) || (month > 12)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Please enter a valid month: ";
        cin >> month;
	}

	return month;
}// end SelectMonth function





////////////////////////////////CalcFirstDay/////////////////////////////////
//
// Function name: CalcFirstDay
//
// Purpose: Calculates the first day of the selected year
//
// Input Parameters: double year
//
// Output Parameters: int first_day
//
// Return Value: int
//
///////////////////////////////////////////////////////////////////////////////

int CalcFirstDay(double year)
{
	int first_day; //holds the first day of the year
	double holder; //holds data while waiting for a conversion to perform the modulo function

	// find the first day of the the year
	holder = ((((year - 1) * 365) + floor((year - 1) / 4) - floor((year - 1) / 100) + floor((year-1) / 400)) + 1);

	// covert the value of holder to an int to perform the modulo operation
	first_day = int (holder);
	first_day = first_day % 7;

	return first_day;
}// end CalcFirstDay function

////////////////////////////////IsLeapYear()/////////////////////////////////
//
// Function name: IsLeapYear
//
// Purpose: Checks if the selected year is a leap year
//
// Input Parameters: int year
//
// Output Parameters: bool leap
//
// Return Value: bool
//
///////////////////////////////////////////////////////////////////////////////

bool IsLeapYear(int year)
{
	// declare variables
	bool leap = false; // holds if the leap year is true or false

	// calculate if it is leapyear
	if(year % 4 == 0)//if the year is evenly divisable by 4 mark leap as true
		leap = true;

	if(year % 100 == 0 && year % 400 != 0)//if the year is evenly divisible by 100 but not 400 mark leap as false
		leap = false;


	return leap;
}// end IsLeapYear

////////////////////////////////DisplayCalendar/////////////////////////////////
//
// Function name: DisplayCalender
//
// Purpose: Displays One month in the calendar
//
// Input Parameters: int first_day, string month, int year, int end_month
//
// Output Parameters: cout
//
// Return Value: void
//
///////////////////////////////////////////////////////////////////////////////


void DisplayCalendar(int first_day, string month, int year, int end_month)
{
	//declare variables
	int size = 70; //size of calendars width
	int lines; //number of repatitions for each calendar section
	int index = 0; //index used for looping
	int counter = 0; // counter used for looping
	int date = 0; // the date that is printed
	int start_point = 0; // a counter used to determine if a date or whitespace should be printed


	// see how many lines the calendar needs
	if (first_day < 5) // if the first day of the month is monday thruough thursday print 5 lines for the calendar
		lines = 5;
	else
	{
		// if the first day is friday and there are less than 31 days in the month
		//print only 5 lines
		if (first_day == 5 && end_month < 31)
			lines = 5;
		else
		{
			// if the first day is saturday and there are less than 30 days in the month
			// print only 5 lines
			if (first_day == 6 && end_month < 30)
				lines = 5;
			else // if none of the conditions are true print 6 lines
				lines = 6;
		}
	}

	cout << month << "                                                              " << year << endl;
	cout << "      Sun       Mon       Tues      Wed       Thurs     Fri       Sat    " << endl;


	for(index; index < lines; index++) // loop for as many times as the integer in lines
	{
		cout << "   ";
		//display a solid horizontal line
		for(counter; counter <= size; counter ++)
			cout << "-";

		cout << endl << "   "; // endl the line and indent
		counter = 0;

		//display a verticle lines and spaces making the gerneral outline of the calendar
		for(counter; counter <= size; counter++)
		{
			if(counter % 10 != 0)
				cout << " ";
			else
				cout << "|";
		}

		cout << endl << "   "; // end the line and indent
		counter = 0;

		//display the dates and verticle lines
		for(counter; counter <= size; counter++)
		{
				//if the counter is in the right position diplay the date
				if(counter % 5 == 0 && counter % 10 != 0)
				{
					//starts the dates in the correct position
					if(start_point < first_day) // if the starting point is less then the start of the calendar print a blank
					{
						cout << " ";
						start_point++;
					}
					else
					{
						//if the date is past the amount of days in the month print a blank
						if(date > end_month - 1)
						{
							cout << "  ";
						}
						else //if neither of the above conditions are true print the date
						{
						date++; // increment date by one
						cout << date; // print date
						}
					}

				}
				else
				{
				//if the date is a single digit print whitespace and verticle lines int the correct spot
				if(date < 10)
					{
						if(counter % 10 != 0 && counter % 5 != 0) //if the counter is not in a spot where a line or a date goes print a blank
							cout << " ";
						if(counter % 10 == 0) // if the counter is in a position where a verticle line should go print a verticle line
							cout << "|";
					}

				//if the date is two digits print one less white space character to make room
				if(date >= 10)
					{
						if(counter % 10 != 0 && counter % 10 != 6) //if the counter is not in a position where a number or line goes print a space
							cout << " ";
						if(counter % 10 == 0)// if the counter is in a position where a line goes print a line
							cout << "|";
					}
				}
		}

		counter = 0;
		cout << endl << "   ";

		// print verticle lines and spaces for calender
		for(counter; counter <= size; counter++)
		{
			if(counter % 10 != 0)// if the counter is in a position where a blank should go print a blank
				cout << " ";
			else // if the counter is not in a position where a blank should go print a line
				cout << "|";
		}

		cout << endl << "   ";
		counter = 0;

		// print a solid line
		for(counter; counter <= size; counter ++)
			cout << "-";

	}
	cout << endl << endl;

}//end display calendar


////////////////////////////////GetMonth/////////////////////////////////
//
// Function name: GetMonth
//
// Purpose: Grabs the string value of the user selected month
//
// Input Parameters: int month
//
// Output Parameters: string month_str
//
// Return Value: month_str
//
/////////////////////////////////////////////////////////////////////////

string GetMonth(int month)
{

	//declare variables
	string month_str; // holds the months name

	//get the string version of the month
	switch(month){
		case 1:
			month_str = "January";
			break;
		case 2:
			month_str = "February";
			break;
		case 3:
			month_str = "March";
			break;
		case 4:
			month_str = "April";
			break;
		case 5:
			month_str = "May";
			break;
		case 6:
			month_str = "June";
			break;
		case 7:
			month_str = "July";
			break;
		case 8:
			month_str = "August";
			break;
		case 9:
			month_str = "September";
			break;
		case 10:
			month_str = "Octber";
			break;
		case 11:
			month_str = "November";
			break;
		case 12:
			month_str = "December";
			break;
		default:
			cout << "You did not enter a value between 1 and 12 for the month!";

			return month_str;
	}
}

////////////////////////////////GetEndMonth/////////////////////////////////
//
// Function name: GetEndMonth
//
// Purpose: gets the total days in
//
// Input Parameters:
//
// Output Parameters:
//
// Return Value:
//
/////////////////////////////////////////////////////////////////////////

int GetEndMonth(int month, bool leap)
{
	int end_month = 0;

	// get the number of days in a given month
	// if it is febuary check for leap year and adjust accordingly
	switch(month){
		case 1:
			 end_month = 31;
			 return end_month;
			break;
		case 2:
			if(leap == false)
			{
				end_month = 28;
				return end_month;
			}
			else
			{
				end_month = 29;
				return end_month;
			}
			break;
		case 3:
			end_month = 31;
			return end_month;
			break;
		case 4:
			end_month = 30;
			return end_month;
			break;
		case 5:
			end_month = 31;
			return end_month;
			break;
		case 6:
			end_month = 30;
			return end_month;
			break;
		case 7:
			end_month = 31;
			return end_month;
			break;
		case 8:
			end_month = 31;
			return end_month;
			break;
		case 9:
			end_month = 30;
			return end_month;
			break;
		case 10:
			end_month = 31;
			return end_month;
			break;
		case 11:
			end_month = 30;
			return end_month;
			break;
		case 12:
			end_month = 31;
			return end_month;
			break;
		default:
			cout << "error value out of range";
			return 0;


	}
}

////////////////////////////////GetFirstDay/////////////////////////////////
//
// Function name: GetFirstDay
//
// Purpose: Gets the first day of the month to be displayed
//
// Input Parameters: int month, int first_day_of_year
//
// Output Parameters: int firstday and -1
//
// Return Value: int
//
/////////////////////////////////////////////////////////////////////////

int GetFirstDay(int month, int first_day_of_year, bool leap)
{

	//int add_days;
	int firstday = 0;
	int holder = 0;

	//Calculates the first day of the month
	//the first day is used and the days in each month are added to the first day and
	//modulo divised by 7.
	switch(month)
	{
		case 1:
			firstday = first_day_of_year;
			return firstday;
		case 2:
			firstday = (first_day_of_year + 31) % 7;
			return firstday;
		case 3:
			if(leap == true)
			{
				firstday = (first_day_of_year + 60) % 7;
				return firstday;
			}
			else
			{
			firstday = (first_day_of_year + 59) % 7;
			return firstday;
			}
		case 4:
			if(leap == true)
			{
				firstday = (first_day_of_year + 91) % 7;
				return firstday;
			}
			else
			{
			firstday = (first_day_of_year + 90) % 7;
			return firstday;
			}
		case 5:
			if(leap == true)
			{
				firstday = (first_day_of_year + 121) % 7;
				return firstday;
			}
			else
			{
			firstday = (first_day_of_year + 120) % 7;
			return firstday;
			}
		case 6:
			if(leap == true)
			{
				firstday = (first_day_of_year + 152) % 7;
				return firstday;
			}
			else
			{
			firstday = (first_day_of_year + 151) % 7;
			return firstday;
			}
		case 7:
			if(leap == true)
			{
				firstday = (first_day_of_year + 182) % 7;
				return firstday;
			}
			else
			{
			firstday = (first_day_of_year + 181) % 7;
			return firstday;
			}
		case 8:
			if(leap == true)
			{
				firstday = (first_day_of_year + 213) % 7;
				return firstday;
			}
			else
			{
			firstday = (first_day_of_year + 212) % 7;
			return firstday;
			}
		case 9:
			if(leap == true)
			{
				firstday = (first_day_of_year + 244) % 7;
				return firstday;
			}
			else
			{
			firstday = (first_day_of_year + 243) % 7;
			return firstday;
			}
		case 10:
			if(leap == true)
			{
				firstday = (first_day_of_year + 274) % 7;
				return firstday;
			}
			else
			{
			firstday = (first_day_of_year + 273) % 7;
			return firstday;
			}
		case 11:
			if(leap == true)
			{
				firstday = (first_day_of_year + 305) % 7;
				return firstday;
			}
			else
			{
			firstday = (first_day_of_year + 304) % 7;
			return firstday;
			}
			case 12:
			if(leap == true)
			{
				firstday = (first_day_of_year + 335) % 7;
				return firstday;
			}
			else
			{
			firstday = (first_day_of_year + 334) % 7;
			return firstday;
			}

		default:
			cout << "Looks like you didn't choose a valid month";
			return -1;
	}
}

	////////////////////////////////ViewAgain()/////////////////////////////////
//
// Function name: ViewAgain
//
// Purpose: Returns true if the user wishes to view another month
//
// Input Parameters: none
//
// Output Parameters: bool
//
// Return Value: bool
//
///////////////////////////////////////////////////////////////////////////

bool ViewAgain()
{
	//declare variables
	int is_ended;

	//prompt user for decision
	cout << "Would you like to view another month?" << endl;
	cout << "1.yes" << endl;
	cout << "2.no" << endl;
	cin >> is_ended;
	while(!cin || (is_ended < 1)|| (is_ended > 2)){
        std::cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        std::cout << "Please enter 1 to continue or 2 to exit: ";
        std::cin >> is_ended;
	}
	cout << endl;

	if(is_ended == 1)
	return true;
	else
	return false;
}












// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;


string showComma(int number)
/** Shows where commas should be placed in an input of numbers
*Pre:   number is an int that is > 0
*Post:  d contains the divided number
r modulus the number while remainder returns r filled with approriate 0's
if d <= 1000, d and remainder are returned with appropriately placed commas
*/
{
	int d, r;
	string remainder;

	//return error message if number is less than 0
	if
		(number < 0)
		return " An invalid number was entered. Please enter positive values only.";

	//return string of number if less then 1000
	else if (number < 1000)
		return to_string(number);

	d = number / 1000; //  divide the number
	r = number % 1000; // modulus (remainder) the number

					   //fills in the missing zeros for modulus (remainder) r
	if (r < 10) {
		remainder = "00" + to_string(r);

	}
	else if (r < 100) {
		remainder = "0" + to_string(r);

	}
	else
		remainder = to_string(r);

	//calls recursive function and returns d and remainder with appropriately placed comma if d >= 1000
	if (d >= 1000)
		return showComma(d) + "," + remainder;

	//return final output string d and remainder with appropriately placed comma if d < 1000
	else {
		return to_string(d) + "," + remainder;
	}
}
//end of recursive function



int main()
{
	int number;
	string result;
	char answer = 'y';
	//Repeat loop when users want to try again
	while (answer == 'y' || answer == 'Y') {
		cout << "Show commas for: ";
		cin >> number;
		cout << endl;
		result = showComma(number);
		cout << "Result is: " << result << endl;
		cout << endl << "Would you like to do it again?(y/n) ";
		cin >> answer;
		cout << endl;
		//system("cls");
	}

	system("pause");
	return 0;
}


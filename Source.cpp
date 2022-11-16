// Check if its a valid credit card, does it stem from a known bank? (from a txt file?)
/* Check if the credit card number can be divided by 10 with no remaining numbers.
		Credit card number validation is performed using a public domain formula called the Luhn algorithm,
		as explained by the writers at GeeksforGeeks. This algorithm takes each digit of the credit card number
		(apart from the checksum), moving right to left, and doubles it.
		If doubling any of the numbers produces a sum greater than nine, subtract nine from the sum to get a single digit.
		Take the sum of all the digits, and if that sum is divisible by ten, then the card’s number is valid.
		Most credit card machines and credit card software automatically perform this calculation before accepting a card as payment.*/
		// Check the credit card 
		//
//https://dnschecker.org/credit-card-validator.php

#include <iostream>
#include <sstream>
using namespace std;

//check if number or string
bool check_number(string str) {
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false)
			return false;
	return true;
}
//count number of digits: THIS FUNCTION DOESNT WORK WELL
int countDigit(long long n)
{
	if (n == 0)
		return 1;
	int count = 0;
	while (n != 0) {
		n = n / 10;
		++count;
	}
	return count;
}

int main() {

	string card_no;
	cout << "Type your credit card number: "; // Type a number and press enter
	cin >> card_no; // Get user input from the keyboard
	cout << "Your number is: " << card_no << endl; // Display the input value

	//0. Check if user input is only int and the correct number of digits
	if (check_number(card_no))
		cout << card_no << " is an integer" << endl;
	else
		cout << card_no << " is a string" << endl;

	stringstream stream(card_no);
	int card_no_int;
	stream >> card_no_int;

	long long n = card_no_int;
	cout << "Number of digits : " << countDigit(n) << endl;

	if (n == 16 )
		cout << "Valid" << endl;
	else
		cout << "Not a credit card number." << endl;
	

	//1. Major industry identifier (MII)  


	//2. BIN/IIN (Bank/Issuer Identification Number)

	//3. Personal account number

	//4. Luhn Algorithm

	//5. Credit card prefix numbers
}

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

//Check if number or string 
bool check_number(string str) {
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i]) == false)
			return false;
	return true;
}
//Count number of digits
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

//Find the last digit
int lastDigit(int n)
{
	return (n % 10);
}

int main() {

	string card_no;
	cout << "Type your credit card number: "; // Type a number and press enter
	cin >> card_no; // Get user input 
	//cout << "Your number is: " << card_no << endl; // Display the input value

	//0. Check if user input is int only 
	bool initializer = true;
		while (initializer) {
			if (check_number(card_no)) {
				cout << card_no << " is an integer." << endl;

				//Output the card number as an integer (back from string)
				stringstream stream(card_no);
				long long card_no_int;
				stream >> card_no_int;
				long long n = card_no_int;

				//1. Check if the input has the right number of digits
				int dgts = countDigit(n);
				cout << "Number of digits : " << dgts << "\n" << endl;

				if (dgts == 16 || dgts == 17) {
					cout << "Valid." << endl;
					initializer = false;
				}
				else {
					cout << "Number of digits not correct. " << endl;
					goto jump;					
				}
			}
			else {
				cout << card_no << " is a string. " << endl;
			jump:
				cout << "Input a proper CC number or exit with 'x'. \n" << endl;
				cout << "Type your credit card number: "; // Type a number and press enter
				cin >> card_no; // Get user input 
				if (card_no == "x")
					return 0;
			}
		}
		
	
	

	//1. Major industry identifier (MII) (OSKAR)
		/*
		Create a list with MII categories assigned to numbers 0-9. Spit out the correct category based on the first digit of card_no
		*/

	//2. BIN/IIN (Bank/Issuer Identification Number)

	//3. Personal account number

	//4. Luhn Algorithm
		/*
		Example: 347609692102916
		1. Take last digit: 6
		*/
	//int last_d = lastDigit(card_no_int);
	//cout << last_d << " is the last digit." << endl;
	/*
		2. Take the rest of the sequence: 34760969210291
		3. Double every other digit starting from the right 3,8,7,12,0,18,6,18,2,2,0,4,9,2.
		4. Sum the digits of the products 12 = 1 + 2 = 3, same with 18 that gives you 9
		5. Add all the digits together 3+8+7+3+0+9+6+9+2+2+0+4+9+2 = 64
		6. Multiply the result by 9, 64 * 9 = 576
		7. Take the last digit of the result 6. If this matches the check digit, then we have a valid sequence.
		8.Since our check digit 6 matches our result 6, we conclude that this sequence is a valid credit card number.
		*/

	//5. Credit card prefix numbers (OSKAR)
		/*
		Create a list with credit card issuers assigned to prefix numbers. Spit out the correct credit card issuer.
		*/

}

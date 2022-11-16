







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
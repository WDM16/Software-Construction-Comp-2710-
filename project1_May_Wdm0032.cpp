/* project1_May_Wdm0032.cpp
 * Will May: Program that will tell user how many months to pay off loan.
 * Compiler: -std=c++15
 *
 * Sources:
 * Dr. Li's Project 1 hints
 * Piazza Question @65 (useful information in calculating and printing)
 * Piazza Question @33 (link that was answered by Tian Liu)
*/

#include <iostream>
using namespace std;

int main() {
	//VARIABLE INITIALIZATION 
	double loan;
	double interestRate;
	double interestRateC;
	double currentMonth = 0;	
	double interestTotal = 0;
	double monthlyInterest;
	double monthlyPayment;
	//CURRENCY FORMATTING
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	//USER INPUT
	//NOT: For valid input, the loan, interest, and monthly payment must 
	//be positive. The monthly payment must also be large enough to 
	//terminate the loan.
	cout << "\nLoan Amount: ";
	cin >> loan;
	
	//Work that enables program to move forward when a positive
	//loan is entered.
	if (loan <= 0 || !(loan)) {
		cout << "ERROR: INVALID LOAN\n\n";	
		return 0;
        }

	cout << "Interest Rate (% per year): ";
	cin >> interestRate;

	//Work that enables program to move forward when a positive 
	//interest rate is entered.
	 if (interestRate <= 0 || !(interestRate)) {
		cout << "ERROR: INVALID INTEREST RATE\n\n";
		return 0;
        }
	//GET PROPER INTEREST RATES FOR CALCULATIONS
	interestRate /= 12;
	interestRateC = interestRate / 100;
	cout << "Monthly Payments: ";
	cin >> monthlyPayment;
	
         if (monthlyPayment <= 0 || !(monthlyPayment)) {
                cout << "ERROR: INVALID MONTHLY PAYMENT\n\n";
                return 0;
        }

	cout << endl;

	//AMORTIZATION TABLE
	cout << "*****************************************************************\n"
	<< "\tAmortization Table\n"
	<< "*****************************************************************\n"
	<< "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";

	//LOOP TO FILL TABLE
	while (loan > 0) {
		if (currentMonth == 0) {
			cout << currentMonth++ << "\t$" << loan;
			if (loan < 1000) {
				cout << "\t";
			} 
			cout << "\t" << "N/A\tN/A\tN/A\t\tN/A\n";
		}
		else {
	//calculate and print.
	monthlyInterest = loan * interestRateC;
	interestTotal += monthlyInterest; 
	loan = (loan * (1 + interestRateC)) - monthlyPayment;
	if (loan < 0) {
		monthlyPayment += loan;
		loan = 0;
	}

	cout << currentMonth++ << "\t$" << loan << "\t";
	if (loan < 1000) {
		cout << "\t";
	}  
	cout << "$" << monthlyPayment << "\t" << interestRate << "\t"
		<< "$" << monthlyInterest << "\t\t"  "$" 
		<< monthlyPayment - monthlyInterest << endl;
					
	}
}
	cout << "****************************************************************\n";
	cout << "\nIt takes " << --currentMonth << " months to pay off "
	     << "the loan.\n"
	     << "Total interest paid is: $" << interestTotal;
	cout << endl << endl;
	return 0;

 }

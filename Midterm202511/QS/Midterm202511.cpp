#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include "polynomial1.h"
#include "BagInterface.h"
#include "ArrayBag.h"
#include "LinkedBag.h"

#define SIZE 10

using namespace std;

void input(string sMessage, string& sInputString)
{
	cout << sMessage << endl;
	cin >> sInputString;
	return;
}

void output(string sMessage)
{
	if (sMessage.length() > 0)
		cout << endl << sMessage << endl;

	return;
}

int inputNumber(string sMessage, int A[])
{
	int i = 0;

	for (; i < SIZE; i++) {
		cout << sMessage;
		cin >> A[i];

		if (A[i] == 0)
			break;
	}

	return i;
}

// ================ Question 1 Begins Here ==================

void prefixSumRecursive1(int arr[], int index) 
{

	// add yor code here

}

int prefixSumRecursive2(int arr[], int index)
{

	// add yor code here

	return arr[0];
}

void doQ1()
{
	int n;
	srand(time(0));
	n = 1 + rand() % 5;
	int* arr1 = new int[n];
	cout << "Current array: ";
	for (int i = 0; i < n; i++) {
		arr1[i] = rand() % 5; // random number between 0 and 99
		cout << arr1[i] << " ";
	}

	prefixSumRecursive1(arr1, n - 1);

	cout << "\nModified array: ";
	for (int i = 0; i < n; i++)
		cout << arr1[i] << " ";
	cout << "\n";

	int* arr2 = new int[n];
	cout << "Current array: ";
	for (int i = 0; i < n; i++) {
		arr2[i] = rand() % 5; // random number between 0 and 99
		cout << arr2[i] << " ";
	}

	prefixSumRecursive1(arr2, n - 1);

	cout << "\nModified array: ";
	for (int i = 0; i < n; i++)
		cout << arr2[i] << " ";
	cout << "\n";
}

// ================ Question 1 Ends Here ==================

// ================ Question 2 Begins Here =================
void doQ2()
{
	ArrayPolynomial aArrPoly, bArrPoly, cArrPoly;
	LinkedPolynomial aLinkPoly, bLinkPoly, cLinkPoly;

	int coef, expo;

	aArrPoly.clear();

	for (int i = 0; i < MAX_TERMS; i++) {
		cout << "\ninput A's coefficient and exponent: ";
		cin >> coef >> expo;

		if (expo == 0 && coef == 0)
			break;

		aArrPoly.inputTerms(coef, expo);
		aLinkPoly.inputTerms(coef, expo);
	}

	cout << endl;

	for (int i = 0; i < MAX_TERMS; i++) {
		cout << "\ninput B's coefficient and exponent: ";
		cin >> coef >> expo;

		if (expo == 0 && coef == 0)
			break;

		bArrPoly.inputTerms(coef, expo);
		bLinkPoly.inputTerms(coef, expo);
	}

	cout << "\n\n[Array Polynomial]\n";
	cout << "\na(X) = ";
	aArrPoly.printArrayBasedPoly();
	cout << "\nExponent of Max Coefficient: " << aArrPoly.exponentOfMaxCoef();
	cout << "\n\nb(X) = ";
	bArrPoly.printArrayBasedPoly();
	cout << "\nExponent of Max Coefficient: " << bArrPoly.exponentOfMaxCoef();

	if (aArrPoly.isSubPolynomialOf(bArrPoly))
		cout << "\n\na(X) is a subpolynomial of b(X)";
	else
		cout << "\n\na(X) is NOT a subpolynomial of b(X)";

	if (bArrPoly.isSubPolynomialOf(aArrPoly))
		cout << "\nb(X) is a subpolynomial of a(X)\n";
	else
		cout << "\nb(X) is NOT a subpolynomial of a(X)\n";

	cout << "\n\n[Link Polynomial]\n";
	cout << "\na(X) = ";
	aLinkPoly.printLinkBasedPoly();
	cout << "\nExponent of Max Coefficient:: " << aLinkPoly.exponentOfMaxCoef();
	cout << "\n\nb(X) = ";
	bLinkPoly.printLinkBasedPoly();
	cout << "\nExponent of Max Coefficient:: " << bLinkPoly.exponentOfMaxCoef();

	if (aLinkPoly.isSubPolynomialOf(bLinkPoly))
		cout << "\n\na(X) is a subpolynomial of b(X)";
	else
		cout << "\n\na(X) is NOT a subpolynomial of b(X)";

	if (bLinkPoly.isSubPolynomialOf(aLinkPoly))
		cout << "\nb(X) is a subpolynomial of a(X)\n";
	else
		cout << "\nb(X) is NOT a subpolynomial of a(X)\n";

	cout << "\n";
}
// ================ Question 2 Ends Here ==================

// ================ Question 3 Begins Here ==================

void displayBag(ArrayBag<string>& bag)
{
	cout << "It contains " << bag.getCurrentSize() << " items: ";
	vector<string> bagItems = bag.toVector();
	int numberOfEntries = (int)bagItems.size();

	for (int i = 0; i < numberOfEntries; i++)
		cout << bagItems[i] << " ";

	cout << endl;
}

void bagTester(ArrayBag<string>& bag)
{
	string items[] = { "5E", "1A", "3C", "5E", "3C", "5E", "3C", "5E" };
	string otherItems[] = { "1A", "5E", "3C", "2B", "4D" };

	cout << endl;
	cout << "Add 3 items to the bag: ";

	for (int i = 0; i < 3; i++) {
		bag.add(items[i]);
		cout << items[i] << ' ';
	}
	cout << endl;
	displayBag(bag);
	cout << endl;
	ArrayBag<string> other;
	cout << "Add 3 items to the other bag: ";
	for (int i = 0; i < 3; i++) {
		other.add(otherItems[i]);
		cout << otherItems[i] << ' ';
	}
	cout << endl;
	displayBag(other);
	cout << endl;

	if (bag.isSameUnordered(other))
		cout << "The bag is the same as the other bag";
	else
		cout << "The bag is NOT the same as the other bag";
	cout << endl;

	if (bag.containsAllValues(other))
		cout << "The bag contains all values in the other bag";
	else
		cout << "The bag does NOT contain all values in the other bag";
	cout << endl;	cout << endl;

	cout << "Add 5 items to the bag: ";

	for (int i = 3; i < 8; i++) {
		bag.add(items[i]);
		cout << items[i] << ' ';
	}
	cout << endl;
	displayBag(bag);
	cout << endl;
	cout << "Add 0 items to the other bag: ";
	cout << endl;
	displayBag(other);
	cout << endl;
	if (bag.isSameUnordered(other))
		cout << "The bag is the same as the other bag";
	else
		cout << "The bag is NOT the same as the other bag";
	cout << endl;

	if (bag.containsAllValues(other))
		cout << "The bag contains all values in the other bag";
	else
		cout << "The bag does NOT contain all values in the other bag";
	cout << endl;	cout << endl;
	cout << "Add 0 items to the bag: ";
	cout << endl;
	displayBag(bag);
	cout << endl;	
	cout << "Add  2 items to the other bag: ";
	for (int i = 3; i < 5; i++) {
		other.add(otherItems[i]);
		cout << otherItems[i] << ' ';
	}
	cout << endl;
	displayBag(other);
	cout << endl;
	if (bag.isSameUnordered(other))
		cout << "The bag is the same as the other bag";
	else
		cout << "The bag is NOT the same as the other bag";
	cout << endl;

	if (bag.containsAllValues(other))
		cout << "The bag contains all values in the other bag";
	else
		cout << "The bag does NOT contain all values in the other bag";
	cout << endl; 	cout << endl;
} 

void displayBag(LinkedBag<string>* bagPtr)
{
	cout << "It contains " << bagPtr->getCurrentSize() << " items: ";
	vector<string> bagItems = bagPtr->toVector();

	int numberOfEntries = (int)bagItems.size();

	for (int i = 0; i < numberOfEntries; i++)
		cout << bagItems[i] << " ";

	cout << endl;
}

void bagTester(LinkedBag<string>* bagPtr)
{
	string items[] = { "5E", "1A", "3C", "5E", "3C", "5E", "3C", "5E" };
	string otherItems[] = { "1A", "5E", "3C", "2B", "4D" };

	cout << endl;
	cout << "Add 3 items to the bag: ";

	for (int i = 0; i < 3; i++) {
		bagPtr->add(items[i]);
		cout << items[i] << ' ';
	}
	cout << endl;
	displayBag(bagPtr);
	cout << endl;
	LinkedBag<string>* otherPtr = nullptr;
	otherPtr = new LinkedBag<string>();
	cout << "Add 3 items to the other bag: ";
	for (int i = 0; i < 3; i++) {
		otherPtr->add(otherItems[i]);
		cout << otherItems[i] << ' ';
	}
	cout << endl;
	displayBag(otherPtr);
	cout << endl;

	if (bagPtr->isSameUnordered(otherPtr))
		cout << "The bag is the same as the other bag";
	else
		cout << "The bag is NOT the same as the other bag";
	cout << endl;

	if (bagPtr->containsAllValues(otherPtr))
		cout << "The bag contains all values in the other bag";
	else
		cout << "The bag does NOT contain all values in the other bag";
	cout << endl;	cout << endl;

	cout << "Add 5 items to the bag: ";

	for (int i = 3; i < 8; i++) {
		bagPtr->add(items[i]);
		cout << items[i] << ' ';
	}
	cout << endl;
	displayBag(bagPtr);
	cout << endl;
	cout << "Add 0 items to the other bag: ";
	cout << endl;
	displayBag(otherPtr);
	cout << endl;
	if (bagPtr->isSameUnordered(otherPtr))
		cout << "The bag is the same as the other bag";
	else
		cout << "The bag is NOT the same as the other bag";
	cout << endl;

	if (bagPtr->containsAllValues(otherPtr))
		cout << "The bag contains all values in the other bag";
	else
		cout << "The bag does NOT contain all values in the other bag";
	cout << endl;	cout << endl;
	cout << "Add 0 items to the bag: ";
	cout << endl;
	displayBag(bagPtr);
	cout << endl;
	cout << "Add  2 items to the other bag: ";
	for (int i = 3; i < 5; i++) {
		otherPtr->add(otherItems[i]);
		cout << otherItems[i] << ' ';
	}
	cout << endl;
	displayBag(otherPtr);
	cout << endl;
	if (bagPtr->isSameUnordered(otherPtr))
		cout << "The bag is the same as the other bag";
	else
		cout << "The bag is NOT the same as the other bag";
	cout << endl;

	if (bagPtr->containsAllValues(otherPtr))
		cout << "The bag contains all values in the other bag";
	else
		cout << "The bag does NOT contain all values in the other bag";
	cout << endl; 	cout << endl;
}

void doQ3()
{
	char userChoice = ' ';

	while (toupper(userChoice) != 'X') {
		cout << "Enter \n 'A' to test the array-based implementation\n"
			<< " 'L' to test the link-based implementation or\n 'X' to exit: ";
		cin >> userChoice;

		if (toupper(userChoice) == 'A') {
			ArrayBag<string> bag;
			cout << "Testing the Array-Based Bag:" << endl;
			cout << "The initial bag is empty." << endl;
			bagTester(bag);
		}
		else {
			LinkedBag<string>* bagPtr = nullptr;
			bagPtr = new LinkedBag<string>();

			cout << "Testing the Link-Based Bag:" << endl;
			cout << "The initial bag is empty." << endl;
			bagTester(bagPtr);
			delete bagPtr;
			bagPtr = nullptr;
		}

		cout << "All done!\n\n" << endl;
	}
}

// ================ Question 3 Ends Here ==================

// ============== Main Program Begins Here ================

int main()
{
	string sCommand, sName, sNum, sMessage;

	while (1) {
		cout << endl;
		cout << "1. Recursive functions" << endl;
		cout << "2. Polynomial functions" << endl;
		cout << "3. Bag functions" << endl;
		input("Enter Question Number( 1 ~ 3 ) or 0 to Exit:", sNum);

		switch (sNum[0] - '0') {
		case 0:
			return 0;
		case 1:
			doQ1();
			break;
		case 2:
			doQ2();
			break;
		case 3:
			doQ3();
			break;
		}
	}
}

// ============== Main Program Ends Here ================

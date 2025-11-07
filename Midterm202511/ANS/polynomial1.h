#include <iostream>
using namespace std;

#define MAX_TERMS 10 /*size of terms array*/

class PolynomialTerm
{
public:
	int coef;
	int expo;
};

class ArrayPolynomial
{
public:
	PolynomialTerm terms[MAX_TERMS];

	ArrayPolynomial()
	{
		for (int i = 0; i < MAX_TERMS; i++)
			terms[i].coef = terms[i].expo = 0;
	}

	void clear() /////
	{
		for (int i = 0; i < MAX_TERMS; i++)
		{
			terms[i].coef = 0;
			terms[i].expo = 0;
		}

		return;
	}

	void inputTerms(int coef, int expo)
	{
		int i = 0;

		for (; terms[i].coef != 0 && i < MAX_TERMS; i++)
			;

		terms[i].coef = coef;
		terms[i].expo = expo;

		return;
	}

	void printArrayBasedPoly()
	{
		if (terms[0].coef == 0)
			return;

		if (terms[0].expo == 0)
			cout << terms[0].coef;
		else
			cout << terms[0].coef << "X^" << terms[0].expo;

		for (int i = 1; i < MAX_TERMS; i++)
		{
			if (terms[i].coef == 0)
				return;

			if (terms[i].expo == 0)
				cout << " + " << terms[i].coef;
			else
				cout << " + " << terms[i].coef << "X^" << terms[i].expo;
		}

		return;
	}

	int exponentOfMaxCoef()
	{
		// add yor code here

		PolynomialTerm Max = this->terms[0];

		for (int i = 1; this->terms[i].expo != 0 || this->terms[i].coef != 0; i++)
		{
			if (this->terms[i].coef > Max.coef)
			{
				Max = this->terms[i];
			}
			else if (this->terms[i].coef == Max.coef && this->terms[i].expo > Max.expo)
			{
				Max = this->terms[i];
			}
		}

		return Max.expo;
	}

	bool isSubPolynomialOf(ArrayPolynomial &other)
	{

		// add your code here
	
		int i = 0;
		bool flag1 = false, flag2 = true;
		for (; i < MAX_TERMS; i++)
		{
			if (this->terms[0].expo == other.terms[i].expo && this->terms[0].coef == other.terms[i].coef)
			{
				flag1 = true;
				break;
			}
		}

		if (flag1)
		{
			for (int j = 0; j < MAX_TERMS; i++, j++)
			{
				if (this->terms[j].expo == 0 && this->terms[j].coef == 0)
					break;
				if ((this->terms[j].expo != other.terms[i].expo) || (this->terms[j].coef != other.terms[i].coef) || (i >= MAX_TERMS))
				{
					flag2 = false;
					break;
				}
			}
			return flag2;
		}

		return flag1;

		/*
		int i = 0;
		bool flag1 = false , flag2 = true;
		for (; i < MAX_TERMS; i++) {
			if (this->terms[i].expo == other.terms[0].expo && this->terms[i].coef == other.terms[0].coef) {
				flag1 = true;
				break;
			}
		}

		if (flag1) {
			for (int j=0; j<MAX_TERMS; i++,j++) {
				if (other.terms[j].expo == 0 && other.terms[j].coef == 0) break;
				if ((this->terms[i].expo != other.terms[j].expo) || (this->terms[i].coef != other.terms[j].coef) || (i >= MAX_TERMS)) {
					flag2 = false;
					break;
				}
				reutrn flag2;
			}
		}

		return flag1;
		*/
	}
};

class LinkedPolynomialTerm
{
public:
	int coef;
	int expo;
	LinkedPolynomialTerm *nextTermPtr;
};

class LinkedPolynomial
{
public:
	LinkedPolynomialTerm *polynomialTermPtr = nullptr;

	void clear()
	{
		LinkedPolynomialTerm *tmpPtr;

		while (polynomialTermPtr != nullptr)
		{
			tmpPtr = polynomialTermPtr;
			polynomialTermPtr = polynomialTermPtr->nextTermPtr;
			delete tmpPtr;
		}

		return;
	}

	void inputTerms(int coef, int expo)
	{
		// modify the following code and add your code here

		LinkedPolynomialTerm *tmpPtr;

		tmpPtr = new LinkedPolynomialTerm;
		tmpPtr->coef = coef;
		tmpPtr->expo = expo;
		tmpPtr->nextTermPtr = polynomialTermPtr;

		polynomialTermPtr = tmpPtr;

		return;
	}

	void printLinkBasedPoly()
	{
		LinkedPolynomialTerm *termPtr = polynomialTermPtr;

		if (termPtr == nullptr)
			return;

		if (termPtr->expo == 0)
			cout << termPtr->coef;
		else
			cout << termPtr->coef << "X^" << termPtr->expo;

		termPtr = termPtr->nextTermPtr;

		while (termPtr != nullptr)
		{
			if (termPtr->coef == 0)
				return;

			if (termPtr->expo == 0)
				cout << " + " << termPtr->coef;
			else
				cout << " + " << termPtr->coef << "X^" << termPtr->expo;

			termPtr = termPtr->nextTermPtr;
		}

		return;
	}

	int exponentOfMaxCoef()
	{
		// add yor code here

		LinkedPolynomialTerm *MaxPtr = this->polynomialTermPtr, *currentPtr = polynomialTermPtr->nextTermPtr;

		while (currentPtr)
		{
			if (currentPtr->coef > MaxPtr->coef)
			{
				MaxPtr = currentPtr;
			}
			else if (currentPtr->coef == MaxPtr->coef && currentPtr->expo > MaxPtr->expo)
			{
				MaxPtr = currentPtr;
			}
			currentPtr = currentPtr->nextTermPtr;
		}

		return MaxPtr->expo;
	}

	bool isSubPolynomialOf(LinkedPolynomial &other)
	{
		// add your code here

		LinkedPolynomialTerm *otherCurrentPtr = other.polynomialTermPtr, *tempPtr = nullptr;

		while (otherCurrentPtr)
		{
			LinkedPolynomialTerm *myCurrentPtr = this->polynomialTermPtr;

			if (myCurrentPtr->expo == otherCurrentPtr->expo && myCurrentPtr->coef == otherCurrentPtr->coef)
			{
				tempPtr = otherCurrentPtr;
				while (myCurrentPtr)
				{
					if (!tempPtr)
						return false;
					if (myCurrentPtr->expo != tempPtr->expo || myCurrentPtr->coef != tempPtr->coef)
						return false;
					myCurrentPtr = myCurrentPtr->nextTermPtr;
					tempPtr = tempPtr->nextTermPtr;
				}
				return true;
			}
			otherCurrentPtr = otherCurrentPtr->nextTermPtr;
		}
		return false;
	}
};

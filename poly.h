// -----------------------------------poly.h-----------------------------------
// Wajeeha Ahmad CSS 502A
// Date Created: January 12, 2021
// Last Modified: January 14, 2021
// ----------------------------------------------------------------------------
// The poly.h class is an array-based implementation to represent a polynomial.
// For example, you can represent the polynomial -3x7 + 4x3 + 9 as an array
// with -3 at the 7th index, 4 at the 3rd index, and 9 at the 0 index.
// ----------------------------------------------------------------------------
// The arrays will be dynamically allocating initial memory using only as many
// elements as needed. They will be made larger when needed, but not smaller 
// because that is inefficient.
// ----------------------------------------------------------------------------
#ifndef POLYNOMIAL_H                                   
#define POLYNOMIAL_H
#include <iostream>
#include <string>
using namespace std;


class Poly {
// -------------------------------- ostream -----------------------------------
// Description: Prints the polynomial in the standard form.
//
// PRE:         Polynomial has a term in it.
// POST:        Prints Cn * x^n + Cn-1 * X^n-1 + ... C1 * X + C0
// ----------------------------------------------------------------------------
  friend ostream& operator<<(ostream &output, const Poly &p );
// -------------------------------- istream -----------------------------------
// Description: User enters one coefficient and one exponent repeatedly, for 
//              example if user enters "5 7 10 1 -4 3 -2 0 -1 -1" then the 
//              polynomial in the parameter is set to 5x^7 -4x^3 +10x –2.
//              The user enters -1 for both coeff and exponent when done.
//
// PRE:         user enters pairs of numbers in any order
// POST:        Assigns user input into polynomial, enters -1 when done
// ----------------------------------------------------------------------------
  friend istream& operator>>(istream &input, Poly &p );

 public:
// ---------------------- CONSTRUCTORS AND DESTRUCTORS ------------------------
// ------------------------------ default constructor -------------------------
  Poly( );
// ------------------------------- copy constructor ---------------------------
  Poly( const Poly& p );
// ------------------------ coeff & exponent constructor ----------------------
  Poly(int coeff, int expo);
// -------------------------- coeff only constructor --------------------------
  Poly(int coeff);
// ---------------------------------- destructor ------------------------------
  ~Poly( );

// ----------------------------- MEMBER FUNCTIONS -----------------------------
// ---------------------------------- getCoeff --------------------------------
// Description: Returns the coefficient of the x^power term.
//
// PRE:         The user is looking for the coefficient with the power in the
//              param.
// POST:        Returns the coefficient of the x^power term, if not found, 
//              returns 0.
// ----------------------------------------------------------------------------
  int getCoeff( const int power ) const; 
// --------------------------------- setCoeff ---------------------------------
// Description: Replaces the coefficient of the x^power term.
//
// PRE:         User gives correct parameters and not a negative exponent.
// POST:        Replaces the coefficient of the x^power term and returns true.
// ----------------------------------------------------------------------------
  bool setCoeff( const int newCoefficient, const int power );

// -----------------------------ARITHMETIC OPERATORS---------------------------
// --------------------------------- operator+ --------------------------------
// Description: Adds two polynomials together.
//
// PRE:         User provides polynomials to add.
// POST:        Returns a polynomial that is the sum of the two polynomials.
// ----------------------------------------------------------------------------
  Poly operator+( const Poly& p ) const;
// --------------------------------- operator- --------------------------------
// Description: Subtracts the param polynomial from the current polynomial.
//
// PRE:         User provides polynomials to subtract.
// POST:        Returns a polynomial that is the difference.
// ----------------------------------------------------------------------------
  Poly operator-( const Poly& p ) const;
// --------------------------------- operator* --------------------------------
// Description: Multiplies two polynomials together.
//
// PRE:         User provides polynomials to multiply.
// POST:        Returns polynomial that is the product of the two polynomials.
// ----------------------------------------------------------------------------
  Poly operator*( const Poly& p ) const;

// ---------------------BOOLEAN COMPARISON OPERATORS---------------------------
// ------------------------------- operator== ---------------------------------
// Description: Returns true when corresponding terms of two given polynomials
//              match each other.
//
// PRE:         User provides two polynomials to compare.
// POST:        Returns true if the polynomials terms match, false otherwise.
// ----------------------------------------------------------------------------
  bool operator==( const Poly& p ) const;
// ------------------------------- operator!= ---------------------------------
// Description: Returns true when corresponding terms of two given polynomials
//              do not match each other.
//
// PRE:         User provides two polynomials to compare.
// POST:        Returns true if the polynomials terms don't match, false 
//              if they do match.
// ----------------------------------------------------------------------------
  bool operator!=( const Poly& p ) const;

// ----------------------------ASSIGNMENT OPERATORS---------------------------
// -------------------------------- operator= ---------------------------------
// Description: This clears the current polynomial and assigns it the same 
//              terms as the param polynomial.
//
// PRE:         The user provides two polynomials and assigns the current one.
// POST:        The current polynomial is assigned the same terms as the param
//              polynomial.
// ----------------------------------------------------------------------------
  Poly& operator=( const Poly& p );
// ------------------------------- operator+= ---------------------------------
// Description: This assigns the current polynomial to equal the sum of the 
//              current polynomial and the param polynomial.
//
// PRE:         The user provides two polynomials and assigns the current one. 
// POST:        The current polynomial equals the sum of the two polynomials.
// ----------------------------------------------------------------------------
  Poly& operator+=( const Poly& p );
// ------------------------------- operator-= ---------------------------------
// Description: This assigns the current polynomial to equal the difference of 
//              the current polynomial minus the param polynomial.
//
// PRE:         The user provides two polynomials and assigns the current one. 
// POST:        The current polynomial equals the difference of the two 
//              polynomials.
// ----------------------------------------------------------------------------
  Poly& operator-=( const Poly& p );
// ------------------------------- operator*= ---------------------------------
// Description: This assigns the current polynomial to equal the product of the 
//              current polynomial and the param polynomial.
//
// PRE:         The user provides two polynomials and assigns the current one. 
// POST:        The current polynomial equals the product of the two polynomials.
// ----------------------------------------------------------------------------
  Poly& operator*=( const Poly& p );

 private:
  int* polynomial; // array
  int size;   // array space in the polynomial
  int countTerms() const; // number of non-zero terms in polynomial

};

#endif

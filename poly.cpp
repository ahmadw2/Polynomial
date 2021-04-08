// -----------------------------------poly.cpp---------------------------------
// Wajeeha Ahmad CSS 502A
// Date Created: January 12, 2021
// Last Modified: January 14, 2021
// ----------------------------------------------------------------------------
// The poly.cpp class is an array-based implementation to represent a polynomial.
// For example, you can represent the polynomial -3x7 + 4x3 + 9 as an array
// with -3 at the 7th index, 4 at the 3rd index, and 9 at the 0 index.
// ----------------------------------------------------------------------------
// The arrays will be dynamically allocating initial memory using only as many
// elements as needed. They will be made larger when needed, but not smaller 
// because that is inefficient.
// ----------------------------------------------------------------------------
#include "poly.h"

// ---------------------- CONSTRUCTORS AND DESTRUCTORS ------------------------
// ------------------------------ default constructor -------------------------
  Poly::Poly( ){
    polynomial = new int[1];
    polynomial[0] = 0;
    size = 0;
  }
// ------------------------------- copy constructor ---------------------------
  Poly::Poly( const Poly& p ){
    polynomial = new int[p.size];
    for(int i = 0; i < p.size; i++){
      polynomial[i] = p.polynomial[i];
    }
    size = p.size;
  }
// ------------------------ coeff & exponent constructor ----------------------
  Poly::Poly(int coeff, int expo){
    polynomial = new int[expo + 1]; 
    for(int i = 0; i <= expo; i++){
      polynomial[i] = 0;
    }
    polynomial[expo] = coeff;
    size = (expo + 1);
  }
// -------------------------- coeff only constructor --------------------------
  Poly::Poly(int coeff){
    polynomial = new int[1];
    polynomial[0] = coeff;
    size = 1;
  }
// ---------------------------------- destructor ------------------------------
  Poly::~Poly( ){
    delete [] polynomial;
    polynomial = NULL;
    size = 0;
  }

// ----------------------------- MEMBER FUNCTIONS -----------------------------
// ---------------------------------- getCoeff --------------------------------
// Description: Returns the coefficient of the x^power term.
//
// PRE:         The user is looking for the coefficient with the power in the
//              param.
// POST:        Returns the coefficient of the x^power term, if not found, 
//              returns 0.
// ----------------------------------------------------------------------------
  int Poly::getCoeff( const int power ) const{
    if(power < 0 || power > size){
      return 0;
    }
    return polynomial[power];
  } 
// --------------------------------- setCoeff ---------------------------------
// Description: Replaces the coefficient of the x^power term.
//
// PRE:         User gives correct parameters and not a negative exponent.
// POST:        Replaces the coefficient of the x^power term and returns true.
// ----------------------------------------------------------------------------
  bool Poly::setCoeff( const int newCoefficient, const int power ){
    if(power < 0){
      return false;
    }
    if(power <= size){
      polynomial[power] = newCoefficient;
      return true;
    }
    if(power > size){
      Poly old(*this);
      delete [] polynomial;
      polynomial = NULL;
      polynomial = new int[power + 1];
      size = (power + 1); 
      for(int i = 0; i < size; i++){
        polynomial[i] = 0;
      }
      for(int i = 0; i < old.size; i++){
        polynomial[i] = old.polynomial[i];
      }
      polynomial[power] = newCoefficient;
      delete [] old.polynomial;
      old.polynomial = NULL;
      return true;
    }
    return false;
  }

// -----------------------------ARITHMETIC OPERATORS---------------------------
// --------------------------------- operator+ --------------------------------
// Description: Adds two polynomials together.
//
// PRE:         User provides polynomials to add.
// POST:        Returns a polynomial that is the sum of the two polynomials.
// ----------------------------------------------------------------------------
  Poly Poly::operator+( const Poly& p ) const{
    Poly T;
    int newCoeff;
    int smallerSize;
    if(p.size > size){
      smallerSize = size;
      T = p;
      for(int i = 0; i < smallerSize; i++){
        newCoeff = polynomial[i] + p.polynomial[i];
         T.setCoeff(newCoeff, i);
      }
    }
    if(size >= p.size){
      smallerSize = p.size;
      T = *this;
      for(int i = 0; i < smallerSize; i++){
        newCoeff = polynomial[i] + p.polynomial[i];
         T.setCoeff(newCoeff, i);
      }
    }
    return T;
  }
// --------------------------------- operator- --------------------------------
// Description: Subtracts the param polynomial from the current polynomial.
//
// PRE:         User provides polynomials to subtract.
// POST:        Returns a polynomial that is the difference.
// ----------------------------------------------------------------------------
  Poly Poly::operator-( const Poly& p ) const{
    Poly T;
    Poly copy(0,(p.size-1));
    for (int i = 0; i < p.size; i++){
      int inverse = (p.polynomial[i] * -1);
      copy.setCoeff(inverse, i);
    }
    T = *this + copy;
    delete [] copy.polynomial;
    copy.polynomial = NULL;
    return T;
  }
// --------------------------------- operator* --------------------------------
// Description: Multiplies two polynomials together.
//
// PRE:         User provides polynomials to multiply.
// POST:        Returns polynomial that is the product of the two polynomials.
// ----------------------------------------------------------------------------
  Poly Poly::operator*( const Poly& p ) const{
    Poly T;
    if(countTerms() == 0 || p.countTerms() == 0){
      return T;
    }
    T.setCoeff(0, (size + p.size - 1));
    for(int i = 0; i < size; i++){
      for(int j = 0; j < p.size; j++){
        T.polynomial[i+j] += (polynomial[i] * p.polynomial[j]);
      }
    }
    return T;
  }

// ---------------------BOOLEAN COMPARISON OPERATORS---------------------------
// ------------------------------- operator== ---------------------------------
// Description: Returns true when corresponding terms of two given polynomials
//              match each other.
//
// PRE:         User provides two polynomials to compare.
// POST:        Returns true if the polynomials terms match, false otherwise.
// ----------------------------------------------------------------------------
  bool Poly::operator==( const Poly& p ) const{
    if(size != p.size){
      return false;
    }
    if(size == 0 && p.size == 0){
      if(polynomial[0] == p.polynomial[0]){
        return true;
      }
      else{
        return false;
      }
    }
    for(int i = 0; i < size; i++){
      if(polynomial[i] != p.polynomial[i]){
        return false;
      }
    }
    return true;
  }
// ------------------------------- operator!= ---------------------------------
// Description: Returns true when corresponding terms of two given polynomials
//              do not match each other.
//
// PRE:         User provides two polynomials to compare.
// POST:        Returns true if the polynomials terms don't match, false 
//              if they do match.
// ----------------------------------------------------------------------------
  bool Poly::operator!=( const Poly& p ) const{
    if(*this == p){
      return false;
    }
    else{
      return true;
    }
  }

// ----------------------------ASSIGNMENT OPERATORS---------------------------
// -------------------------------- operator= ---------------------------------
// Description: This clears the current polynomial and assigns it the same 
//              terms as the param polynomial.
//
// PRE:         The user provides two polynomials and assigns the current one.
// POST:        The current polynomial is assigned the same terms as the param
//              polynomial.
// ----------------------------------------------------------------------------
  Poly& Poly::operator=( const Poly& p ){
    if(this != &p){
      delete [] polynomial;
      polynomial = NULL;
      polynomial = new int[p.size];
      size = p.size;
      for(int i = 0; i < p.size; i++){
        polynomial[i] = p.polynomial[i];
      }
    }
    return *this;
  }
// ------------------------------- operator+= ---------------------------------
// Description: This assigns the current polynomial to equal the sum of the 
//              current polynomial and the param polynomial.
//
// PRE:         The user provides two polynomials and assigns the current one. 
// POST:        The current polynomial equals the sum of the two polynomials.
// ----------------------------------------------------------------------------
  Poly& Poly::operator+=( const Poly& p ){
    Poly d = *this;
    d = d + p;
    *this = d;
    return *this;
  }
// ------------------------------- operator-= ---------------------------------
// Description: This assigns the current polynomial to equal the difference of 
//              the current polynomial minus the param polynomial.
//
// PRE:         The user provides two polynomials and assigns the current one. 
// POST:        The current polynomial equals the difference of the two 
//              polynomials.
// ----------------------------------------------------------------------------
  Poly& Poly::operator-=( const Poly& p ){
    Poly d = *this;
    d = d - p;
    *this = d;
    return *this; 
  }
// ------------------------------- operator*= ---------------------------------
// Description: This assigns the current polynomial to equal the product of the 
//              current polynomial and the param polynomial.
//
// PRE:         The user provides two polynomials and assigns the current one. 
// POST:        The current polynomial equals the product of the two polynomials.
// ----------------------------------------------------------------------------
  Poly& Poly::operator*=( const Poly& p ){
    Poly d = *this;
    d = d * p;
    *this = d;
    return *this;
  }

// -------------------------------- ostream -----------------------------------
// Description: Prints the polynomial in the standard form.
//
// PRE:         Polynomial has a term in it.
// POST:        Prints Cn * x^n + Cn-1 * X^n-1 + ... C1 * X + C0
// ----------------------------------------------------------------------------
  ostream& operator<<(ostream &output, const Poly &p ){
    if(p.countTerms() == 0){
      output << " 0";
      return output;
    }

    for(int i = (p.size-1); i > -1; i--){
      if(p.polynomial[i] != 0){
        if(p.polynomial[i] > 0 && i == 0){
          output << " +" << p.polynomial[i];
        }
        else if(p.polynomial[i] < 0 && i == 0){
          output << " " << p.polynomial[i];
        }
        else if(p.polynomial[i] > 0 && i == 1){
          output << " +" << p.polynomial[i]<< "x";
        }
        else if(p.polynomial[i] < 0 && i == 1){
          output << " " << p.polynomial[i] << "x";
        }
        else if(p.polynomial[i] > 0 && i != 0){
          output << " +" << p.polynomial[i] << "x^" << (i);
        }
        else if(p.polynomial[i] < 0 && i != 0){
          output << " " << p.polynomial[i] << "x^" << (i);
        }
      }
    }

  return output;
  }
// -------------------------------- istream -----------------------------------
// Description: User enters one coefficient and one exponent repeatedly, for 
//              example if user enters "5 7 10 1 -4 3 -2 0 -1 -1" then the 
//              polynomial in the parameter is set to 5x^7 -4x^3 +10x –2.
//              The user enters -1 for both coeff and exponent when done.
//
// PRE:         user enters pairs of numbers in any order
// POST:        Assigns user input into polynomial, enters -1 when done
// ----------------------------------------------------------------------------
  istream& operator>>(istream &input, Poly &p ){
    int coeff;
    int power;
    input >> coeff >> power;
    while(coeff != -1 && power != -1){
      p.setCoeff(coeff, power);
      input >> coeff >> power;
    }
    return input;
  }

// ------------------------------- countTerms ---------------------------------
// Description: Private method that returns the number of non-zero terms in 
//              polynomial.
//
// PRE:         Polynomial has Terms in it
// POST:        Returns amount of non-zero terms in polynomial.
// ----------------------------------------------------------------------------
  int Poly::countTerms() const{
    int count = 0;
    if(size == 0){
      return 0;
    }
    for(int i = 0; i < size; i++){
      if(polynomial[i] != 0){
        count++;
      }
    }
    return count;
  }

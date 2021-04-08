#include "poly.h"
#include <iostream>
using namespace std;

int main() {
	Poly A(5, 7), B(3, 4), C(2), D(A), X, Y;
	Poly A2, B2, Z1, Z2;
  cout << A << endl;
  cout << B << endl;
  cout << C << endl;
  cout << D << endl;
  cout << X << endl;

  Y.setCoeff(5, 6);
  Y.setCoeff(0, 5);
  Y.setCoeff(-5, 4);
  Y.setCoeff(-1, 3);
  Y.setCoeff(1, 2);
  Y.setCoeff(5, 1);
  Y.setCoeff(5, 0);
 
  Poly Q(-3, 4);
  Z2 = B + Q;
  cout << Z2 << endl;
  cout << Y << endl;
  A2 = A;
	B2 = B;
	X = A + B;
	cout << "Compute X = A + B: " << X << endl << endl;
  Z1 = B2 - B;
  cout << "Compute Z1 = B2 - B: " << Z1 << endl << endl;
  Z2 = X * Y;
  cout << "Compute Z2 = X * Y: " << Z2 << endl << endl;

	cout << ((A == B) ? "A == B" : "A is not == B") << endl;
	cout << ((A != B) ? "A is not == B" : "A == B") << endl << endl;

	A2 += B2;
	cout << "Compute A2 += B2: " << A2 << endl;
	B2 -= A2;
	cout << "Compute  B2 -= A2: " << B2 << endl << endl;
  B2 *= A2;
	cout << "Compute  B2 *= A2: " << B2 << endl << endl;
}
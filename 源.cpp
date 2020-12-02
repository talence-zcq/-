#include <iostream>
#include"link.h"
using namespace std;
int main()
{
	Poly<double> s1,s2,s3,s4;
	s1.add(6);
	s1.display();
	s2.add(5);
	s2.display();
	s3 = s1 + s2;
	s3.display();
	s4=s3.Derivation();
	s4.display();
	s4 = s1 * s2;
	s4.display();
}
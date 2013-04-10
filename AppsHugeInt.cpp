#include<iostream>
#include "HugeInt.h"
#include "stdio.h"
using namespace std;

int main()
{
	HugeInt bigInt();
	cout << "bigInt = " << bigInt << "\n";
	
	HugeInt bigInt1("1234");
	cout << bigInt1;
	
	HugeInt bigInt2("1239");
	cout << bigInt2;
	if(bigInt1 == bigInt2) 
	{
		cout << "BigInt1 and BigInt2 have the same value\n";
	}	
	else
	{
		cout << "BigInt1 is not same as BigInt2\n";
	}
	if(bigInt1 != bigInt2)
	{
		cout << "BigInt1 and BigInt2 are the different value\n";
	}else
	{
		cout << "BigInt1 and BigInt2 are the same value\n";
	}

	
	HugeInt a("9000");
	HugeInt b("999");
	HugeInt c("109");

	cout << "before increment\n";
	cout << "1345 = " << a ;
	cout << "999 = "<<b ;
	cout << "109 = "<<c ;

	cout << "After pre-increment\n";	
	cout << "1345+1 =" <<++a ;
	cout << "999+1 =" <<++b ;
	cout << "109+1 =" <<++c ;
	
	
	cout << "before post-increment\n";
	cout << "a = " << a;
	cout << "\nb = " << b;
	cout << "\nc = " << c;
	cout << a++ << "\n";
	cout << b++ << "\n";
	cout << c++ << "\n";
	
	
	cout << "After post-increment\n";	
	cout << "a = " << a;
	cout << "\nb = " << b;
	cout << "\nc = " << c;

	cout << "Addition\n";
	cout << "a + b = " <<  a + b;
	cout << "check number of digit\n";
	printf("a contains: %d digits\n", a.numDigits());
	printf("b contains: %d digits\n", b.numDigits());
	printf("c contains: %d digits\n", c.numDigits());
	cout << "\noperator overloading baracket\n";   
	cout << "a[1] = " <<  a[1] << "\n";
	/* 1st: do a[1] that means activate operator overloading[];
	 * 2nd: execute cout << "a[1] = " << returned value  
	 */
   
	a[1] = 6;//insert n th digit to be 6
	cout << "a[1] = " <<  a[1] << "\n"; 
	cout << "a = " << a << "\n";  
	/*
	int index = 0;
	cout << "which digits would you like to know?\n";	
	cin >> index;
	cout << "index : " << index << "\n";
	//cout << "element: "  << BigInt1.[index];
	//BigInt1[index]* = 6;//insert 6 where user want to see
*/

	//return 0;
}//main

#include <iostream>
#include "math.h"
#include "HugeInt.h"
#include "stdlib.h"//where atoi and exit  is tored 
using namespace std; 

HugeInt::HugeInt()
{
	length = 4;
	for(int i =0; i < SIZE; i++)
	{
		if(i < 4)
		{
			digits[i] = 5;
		}
		else
		{
			digits[i] = 0;
		}

	}
}

HugeInt::HugeInt(string value)
{
	//int length;
	for(int n = 0; n < SIZE; n++)
	{//initialize array 
	 //in order to avoid to enter unknow value automatically 
		digits[n] = 0;
		//cout << digits[n] << "\n";
	}
	//cout << "2nd";

	length=value.length();
	if(allDigits(value))
	{
		//cout << "3rd\n";
		for(int i = 0; i < length + 1; i++)
		{
			
			digits[i] = atoi(&value[value.length()-1 - i]);
			value[value.length() - 1 - i] = 0x00;
			//cout << "i = " << i << "\n" ;
			//cout << "digit = " << digits[i]<< "\n";
		}

	}
	else
	{
		cout << "entered value is invalid";
	}

}

int HugeInt::numDigits() const
{//return the num of digits in this HugeInt array 
	
	return this->length;

}
 
int &HugeInt::operator[] (int n)
{
	cout << "inside []\n";
	//int fals = -1;
	if(n <= 0 && n > length)
	{	cout << "length = " << length << "\n";
		cout << "before exit from cpp\n";
		exit(-1);
	}
	cout << "out side of if\n";
	return this->digits[n];
}

HugeInt HugeInt::operator++()
{//operator overloading with pre-increment 

	//HugeInt postIncrement = *this;
	HugeInt preIncrement("0");

	preIncrement.length=this->length;
	for (int i=0;i<this->length;i++)
	{
		preIncrement.digits[i]=this->digits[i];
		//cout<<this->digits[i];
	}

	int index = 0;
	//cout<<"preIncrement=";
	//cout<<preIncrement<<"\n";

	preIncrement.digits[index]++;
	
	while(index < length)
	{ 
		if(preIncrement.digits[index] == 10)
		{
			preIncrement.digits[index] = 0;
			preIncrement.digits[index + 1] += 1;
			if(index == preIncrement.length-1)
			{
				preIncrement.length += 1;
				
			}
			index++;
			 
		}
		else
		{
			return (preIncrement);
		} 
	}
	return (preIncrement);
}

HugeInt HugeInt::operator++(int)
{//opeartor overloading with post-increment 

	//HugeInt postIncrement = *this;
	HugeInt postIncrement("0");

	postIncrement.length=this->length;
	for (int i=0;i<this->length;i++)
	{//make a copy 
		postIncrement.digits[i]=this->digits[i];
		//cout<<this->digits[i];
	}

	int index = 0;	
	//cout<<"postIncrement=";
	//cout<<postIncrement<<"\n";
	
	this->digits[index] = this->digits[index] + 1;
	while(index < length)
	{
		if(this->digits[index] == 10)
		{
			this->digits[index] = 0;
			this->digits[index + 1] += 1;
			if(index == this->length-1)
			{
				this->length += 1;
			}
			index++;
		}
		else
		{
			return (postIncrement);
		}
	
	}
	return (postIncrement);

}

bool HugeInt::operator==(const HugeInt& operand)const
{ 
	if(this->length == operand.length)
	{
		for(int k = 0; k < this->length; k++)
		{
			if(digits[k] != operand.digits[k])
			{
				return false;
			}		
		}	
		return true; 
	}
	else
	{
		return false;
	}
}

bool HugeInt::operator!= (const HugeInt& operand)const
{
	if (this->length==operand.length)
	{
		for(int index = 0; index < this->length; index++)
		{
			if(digits[index] != operand.digits[index])
			{
				return true;
			}
		}
		return false;
	}else
	{
		return true;
	}

}
//should not define 'frind' here(only with .h file)
//do not need class name since it is not member function(?)
ostream& operator<<(ostream& out, const HugeInt& obj)
{
	//char buffer[50];
	//int hugeInt = 0;//store actual value of integer.
	//unsigned Position =0;
	cout << endl << "{ ";

	for (int i=0;i<obj.length;i++)
	{
		cout << obj.digits[obj.length-1-i];// << ", ";
	}
	cout << " }" << endl;

	return out;


}

HugeInt operator+ (const HugeInt& operand1, const HugeInt& operand2)
{	
	HugeInt sumInt("0");
	//avoid to call defalut const (no-ags param) and init to be 0
	if(operand1.length > operand2.length)
	{
		sumInt.length = operand1.length;
		for (int i=0;i< operand1.length; i++)
		{//make a copy 
			sumInt.digits[i]= operand1.digits[i];
			//cout<<this->digits[i];
		}
		
		for(int i = 0; i < operand2.length ; i++)
		{
			sumInt.digits[i] += operand2.digits[i];
			if(sumInt.digits[i] >= 10)
			{
				sumInt.digits[i] = (int) (sumInt.digits[i] % 10);
				sumInt.digits[i+1] += 1;
				
				if(i == sumInt.length-1)
				{
					sumInt.length += 1;
				}
			}
			
		}
	}
	else
	{
		sumInt.length = operand2.length;
		for(int i = 0; i < operand2.length; i++)
		{//make a copy
			sumInt.digits[i] = operand2.digits[i];
		}
		for(int k = 0; k < operand1.length; k++)
		{
			
			sumInt.digits[k] += operand1.digits[k];
			if(sumInt.digits[k] >= 10)
			{
				sumInt.digits[k] = (int) (sumInt.digits[k] % 10);
				sumInt.digits[k+1] += 1;
				
				if(k == sumInt.length-1)
				{
					sumInt.length += 1;
				}
			}
		}
	}
	

	return sumInt;
}
bool HugeInt::allDigits(string str)
{
	int len;
	len=str.length();
	for(int i = 0; i < len; i++)
	{
		if(!isdigit(str[i]))
		{
			return false;	
		}
	}
	return true; 
}






/*

HugeInt HugeInt::operator=()
{//operator overloading with pre-increment

	//HugeInt postIncrement = *this;
	HugeInt target("0");

	target.length=this->length;
	for (int i=0;i<this->length;i++)
	{
		target.digits[i]=this->digits[i];
		//cout<<this->digits[i];
	}

	return (target);
}

*/

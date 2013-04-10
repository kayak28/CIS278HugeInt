#include <ostream>
using namespace std;
class HugeInt 
{
	public:
		HugeInt();
		HugeInt(string value);
		
		int numDigits() const;
		HugeInt operator ++();
		//HugeInt operator =();
		HugeInt operator ++(int);
		bool operator ==(const HugeInt& operand) const;
		bool operator !=(const HugeInt& operand) const;
		friend ostream& operator <<(ostream& out, const HugeInt& obj);
		friend HugeInt operator+(const HugeInt& operend1, const HugeInt& obj);
		
		int &operator[] (int n);
		static bool allDigits(string str);

	private:
		static const  int SIZE = 50; 
		int digits[SIZE];
		int length;
};
//int HugeInt::&operator [](int i);
/*{
	if(n < 0 && n > length)
	{
		return -1;
	}
	return digits[n];
}
*/		//HugeInt::SIZE = 50;
		//static const int HugeInt::SIZE = 50;	

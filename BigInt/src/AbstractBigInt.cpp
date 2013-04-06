#include "Include.h"
using namespace std;

///////////////////////////////Artem/////////////////////////////////////////////////////////

AbstractBigInt::AbstractBigInt(string & init_str) // number = str.begin()
 {
	 if(init_str[0]== '0')
	 {
		 if( init_str[1] == 'x')	//hex
		 {
			 //pCoef = new uint16_t [nSize];
			 StringToBigInt(hex16, init_str);
		 }
		 else						//oct
		 {
			// nSize = (strlen(pNumber)%6)+1;
			// CharToBigInt(oct8, sNumber);
		 }
	 }
	 else 							//dec
	 {
		 //nSize = (strlen(pNumber)%5)+1;
		// CharToBigInt(dec10, sNumber);
	 }
 }

void AbstractBigInt::StringToBigInt(base CurBase, string & init_str)
{
	 uint16_t iTemp;
	 uint32_t str_size = init_str.size();
	 int32_t count = str_size-1; //counter on current symbol
	 if(CurBase == hex16)
	 {
		 while(init_str[count] > 1)
		 {
			 iTemp = 0;
		 	 for(int iFour=0, iBase=1; (iFour<4)&&(init_str[count] > 1); iFour++, count--)
		 	 {
			 	 if( (init_str[count]>='0')&&(init_str[count]<='9') )
			 	 {
				 	 iTemp+=( init_str[count] - '0')*iBase;
			 	 }
			 	 else if( (init_str[count]>='A')&&(init_str[count]<='F') )
			 	 {
				 	 iTemp+=(init_str[count] - 'A' + 0xA)*iBase;
			 	 }
			 	 else if( (init_str[count]>='a')&&(init_str[count]<='f') )
			 	 {
				 	 iTemp+=(init_str[count] - 'a' + 0xA)*iBase;
			 	 }
			 	 iBase*=CurBase;
		 	 }
		 	 coef.push_back(iTemp);
		 }
	 }


}

AbstractBigInt::AbstractBigInt (uint32_t number)
{
	uint16_t temp;
	if(number == 0) coef.push_back(0);
	while(number)
	{
		temp = number & 0xFFFF;
		coef.push_back(temp);
		number>>=16;
	}
}

AbstractBigInt::AbstractBigInt (const AbstractBigInt & TCopy)
{

	for(uint32_t i=0; i<TCopy.coef.size(); i++)
	{
		coef.push_back( TCopy.coef.at(i) );
	}
}

AbstractBigInt::AbstractBigInt ()
{
	coef.push_back(0);
}

AbstractBigInt& AbstractBigInt::operator= (AbstractBigInt second)
{
	coef = second.coef;
	return *this;
}

AbstractBigInt AbstractBigInt::operator!()
{
	if (*this == 0) *this = 1;
	else *this = 0;
	return *this;
}

AbstractBigInt AbstractBigInt::operator~ ()
{
	for(uint32_t i=0; i<coef.size(); i++ )
	{
		coef.at(i) = ~ coef.at(i);
	}
	return *this;

}

AbstractBigInt& AbstractBigInt::operator & (const AbstractBigInt & second)
{
	AbstractBigInt* result = new AbstractBigInt(); // shared_ptr
	uint32_t i_max=max(*this, second).coef.size();
	vector<uint16_t> vect_result(i_max, 0);
	for(uint32_t i = 0; i<i_max; i++)
	{
		if(i < this->coef.size() && i < second.coef.size())
		{
			vect_result.at(i) = this->coef.at(i) & second.coef.at(i);
		}
	}
	result->coef = vect_result;

	return *result;
}

AbstractBigInt AbstractBigInt::operator| (const AbstractBigInt & second)
{
	AbstractBigInt result = max(*this, second);
	uint32_t i_max=result.coef.size();

	for(uint32_t i = 0; i<i_max; i++)
	{
		if(i < this->coef.size() && i < second.coef.size())
		{
			result.coef.at(i) = this->coef.at(i) | second.coef.at(i);
		}
	}
	return result;
}

AbstractBigInt AbstractBigInt::operator^ (const AbstractBigInt & second)
{
	AbstractBigInt result = max(*this, second);
	uint32_t i_max=result.coef.size();

	for(uint32_t i = 0; i<i_max; i++)
	{
		if(i < this->coef.size() && i < second.coef.size())
		{
			result.coef.at(i) = this->coef.at(i) ^ second.coef.at(i);
		}
	}

	return result;
}

AbstractBigInt AbstractBigInt::operator&= (const AbstractBigInt & second)
{
	*this = *this & second;
	return *this;
}

AbstractBigInt AbstractBigInt::operator|= (const AbstractBigInt & second)
{
	*this = *this | second;
	return *this;
}

AbstractBigInt AbstractBigInt::operator^= (const AbstractBigInt & second)
{
	*this = *this ^ second;
	return *this;
}

AbstractBigInt AbstractBigInt::max(AbstractBigInt first, AbstractBigInt second)
{
	if (first > second) return first;
	else return second;
}

bool AbstractBigInt::operator&& (AbstractBigInt & second)
{
	if ( (*this == 0)||(second == 0) ) return false;
	else return true;
}

bool AbstractBigInt::operator|| (AbstractBigInt & second)
{
	if ( (*this == 1)||(second == 1) ) return true;
	else return false;
}

AbstractBigInt AbstractBigInt::AdditionalCode(AbstractBigInt &number)
{
	//number = ~number + 1;
	return number;
}

AbstractBigInt AbstractBigInt::operator- (const AbstractBigInt & second )
{
	for(uint32_t i = 0; i < max(*this, second).coef.size(); i++ )
	{
		this->coef.at(i)= this->coef.at(i) - second.coef.at(i);

	}
	return *this;
}

AbstractBigInt AbstractBigInt::operator+ (const AbstractBigInt &second )
{
	AbstractBigInt result = max(*this, second);
	uint16_t division = 0;
	uint32_t temp;
	for(uint32_t i=0; i<coef.size(); i++ )
	{
		temp = coef.at(i) + second.coef.at(i) + division;
		if ((temp>>15) == 1)
			{
				division = 1;
				temp = temp & 0xFFFF;
				result = temp;
			}
		else division = 0;
	}
	return result;
}




bool AbstractBigInt::operator== (const AbstractBigInt &abi )
	{
		uint16_t i;
		if (abi.coef.size()!=coef.size()) {return false;}
		else
		{
			for(i=0;i<abi.coef.size();i++)
			{
				if(abi.coef[i]!=coef[i]) {return false;}
			}
		}
		return true;
	}

bool AbstractBigInt::operator!= (const AbstractBigInt &abi )
{
	uint16_t i;
	if (abi.coef.size()!=coef.size()) {return true;}
	else
	{
		for(i=0;i<abi.coef.size();i++)
		{
			if(abi.coef[i]!=coef[i]) {return true;}
		}
	}
	return false;
}

bool AbstractBigInt::operator> (const AbstractBigInt &abi )
	{
		int i;
		if(abi.coef.size() > coef.size()) {return true;}
		else if(abi.coef.size() < coef.size()) {return false;}
		else{
			for(i=abi.coef.size()-1;i==0;i--)
				{
					if(abi.coef[i]>coef[i]) {return true;}
					else if (abi.coef[i]<coef[i]) {return false;}
				}
			}
		return false;
		}


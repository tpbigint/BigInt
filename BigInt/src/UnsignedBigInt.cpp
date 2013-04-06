#include "Include.h"
#include <iostream>
using namespace std;


ostream &operator << (ostream& ostr, UnsignedBigInt& a_bigint)
  {
	  int32_t curr_coef = a_bigint.coef.size() -1;
	  while(curr_coef >= 0)
	  {
		  ostr.width(4); // print by 4 symbols per one time
		  ostr.fill('0');
		  ostr << hex << a_bigint.coef.at(curr_coef);
		  curr_coef--;
	  }
	  ostr << endl;
	  return ostr;
  }


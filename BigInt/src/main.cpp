/*
 * main.cpp
 *
 *  Created on: 15.03.2013
 *      Author: artem
 */
#include "Include.h"
int main()
{
	bool bb=false;
	UnsignedBigInt qq(0xffff);
	UnsignedBigInt ww(0xffff);
	string sA("0x11FFF00FF");
	string s_null("0x0000");
	UnsignedBigInt a(sA);
	cout << a << "\n";
	UnsignedBigInt b((uint32_t)255);

	cout << b << "\n";
	UnsignedBigInt c;
	cout << c << "\n";

	bb = qq!=ww;
	if(bb){cout<<'1';}else cout<<'0' << "\n";

	// TODO: test it
	cout << "Testing operator !:\n";
	UnsignedBigInt null((uint32_t)0);
	cout <<  null;
	null = !null;
	cout << null;

	// TODO: test it
	cout << "Testing operator ~:\n";
	UnsignedBigInt not_test((uint32_t)0);
	cout <<  not_test;
	not_test = ~not_test;
	cout << not_test;

	cout << "Testing operator &:\n";
	UnsignedBigInt and_test1((uint32_t)0x0CAB0010);
	UnsignedBigInt and_test2((uint32_t)0x00FF);
	UnsignedBigInt result;
	cout << and_test1;

	//cout << and_test1 & and_test2;
	//and_test1 = (and_test1 & and_test2);
	//cout <<  and_test1;

//	cout << "Testing operator +:\n";
//	UnsignedBigInt and_test_1((uint32_t)0x1234590f);
//	UnsignedBigInt and_test_2((uint32_t)0xabcdff);
//	UnsignedBigInt result_;
//	result_ = and_test_1 +and_test_2;
//	cout << result_;




	return 0;
}



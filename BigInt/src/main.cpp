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

	cout << "Testing operator +:\n";
	UnsignedBigInt plus_test1((uint32_t)0x1234590f);
	UnsignedBigInt plus_test2((uint32_t)0x00abcdff);
	UnsignedBigInt plus_result;
	plus_test1+=plus_test2;
	cout<<"1234 590f + 00ab cdff = "<<(plus_test1);
	plus_test2=0xffffffff;
	plus_result=plus_test1+plus_test2;
	cout<<"1234 590f + 00ab cdff + ffff ffff = "<<plus_result<<"\n";
	//cout<<(++plus_test2);          FIXME:из-за бага невозможно проверить разницу
	//cout<<"\n";                    работы инкремента и декремента
	//cout<<(plus_test2++)<<"\n";
	//cout<<plus_test2<<"\n";


	cout << "Testing operator *:\n";
	string str1("0x27a7b31234590f");
	string str2("0x12ab74df35c1");
	UnsignedBigInt proizv_test1(str1);
	UnsignedBigInt proizv_test2(str2);
	UnsignedBigInt result1;
	UnsignedBigInt res;
	// res=proizv_test1*proizv_test2; FIXME: change error connecting with operator =
	cout<<"27 a7b3 1234 590f * 12ab 74df 35c1 = "<<res<<"\n";
	//proizv_test1*=proizv_test2;    по какой-то причине выдаёт ошибку
	//cout<<proizv_test1;

	/*cout << "Testing operator -:\n";
		UnsignedBigInt minus_test1((uint32_t)0x1234590f);
		UnsignedBigInt minus_test2((uint32_t)0x00abcdff);
		UnsignedBigInt result2;
		result1=minus_test1-minus_test2;
		cout<<"1234590f * 00abcdff = "<<(minus_test1)<<"\n";*/

	cout << "Testing operator < :\n";
	UnsignedBigInt test5(0xffff);
	UnsignedBigInt test6(0xffff);
	if(test5 >= test6)
	{
		cout<<'1';} else {cout<<'0' << "\n";
	}



	return 0;
}



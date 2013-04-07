#include "Include.h"
using namespace std;

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

bool AbstractBigInt::operator> (const AbstractBigInt &right )
	{
		int32_t i,t_r,t_l;

		t_l=coef.size();
		t_r=right.coef.size();
		cout<<t_l;
		cout << " T_L:\n";
		cout<<t_r;
		cout << " T_R:\n";


		if(right.coef.size() > coef.size())
		{
			for (i=right.coef.size()-1;i>coef.size();i--)
			{
				if(right.coef[i]>0x0){return false;}
			}
			for(i=coef.size()-1;i>=0;i--)
			{
				if(right.coef[i]>coef[i]){return false;}
				else if(right.coef[i]<coef[i]){return true;}
			}
		}
		else if(right.coef.size() < coef.size())
		{
			for(i=coef.size()-1;i>=right.coef.size();i--)
			{
				if(coef[i]>0x0){return true;}
			}
			for(i=right.coef.size()-1;i>=0;i--)
			{
				if(right.coef[i]>coef[i]){return false;}
				else if(right.coef[i]<coef[i]){return true;}
			}
		}
		else
		{
			for(i=coef.size()-1;i>=0;i--)
			{
				//cout << " !";
				if(right.coef[i]>coef[i]){return false;}
				if(right.coef[i]<coef[i]){return true ;}

			}
		}

		return false;
		}

bool AbstractBigInt::operator>= (const AbstractBigInt &right )
	{
		int32_t i,t_r,t_l;

		t_l=coef.size();
		t_r=right.coef.size();
		cout<<t_l;
		cout << " T_L:\n";
		cout<<t_r;
		cout << " T_R:\n";


		if(right.coef.size() > coef.size())
		{
			for (i=right.coef.size()-1;i>coef.size();i--)
			{
				if(right.coef[i]>0x0){return false;}
			}
			for(i=coef.size()-1;i>=0;i--)
			{
				if(right.coef[i]>coef[i]){return false;}
				else if(right.coef[i]<coef[i]){return true;}
			}
		}
		else if(right.coef.size() < coef.size())
		{
			for(i=coef.size()-1;i>=right.coef.size();i--)
			{
				if(coef[i]>0x0){return true;}
			}
			for(i=right.coef.size()-1;i>=0;i--)
			{
				if(right.coef[i]>coef[i]){return false;}
				else if(right.coef[i]<coef[i]){return true;}
			}
		}
		else
		{
			for(i=coef.size()-1;i>=0;i--)
			{
				//cout << " !";
				if(right.coef[i]>coef[i]){return false;}
				if(right.coef[i]<coef[i]){return true ;}

			}
		}

		return true;
		}

bool AbstractBigInt::operator< (const AbstractBigInt &right )
	{
		int32_t i,t_r,t_l;

		t_l=coef.size();
		t_r=right.coef.size();
		cout<<t_l;
		cout << " T_L:\n";
		cout<<t_r;
		cout << " T_R:\n";


		if(right.coef.size() > coef.size())
		{
			for (i=right.coef.size()-1;i>coef.size();i--)
			{
				if(right.coef[i]>0x0){return true;}
			}
			for(i=coef.size()-1;i>=0;i--)
			{
				if(right.coef[i]>coef[i]){return true;}
				else if(right.coef[i]<coef[i]){return false;}
			}
		}
		else if(right.coef.size() < coef.size())
		{
			for(i=coef.size()-1;i>=right.coef.size();i--)
			{
				if(coef[i]>0x0){return false;}
			}
			for(i=right.coef.size()-1;i>=0;i--)
			{
				if(right.coef[i]>coef[i]){return true;}
				else if(right.coef[i]<coef[i]){return false;}
			}
		}
		else
		{
			for(i=coef.size()-1;i>=0;i--)
			{
				//cout << " !";
				if(right.coef[i]>coef[i]){return false;}
				if(right.coef[i]<coef[i]){return true ;}

			}
		}

		return false;
		}


AbstractBigInt AbstractBigInt::operator+ (const AbstractBigInt &right )  //оператор реализован без битовых операций
{
	int incr=0;//флаг перехода разряда false-переход не нужен
	uint32_t buf;   //буфер в котором содержится промежуточны результат
	int size;       //минимальный из размеров вектора
	int i,j;
	AbstractBigInt temp;
	if (coef.size() > right.coef.size()) size=right.coef.size(); // поиск минимального размера
	else size=coef.size();
	for (i=0;i<size;i++)                                 //цикл поэлементного сложения
		{
			buf=coef[i]+right.coef[i]+incr;
			if(i>0) temp.coef.push_back( (buf & 0xFFFF) );
			else temp.coef[i]=buf & 0xFFFF;
			incr=(buf>>16);
		}
		if (incr>0)
		{
			for(j=i;coef[j]==0xFFFF;j++) temp.coef[j]=0x0000;      //поиск элемента не равного максимально возможному и запись нулей если элемент максимален
			if(j==coef.size()) temp.coef.push_back(0x0001);              //проверка на выход за пределы изначального вектора и запись инкремента
			else temp.coef[j]+=0x0001;                         //иначе инкрементация
		}

		return temp;

}

AbstractBigInt AbstractBigInt::operator++ ()
{
	*(this)=(*this)+1;
	return *this;
}

AbstractBigInt AbstractBigInt::operator++ (int)
{
	AbstractBigInt temp=*this;
	(*this)=(*this)+1;
	return temp;
}

AbstractBigInt AbstractBigInt::operator+= (const AbstractBigInt &right )
{
	(*this)=(*this)+right;
	return *this;
}

AbstractBigInt AbstractBigInt::operator* (const AbstractBigInt &right )
{
	int rightsize=right.coef.size();
	int size=coef.size();
	AbstractBigInt temp;
	int incr=0;
	uint64_t buf;
	int i,j,k=0;
	for(i=0;i<size;i++)                        //цикл прохода посимвольно по второму множителю
	{
		for (j=0;j<rightsize;j++)                        //цикл похода посимвольно по первому множителю
		{
			buf=temp.coef[i+j]+coef[j]*right.coef[i]+incr;     //результат умножения элементов массива+ инкремент+предыдущее значение ячейки
			if( (i+j)>k )                                     //запись и перезапись элемента вектора
				{                                             //а также проверка на наличие элемента в момент записи
					temp.coef.push_back(buf & 0xFFFF);
					k++;                                       //увеличение счётчика элементов вектора
				}
			else temp.coef[i+j]=buf & 0xFFFF;
			incr=buf>>16;                                 //вычисление инкремента от умножения

		}
	if(incr>0)                                              //проверка на переход в новый разряд
		{
		temp.coef.push_back(incr);
		incr=0;
		k++;
		}
	}
	return temp;
}

AbstractBigInt AbstractBigInt::operator*= (const AbstractBigInt &right )
{
	(*this)=(*this)*right;
	return *this;
}


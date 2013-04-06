#include "Include.h"
#include <stdint.h>
#include <vector>
#include <string>

using namespace std;
enum base { oct8 = 8, dec10 = 10, hex16 = 16 };

/// class AbstractBigInt - 
class AbstractBigInt {
  // Attributes
protected:
	vector<uint16_t> coef;
  // Operations

public:
  AbstractBigInt (); 											//ready
  AbstractBigInt (uint32_t);									//ready
  AbstractBigInt (string &);									//ready
  AbstractBigInt (const AbstractBigInt & );						//ready
  virtual ~AbstractBigInt () {};								//ready
  AbstractBigInt& operator= (AbstractBigInt );					//ready
  AbstractBigInt operator+ (const AbstractBigInt & );
  AbstractBigInt operator- (const AbstractBigInt & );
 // virtual AbstractBigInt operator* (const AbstractBigInt & ); //Разкомментируй когда будешь реализовывать
 // virtual AbstractBigInt operator/ (const AbstractBigInt & ); //Компилятор ругается на виртуальные функции без реализации
  AbstractBigInt operator% (const AbstractBigInt & );
  AbstractBigInt operator++ ( );
  AbstractBigInt operator++ (int );
  AbstractBigInt operator-- ();
  AbstractBigInt operator-- (int );
  bool operator== (const AbstractBigInt & );					//ready
  bool operator!= (const AbstractBigInt & );					//ready
  bool operator> (const AbstractBigInt & );						//ready
 // virtual bool operator< (const AbstractBigInt & );
 // virtual bool operator>= (const AbstractBigInt & );
 // virtual bool operator<= (const AbstractBigInt & );
  bool operator&& (AbstractBigInt & );							//ready
  bool operator|| (AbstractBigInt & );							//ready
  AbstractBigInt operator! ();									//ready
  AbstractBigInt operator~ ();									//ready
  AbstractBigInt& operator &(const AbstractBigInt & );			//ready
  AbstractBigInt operator| (const AbstractBigInt & );			//ready
  AbstractBigInt operator^ (const AbstractBigInt & );			//ready
  AbstractBigInt operator<< (const AbstractBigInt & );
  AbstractBigInt operator>> (const AbstractBigInt & );
  AbstractBigInt operator+= (const AbstractBigInt & );
  AbstractBigInt operator-= (const AbstractBigInt & );
  //virtual AbstractBigInt operator*= (const AbstractBigInt & );
  //virtual AbstractBigInt operator/= (const AbstractBigInt & );
  AbstractBigInt operator%= (const AbstractBigInt & );
  AbstractBigInt operator&= (const AbstractBigInt & );			//ready
  AbstractBigInt operator|= (const AbstractBigInt & );			//ready
  AbstractBigInt operator^= (const AbstractBigInt & );			//ready
  AbstractBigInt operator<<= (const AbstractBigInt & );
  AbstractBigInt operator>>= (const AbstractBigInt & );
  //operator uint32_t() const;

  void StringToBigInt(base, string &);
  AbstractBigInt max(AbstractBigInt, AbstractBigInt);
  AbstractBigInt AdditionalCode(AbstractBigInt &);					//almost ready
};



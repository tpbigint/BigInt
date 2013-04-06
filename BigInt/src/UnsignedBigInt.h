#include "Include.h"


/// class UnsignedBigInt - 
class UnsignedBigInt : public AbstractBigInt {
  // Operations
public:
  UnsignedBigInt():AbstractBigInt(){ };
  UnsignedBigInt(string & init_str ): AbstractBigInt(init_str) { };
  UnsignedBigInt(uint32_t number):AbstractBigInt(number) { };
  UnsignedBigInt (const AbstractBigInt & TCopy):AbstractBigInt (TCopy) { };
  UnsignedBigInt (const UnsignedBigInt & TUCopy):AbstractBigInt (TUCopy) { };
  ~UnsignedBigInt(){ };

  AbstractBigInt operator* (const AbstractBigInt & );
  AbstractBigInt operator/ (const AbstractBigInt & );
  bool operator> (const AbstractBigInt & );
  bool operator< (const AbstractBigInt & );
  bool operator>= (const AbstractBigInt & );
  bool operator<= (const AbstractBigInt & );
  AbstractBigInt& operator*= (AbstractBigInt );
  AbstractBigInt& operator/= (AbstractBigInt );

  friend istream& operator>> (istream & , UnsignedBigInt & );
  friend ostream& operator<< (ostream & , UnsignedBigInt & );
};


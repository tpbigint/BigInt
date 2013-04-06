#include "Include.h"
#include <iostream>
using namespace std;

/// class BigInt - 
class BigInt : public AbstractBigInt {
  // Operations
public:
  BigInt ( int);
  AbstractBigInt operator- ();
  AbstractBigInt operator* (const AbstractBigInt  & );
  AbstractBigInt operator/ (const AbstractBigInt & );
  bool operator> (const AbstractBigInt  & );
  bool operator< (const AbstractBigInt  & );
  bool operator>= (const AbstractBigInt  & );
  bool operator<= (const AbstractBigInt  & );
  AbstractBigInt operator*= (const AbstractBigInt  & );
  AbstractBigInt operator/= (const AbstractBigInt  & );
  friend istream & operator >> (istream & , AbstractBigInt & );
  friend ostream & operator << (ostream & , AbstractBigInt & );
};


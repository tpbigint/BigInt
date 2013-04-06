
/// class FastBigInt - 
class FastBigInt : public BigInt {
  // Operations
public:
  BigInt pow (BigInt n, BigInt m);
  BigInt pow (BigInt n, unsigned int m);
  AbstractBigInt operator* (const AbstractBigInt & );
  AbstractBigInt operator/ (const AbstractBigInt & );
};


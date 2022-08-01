//destructor
BigInt::~BigInt() { delete[] bigIntDigits; }

// copy constructor
BigInt::BigInt(const BigInt& a) : bigIntDigits{new int[10]}
{
	copy(a.bigIntDigits, a.bigIntDigits+10, bigIntDigits);
}

// move constructor
BigInt::BigInt(BigInt&& a) : bigIntDigits{a.bigIntDigits}
{
	a.bigIntDigits = nullptr;
}

// copy assignment
BigInt& BigInt::operator=(const BigInt& a) 
{
	if (&a == this) { return *this; }

	int* big = new int[10];
	copy(a.bigIntDigits, a.bigIntDigits+10, big);
	delete[] bigIntDigits; // delete pointer to original's resources
	bigIntDigits = big; // ...and replace with pointer to new resources
	return *this;
}

// move assignment
BigInt& BigInt::operator=(BigInt&& a)
{
	// delete resources currently held by this object
	delete[] bigIntDigits;
	// take ownership of resources belonging to ‘a’
	bigIntDigits = a.bigIntDigits;

	// set a’s size and pointer to null
	a.bigIntDigits = nullptr;
	return *this;
}
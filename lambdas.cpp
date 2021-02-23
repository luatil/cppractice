
int plus1(int x)
{
	return x+1;
}

// Function Overloading
double plus1(double x)
{
	return x+1;
}

// Function templates  
template <typename T>
T plus1(T x)
{
	return x+1;
}

// Class member functions
class Plus {
	int value;
public:
	Plus(int v);

	int plusme(int x) const {
		return x + value;
	}
};

// Operator overloading
class Plus {
	int value;
public:
	Plus(int v);

	int operator() (int x) const {
		return x + value;
	}
	// auto plus = Plus(1);
	// auto x = plus(42);
};

// Lambdas reduce boilerplate
auto plus = [value=1](int x) { return x + value; };
// assert(plus(42) == 43);


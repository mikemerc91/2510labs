// lab 9 exercise 1
#include "../std_lib_facilities.h"

class TrigFunction 
{
public:
    virtual double evaluate(double d) = 0;
};

class SinFunction : public TrigFunction 
{
public:
    double evaluate(double d) override { return sin(d); }
};

class CosFunction : public TrigFunction 
{
public:    
    double evaluate(double d) override { return cos(d); }
};

class TanFunction : public TrigFunction 
{
public:
    double evaluate(double d) override { return tan(d); }
};

class ArctanFunction : public TrigFunction 
{
public:
    double evaluate(double d) override { return atan(d); }
};

class ArcsinFunction : public TrigFunction 
{
public:
    double evaluate(double d) override { return asin(d); }
};

class TrigFunction2 : public TrigFunction
{
private:
    function<double(double)> lambda;
public:
    TrigFunction2(function<double(double)> f) : lambda{f} {}

    double evaluate(double d) override { return lambda(d); }
};

void trigger(TrigFunction&, double);

int main()
{
    SinFunction sinf;
    CosFunction cosf;
    TanFunction tanf;
    ArcsinFunction asinf;
    ArctanFunction atanf;
    trigger(sinf, 1.0);
    trigger(cosf, 1.0);
    trigger(tanf, 1.0);
    trigger(asinf, 1.0);
    trigger(atanf, 1.0);

    TrigFunction2 sinLambda{[](double d){ return sin(d); }};
    TrigFunction2 cosLambda{[](double d){ return cos(d); }};
    TrigFunction2 tanLambda{[](double d){ return tan(d); }};
    TrigFunction2 asinLambda{[](double d){ return asin(d); }};
    TrigFunction2 atanLambda{[](double d){ return atan(d); }};
    trigger(sinLambda, 1.0);
    trigger(cosLambda, 1.0);
    trigger(tanLambda, 1.0);
    trigger(asinLambda, 1.0);
    trigger(atanLambda, 1.0);
}

void trigger(TrigFunction& f, double value)
{
    cout << f.evaluate(value) << endl;
}

// Lambda approach is easier when adding new functions.
// Class hierarchy approach allows for more specific functionality for each class.
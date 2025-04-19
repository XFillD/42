#ifndef BASE_HPP
#define BASE_HPP

class Base 
{
public:
    virtual ~Base();
};

// Derived classes
class A : public Base {};
class B : public Base {};
class C : public Base {};

// Required functions
Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif // BASE_HPP
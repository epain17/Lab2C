#pragma once
#include <iostream>
#include "GCD.h"

template<typename Tint>
class Rational
{
public:
	Tint nom, denom;
	friend std::ostream& operator<< (std::otream& cout, Rational<Tint> R)
	{
		cout << R.P << '/' << R.Q;
		return cout;
	}

	Rational() : nom(0), denom(1) {};
	Rational(Tint P):P(P), Q(1){}
	Rational(Tint P, Tint Q) :P(P), Q(Q)
	{
		Reduce(P, Q);
	}
	Rational operator+(const Rational rhs) const 
	{
		Rational result = r;
		result += rhs;
		return result;


	}

	Rational operator+=(const Rational rhs) const
	{
		nom = rhs.nom * denom + rhs.denom * nom;
		denom = rhs.denom*denom;
		return *this;
	}

	Rational operator - (const Rational &r, const Rational &s)
	{
		Rational result = r;
		result -= s;
		return result;
	}
};
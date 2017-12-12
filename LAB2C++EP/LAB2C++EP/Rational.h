#pragma once
#include <iostream>
#include "GCD.h"

template<typename Tint>
class Rational
{
public:
	Tint P, Q; //nom, denom
	friend std::ostream& operator<< (std::otream& cout, Rational<Tint> R)
	{
		cout << R.P << '/' << R.Q;
		return cout;
	}

	Rational() : P(0), Q(1) {};
	Rational(Tint P):P(P), Q(1){}
	Rational(Tint P, Tint Q) :P(P), Q(Q)
	{
		Reduce(P, Q);
	}

	template <typename T>
	Rational(Rational<T>& r){}

	Rational void simplify()
	{
		if (Q < 0)
		{
			P *= -1;
			Q *= -1;
		}

		int denom = GCD(P, denom);
		P /= denom;
		denom /= denom;
	}

	template <typename T>
	bool operator== (const Rational<T>& lhs, const Rational<T>& rhs)
	{
		return lhs.P == rhs.P && lhs.Q == rhs.Q;
	}

	template <typename T>
	bool operator!= (const Rational<T>& lhs, const Rational<T>& rhs)
	{
		return !(lhs.P == rhs.P && lhs.Q == rhs.Q);
	}

	template <typename T>
	Rational operator =(const Rational<T>& lhs, const Rational<T>& rhs)
	{
		lhs.P = rhs.P;
		lhs.Q = rhs.Q;
		return dynamic_cast<Rational> (lhs);
	}

	template <typename T>
	Rational operator+= (const Rational<T>& rhs) const
	{
		P = rhs.P * Q + rhs.Q * P;
		Q = rhs.Q*Q;

		this->simplify();
		return *this;
	}

	template <typename T>
	Rational operator+ (const Rational rhs) const 
	{
		return Rational{ *this } += rat;
	}

	template <typename T>
	Rational operator- (const Rational rhs) const
	{
		return Rational{ *this } -= rat;
	}

	template <typename T>
	Rational operator ++()
	{
		return (*this) += 1;
	}

	template <typename T>
	Rational operator++(int)
	{
		Rational temp{ *this };
		P += Q;
		return temp;
	}

	


};
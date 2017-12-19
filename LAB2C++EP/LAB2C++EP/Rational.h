#pragma once
#include <iostream>
#include "GCD.h"

template<typename Tint>
class Rational
{
public:
	Tint P, Q; //nom, denom
	friend std::ostream & operator<< (std::ostream & cout, Rational<Tint> R)
	{
		cout << R.P << '/' << R.Q;
		return cout;
	}

	
	friend std::istream & operator>> (std::istream & cin, Rational<Tint>& R)
	{
		cin >> R.P;
		char c;
		cin >> c;
		cin >> R.Q;
		return cin;
	}


	Rational() : P(0), Q(1) {};
	Rational(Tint P):P(P), Q(1){}
	Rational(Tint P, Tint Q) :P(P), Q(Q)
	{
		Reduce(this->P, this->Q);
	}

	Rational(const Rational& r)
	{
		P = r.P;
		Q = r.Q;
	}

	operator int()
	{
		return P / Q;
	}

	template <typename T>
	Rational(Rational<T>& r)
	{
		P = r.P;
		Q = r.Q;
	}

	/*template <typename Other>
	std::ostream& operator << (std::ostream& s)const
	{
	 return (s << P << '/' << Q);
	}*/

	/*std::ostream& Rational::print(std::ostream &s)const
	{
		return (s << P << '/' << Q);
	}*/

	template <typename Other>
	friend bool operator== (const Rational<Tint>& lhs, const Rational<Other>& rhs) 
	{
		return lhs.P * rhs.Q == lhs.Q * rhs.P;
	}


	Rational operator=  (const Rational<Tint>& rhs)
	{
		P = rhs.P;
		Q = rhs.Q;
		return *this;
	}

	template<typename Other>
	Rational operator+= (const Rational<Other>& rhs)
	{
		P = rhs.P * Q + rhs.Q * P;
		Q = rhs.Q*Q;
		Reduce(P, Q);

		return *this;
	}

	template<typename Other>
	Rational operator+= (const Other& rhs)
	{
		P = rhs * Q + P;
		
		Reduce(P, Q);

		return *this;
	}

	Rational operator-= (const Rational<Tint>& rhs)
	{
		P = P * rhs.Q + Q rhs.P;
		Q *= rhs.Q;
		return *this;
	}

	template <typename Other>
	Rational operator+ (const Other& rhs) 
	{
		Rational temp(*this);
		return temp += rhs;
		
	}

	template <typename Other>
	Rational operator+ (const Rational<Other>& rhs)
	{
		Rational temp(*this);
		return temp += rhs;
	}
	

	Rational operator- (const Rational<Tint> rhs) 
	{
		return Rational{ *this } -= rat;
	}

	Rational operator- ()
	{
		this->P = (0 - P);
		return *this;
	}


	Rational operator ++()
	{
		return (*this) += 1;
	}

	Rational operator++(int)
	{
		Rational temp(*this );
		++*this;
		return temp;
	}

	


};
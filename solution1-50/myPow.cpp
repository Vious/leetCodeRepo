#include <iostream>
#include <algorithm>


class Solution1 {
public:
	double myPow(double x, int n) {
		if (n == 0) {
			return 1.0;
		}
		if (x == 0.0) {
			return 0.0;
		}
		if (n == 1) {
			return x;
		}
		double result = 1.0;
		int n1 = abs(n);
		for (int i = 0; i <= 31; n1 >>= 1, i++, x *= x)
		{
			if (n1 & 1) {
				result *= x;
			}
		}
		return n > 0 ? result : 1.0 / result;
	}
};


class Solution0 {
public:
	double myPow(double x, int n) 
	{
		double result = 1.0;
		for (unsigned i = 0, absn = abs(n); i <= 31; ++i, absn >>= 1, x *= x) 
		{
			if (absn & 1)
			{
				result *= x;
			}
		}

		return n < 0 ? 1 / result : result;
	}
};


class Solution2 {
public:
	double myPow(double x, int n) {
		if (n == 0) {
			return 1.0;
		}
		if (x == 0.0) {
			return 0.0;
		}
		if (n == 1) {
			return x;
		}
		double result = 1.0;
		int n1 = abs(n);
		for (int i = 0; i < n1; i++) {
			result *= x;
		}
		return n > 0 ? result : 1.0 / result;
	}
};


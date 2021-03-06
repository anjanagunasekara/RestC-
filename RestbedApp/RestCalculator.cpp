#include "stdafx.h"
#include "RestCalculator.h"
#include <string>

using namespace std;

double RestCalculator::calc(double val1, double val2, CalcOperator calOperator)
{ 
	switch (calOperator)
	{
		case ADD: 
			return add(val1, val2);
		case MINUS: 
			return substract(val1, val2);
		case DIVIDE: 
			return divide(val1, val2);
		case MULTIPLICATION: 
			return mult(val1, val2);
		default: 
			return 0.0;
	}
}

double RestCalculator::add(double val1, double val2)
{
	return val1 + val2;
}

double RestCalculator::substract(double val1, double val2)
{
	return val1 - val2;
}

double RestCalculator::divide(double val1, double val2)
{
	return val2 == 0.0 ? 0.0 : val1/val2;
}

double RestCalculator::mult(double val1, double val2)
{
	return val1 * val2;
}
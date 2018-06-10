#pragma once

enum CalcOperator {
	ADD = 0,
	MINUS = 1,
	DIVIDE = 2,
	MULTIPLICATION = 3
};

class RestCalculator
{
public:
	RestCalculator() {};
	~RestCalculator() {};

	double calc(double val1, double val2, CalcOperator calcOperator);
	double add(double val1, double val2);
	double substract(double val1, double val2);
	double divide(double val1, double val2);
	double mult(double val1, double val2);

};
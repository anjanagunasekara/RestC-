#include "stdafx.h"
#include "RestCalculator.h"
#include <thread>
#include <memory>
#include <chrono>
#include <cstdlib>
#include <restbed>
#include <string>
#include <iostream>

using namespace std;
using namespace restbed;


map<string, CalcOperator> operatorMap = {
	{ "add" , ADD },
	{ "minus" , MINUS },
	{ "divide" , DIVIDE },
	{ "mult" , MULTIPLICATION }
};

void post_method_handler(const shared_ptr< Session > session)
{
	RestCalculator* restCalculator = new RestCalculator();
	double val1   = 0.0;
	double val2   = 0.0;
	double answer = 0.0;

	const auto request = session->get_request();
	int content_length = request->get_header("Content-Length", 0);
	string calcOperator = request->get_path_parameter("operator");

	for (const auto query_parameter : request->get_query_parameters())
	{
		double val = 0.0;
		try
		{
			val = stod(query_parameter.second);
		}
		catch (int e)
		{
			cout << "invalid value argument";
			session->close(OK, "invalid argument value", { { "Content-Length", "20" } });
			return;
		}

		if (query_parameter.first == "val1")
		{
			val1 = val;
		} 
		else if (query_parameter.first == "val2")
		{
			val2 = val;
		}
	}

	cout << "Value 1 : " << val1 << ", Value 2 : " << val2 << " - " << calcOperator << "; ";
	answer = restCalculator->calc(val1, val2, operatorMap[calcOperator]);
	cout << "Answer : " << answer << endl;
	
	delete restCalculator;
	session->close(OK, to_string(answer), { { "Content-Length", to_string(to_string(answer).size()) } });
}


void service_ready_handler(Service&)
{
	fprintf(stderr, "Hey! The service is up and running.\n");
}

int main(const int, const char**)
{
	auto resource = make_shared< Resource >();
	resource->set_path("/resource/{operator: .*}");
	resource->set_method_handler("POST", post_method_handler);

	auto settings = make_shared< Settings >();
	settings->set_port(1984);

	auto service = make_shared< Service >();
	service->publish(resource);
	service->set_ready_handler(service_ready_handler);
	service->start(settings);

	return EXIT_SUCCESS;
}
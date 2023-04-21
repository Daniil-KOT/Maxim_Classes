#include <iostream>
#include <string>
//#include "AccessControl.h"

/*
void PrintResponse(const ResposeData& response) {
	std::cout << "result: " << response.Success << "\nresponse: " <<
		response.Response << "\n";
}
*/

void foo(int x)
{
	x = 10;
}

int main()
{
	/*
	AccessControl ac;
	int user1 = 1;
	int user2 = 2;
	int user3 = 3;

	ResposeData response;

	std::cout << "Test: register\n";
	response = ac.AssignRole(1, ROLE::User);
	PrintResponse(response);
	response = ac.AssignRole(2, ROLE::User);
	PrintResponse(response);
	response = ac.AssignRole(3, ROLE::User);
	PrintResponse(response);

	std::cout << "Test: change role\n";
	response = ac.AssignRole(1, ROLE::Admin);
	PrintResponse(response);

	std::cout << "Test: assign same role\n";
	response = ac.AssignRole(1, ROLE::Admin);
	PrintResponse(response);
	*/
	int x = 1;
	std::cout << x << "\n";
	foo(x);
	std::cout << x << "\n";
}

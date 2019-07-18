#include"Transaction.h"



//set transaction time to system time now
std::string Transaction::return_current_time_and_date(){
	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(std::localtime(&in_time_t), "%d/%m/%Y %X");
	return ss.str();
}
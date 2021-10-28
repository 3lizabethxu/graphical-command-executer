/**
*** Author:Elizabeth Xu
***
*** Description: Command.h is the header file for Command.cpp. 
***
*/

// include guards
#ifndef COMMAND_H
#define COMMAND_H

//system and standard libraries
#include <boost/process.hpp> 
#include <string>
#include <iostream>

 class Command
{

//access specifiers
private:
	std::string cmdText, result;
	int returnCode;
        boost::process::ipstream pipe_stream;


public:
  
        Command(std::string strInput);
	~Command();
	
	void execute(); 
	
	//getter methods 
	int getReturnCode();
	std::string getCmdText();
	std::string getResult();

	//setter method (no need for setters)

 };

#endif

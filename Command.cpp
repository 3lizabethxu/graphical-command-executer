/**
*** Author: Elizabeth Xu
***
*** Description: Command.cpp implements the Command class objects which contains the attributes,getters and setters needed to handle what the user entered.
***              CommandGUI.cpp uses Command.cpp to handle commands inputed by the user.
***
*/

#include "Command.h"

using namespace std;

//Constructor
Command::Command(string strInput)
	{
		cmdText = strInput;
		result="";
		returnCode=0;
	}
 
/*
** Function name: execute()
** Description: Called by CommandGUI to execute the userInput in shell. This stores the shell ouput as an attribute of the command. 
**              The try/catch is used to catch error code for when the user inputes a command that doesn't exist and displays it.
** Parameters: none
** Returns: none
*/
void Command::execute(){
	try{

		boost::process::child c(cmdText, boost::process::std_out > pipe_stream);
		
		std::string line;
		while (pipe_stream && std::getline(pipe_stream, line) && !line.empty())
			{
				result = result.append(line).append("\n");	//store shell output lines into Command attribute
			}        	
			
		std::cerr << result << std::endl; //display result in terminal 
		c.wait();
		       
	}

	catch(boost::process::process_error &e){
		returnCode=-1;
		result=e.what();
	}

}
 
/*
** Function name: getReturnCode()
** Description: Gets the exit status of a the command.
** Parameters: none
** Returns: int returnCode
*/

int Command:: getReturnCode(){
	return returnCode;
}

/*
** Function name: getReturnCode()
** Description: Gets the command inputted by user.
** Parameters: none
** Returns: string cmdText 
*/
string Command::getCmdText(){
	return cmdText;
}

/*
** Function name: getResult()
** Description: Gets the output that was taken from shell.
** Parameters: none
** Returns: string result
*/
string Command::getResult(){
	return result;
}


//Destructor
Command::~Command() 
{

}



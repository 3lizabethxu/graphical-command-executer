/**
*** Author:Elizabeth Xu
***
*** Description: CommandGUI.cpp builds the user interface using Qt5 libraries and implments any user interaction with the "Execute" button or "History" selection.
***              It uses Command class objects for implmentation.
***
*/

#include "CommandGUI.h"

using namespace std;


//Constructor
CommandGUI::CommandGUI(QWidget *parent): QWidget(parent)
{
	//initializaing visual components and connecting listeners where needed
	cmdLabel = new QLabel(tr("Command:"));
	cmdLine = new QLineEdit;

	execute_btn = new QPushButton("Execute", this);
	connect(execute_btn, &QPushButton::released, this, &CommandGUI::executeButton);//NEW
	  	
	outputLabel = new  QLabel(tr("Output:"));
	outputText = new QTextEdit;

	statusLabel = new QLabel(tr("Exit status:")); 
	    
	histLabel = new QLabel(tr("History"));

	listWidget = new QListWidget(this);//NEW
	connect(listWidget, &QListWidget::itemClicked, this, &CommandGUI::renderHistory);//NEW

	//put components onto a grid layout
	mainLayout = new QGridLayout;

	mainLayout->addWidget(cmdLabel, 0, 0);
	mainLayout->addWidget(cmdLine, 0, 1);
	mainLayout->addWidget(execute_btn, 0, 2);
	mainLayout->addWidget(outputLabel, 1, 0, Qt::AlignTop);
	mainLayout->addWidget(outputText, 1, 1);
	mainLayout->addWidget(statusLabel, 3,0 );
	mainLayout->addWidget(histLabel, 5,0);
	mainLayout->addWidget(listWidget, 6,1);

	setLayout(mainLayout);
	setWindowTitle(tr("CommandGUI"));   

}


/*
** Function name: executeButton()
** Description: Called when the user clicks on the "Execute" button. 
**              It takes in user input, creates a command, displays the command on the interface and then stores the command attributes in 3 containers of historical data
**		(the three containers hold input,output,status, respectively)
** Parameters: none
** Returns: none
*/
void CommandGUI::executeButton()
{	
	//get user input
	userInput = cmdLine->text();
	
	//create a command object 
	strInput = userInput.toUtf8().constData();  
	cmd= new Command(strInput);outputText->setReadOnly(true);
	
	//run the command in shell
	cmd->execute();
	
	//display ouput on user interface
	qOutputText = QString::fromStdString(cmd->getResult()); 
	outputText->setText(qOutputText);
	outputText->setReadOnly(true);

	//display exit status on user interface
	qStatus = QString::number(cmd->getReturnCode()); 
	statusLabel->setText("Exit status: "+ qStatus);

	//add a corresponding widget to the list	
	newItem = new QListWidgetItem; 
	newItem->setText(userInput+"("+qStatus+")");
	listWidget->addItem(newItem);

	//store current command into 3 data containers for access at a later time
	historyInput.append(userInput);
	historyOutput.append(qOutputText);
        historyStatus.append(qStatus); 

}


/*
** Function name: renderHistory()
** Description: Called when the user clicks on the "History" list. 
**              It searches up the matching historical input,output and status values in the 3 containers of historical data 
**              and then sets up the user interface to display those values.
** Parameters: none
** Returns: none
*/
void CommandGUI::renderHistory()
{
	//identify which historical item was selected
	current_index= listWidget->currentRow();

	//set up display to show historical data 
	cmdLine->setText(historyInput.at(current_index));
	outputText->setText(historyOutput.at(current_index));
	statusLabel->setText("Exit status: "+historyStatus.at(current_index));

}






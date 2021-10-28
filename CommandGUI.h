/**
*** Author:Elizabeth Xu
***
*** Description: CommandGUI.h is the header file for CommandGUI.cpp. 
***
*/

// include guards
#ifndef COMMANDGUI_H 
#define COMMANDGUI_H

//system and standard libraries
#include <QTextEdit>
#include <QLineEdit>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QMessageBox>
#include <QTextStream>
#include <QListWidget>
#include <QVector>

#include <iostream> 

//headers
#include "Command.h" 

class CommandGUI: public QWidget
{
	Q_OBJECT

	//access specifiers
	public:
		CommandGUI(QWidget *parent = nullptr);

	private slots:                     
		void executeButton();
		void renderHistory(); 

	private:
		//interface components for user input 
		QLabel *cmdLabel ;		
		QLineEdit *cmdLine;
		QPushButton *execute_btn;
		
		//interface components for shell ouput
		QLabel *outputLabel;
		QTextEdit *outputText;

		//exit status display
		QLabel *statusLabel;
		
		//history display
		QLabel *histLabel;
		QListWidget *listWidget;

		//layout for the components above
		QGridLayout *mainLayout ;
		
		//3 containers to store user command attributes
		QVector<QString> historyInput;
		QVector<QString> historyOutput;
		QVector<QString> historyStatus;
		
		//historical recall components
		QString userInput;//variable to store user input from "Command" textbox
		std::string strInput;//variable to translate user input into acceptable parameter for Command class

		Command* cmd; // command object created once user presses "Execute"

		QString qOutputText; //variable to store shell output
		QString qStatus; //variable to translate status integer to a QString to feed into a QLabel 

		QListWidgetItem *newItem ; //new item to be added to historical commands display
		
		int current_index;//holds index of where the user-selected historical command is held in the 3 historical attribute containers

};

#endif 

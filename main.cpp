/**
*** Author:Elizabeth Xu
***
*** Description: main.cpp uses executes a CommandGUI. The CommandGUI simulates a command prompt.
***
*/

#include <QApplication>
#include "CommandGUI.h"

int main(int argc, char *argv[])
{
   
    QApplication app(argc, argv);

    CommandGUI commandGUI;
    commandGUI.show();

    return app.exec();
}

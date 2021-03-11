////////////////////////////////////////////////////////
// ECE 3574 - Exercise-11 -  Qt widgets
//
#include <QApplication>
#include "complex_widget.hpp"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	ComplexWidget complexWidget;
	complexWidget.show();

	return app.exec();
}

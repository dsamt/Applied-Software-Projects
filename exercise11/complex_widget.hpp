////////////////////////////////////////////////////////
// ECE 3574 - Exercise-11 -  Qt widgets
//
#ifndef COMPLEX_WIDGET_H
#define COMPLEX_WIDGET_H
#include <QtWidgets>

class ComplexWidget : public QWidget 
{
	Q_OBJECT

public:
	ComplexWidget();
	double getRealPart();
	double getImaginarypart();
	double getMagnitude();
	double getPhase();

public slots:
	void updatePush();

private:
	QLineEdit *real_partLineEdit;
	QLineEdit *imaginary_partLineEdit;
	QLabel* phaseLabel;
	QLabel* magnitudeLabel;
};






#endif

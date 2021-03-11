////////////////////////////////////////////////////////
// ECE 3574 - Exercise-11 -  Qt widgets
//
#include <QtWidgets>
#include <QDebug>
#include "complex_widget.hpp"
#include <complex>

ComplexWidget::ComplexWidget() {
	//inputs
	QLabel* realPart = new QLabel("Real Part: ");
	QLabel* imaginaryPart = new QLabel("Imaginary Part: ");
	real_partLineEdit = new QLineEdit;
	imaginary_partLineEdit = new QLineEdit;
	real_partLineEdit->setPlaceholderText("0.0");
	imaginary_partLineEdit->setPlaceholderText("0.0");
	real_partLineEdit->setFocus();
	imaginary_partLineEdit->setFocus();

	//phase and magnitude
	QLabel* _phaseLabel = new QLabel("Phase: ");
	QLabel* _magnitudeLabel = new QLabel("Magnitude: ");
	phaseLabel = new QLabel("0.0");
	magnitudeLabel = new QLabel("0.0");

	//update
	QPushButton* button = new QPushButton("Update");
	button->setToolTip("Click to update");

	//layout
	QGridLayout* layout = new QGridLayout;
	layout->addWidget(realPart,               0, 0);
	layout->addWidget(real_partLineEdit,      0, 1);

	layout->addWidget(imaginaryPart,          0, 2);
	layout->addWidget(imaginary_partLineEdit, 0, 3);
	
	layout->addWidget(_phaseLabel,            1, 0);
	layout->addWidget(phaseLabel,             1, 1);

	layout->addWidget(_magnitudeLabel,        1, 2);
	layout->addWidget(magnitudeLabel,         1, 3);

	layout->addWidget(button, 2, 3);

	QObject::connect(button, SIGNAL(clicked()), this, SLOT(updatePush()));

	setLayout(layout);
	setWindowTitle("Exercise 11");
}

double ComplexWidget::getRealPart() {

	bool ok(false);
	double real = real_partLineEdit->text().toDouble(&ok);

	if (ok) {
		return real;
	}
	return 1;
}

double ComplexWidget::getImaginarypart() {

	bool ok(false);
	double imag = imaginary_partLineEdit->text().toDouble(&ok);

	if (ok) {
		return imag;
	}

	return 1;
}

double ComplexWidget::getMagnitude() {
	std::complex<double> complex(getRealPart(), getImaginarypart());

	return std::abs(complex);
}

double ComplexWidget::getPhase() {
	std::complex<double> complex(getRealPart(), getImaginarypart());

	return std::arg(complex);
}

void ComplexWidget::updatePush() {
	double ph = getPhase();
	double mag = getMagnitude();

	QString ph_str = QString::number(ph);
	QString mag_str = QString::number(mag);

	phaseLabel->setText(ph_str);
	magnitudeLabel->setText(mag_str);
}
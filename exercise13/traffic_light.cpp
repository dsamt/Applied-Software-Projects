// traffic_light.cpp

#include "traffic_light.h"
#include <QWidget>
#include <QLayout>
#include <QRadioButton>

TrafficLight::TrafficLight(QWidget * parent): QWidget(parent) {

  redlight = new QRadioButton;
  redlight->setCheckable(true);
  redlight->setEnabled(false);
  redlight->toggle();   // initialize the red light to be ON
  redlight->setChecked(true);
  redlight->setStyleSheet("QRadioButton::indicator:checked { background-color: red;}");
  
  yellowlight = new QRadioButton;
  yellowlight->setCheckable(true);
  yellowlight->setEnabled(false);
  yellowlight->setChecked(false);
  yellowlight->setStyleSheet("QRadioButton::indicator:checked { background-color: yellow;}");
    
  greenlight = new QRadioButton;
  greenlight->setCheckable(true);
  greenlight->setEnabled(false);
  yellowlight->setChecked(false);
  greenlight->setStyleSheet("QRadioButton::indicator:checked { background-color: green;}");
  
  auto layout = new QVBoxLayout;
  layout->addWidget(redlight);
  layout->addWidget(yellowlight);
  layout->addWidget(greenlight);

  setLayout(layout);
}

void TrafficLight::light_update() {
	if (redlight->isChecked()) {
		redlight->setChecked(false);
		greenlight->toggle();
		greenlight->setChecked(true);
		
	}
	else if (greenlight->isChecked()) {
		greenlight->setChecked(false);
		yellowlight->toggle();
		yellowlight->setChecked(true);
	}
	else if (yellowlight->isChecked()) {
		yellowlight->setChecked(false);
		redlight->toggle();
		redlight->setChecked(true);
	}
	
}
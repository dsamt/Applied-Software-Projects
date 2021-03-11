// traffic_light.h
#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include <QWidget>
#include <QTimer>

class QRadioButton;

class TrafficLight: public QWidget{
  Q_OBJECT

public:
  TrafficLight(QWidget * parent = nullptr);
  
  
private:
  QRadioButton * redlight;
  QRadioButton * yellowlight;
  QRadioButton * greenlight;
  

public slots:
	void light_update();
};

#endif

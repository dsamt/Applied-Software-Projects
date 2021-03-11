// widget_events.hpp
#ifndef WIDGET_EVENTS_H
#define WIDGET_EVENTS_H

#include <QtWidgets>
#include <QEvent>

class WidgetEvent : public QWidget {
	Q_OBJECT

public:
	WidgetEvent();
	~WidgetEvent();

	bool event(QEvent* ev) override;
	

};


#endif
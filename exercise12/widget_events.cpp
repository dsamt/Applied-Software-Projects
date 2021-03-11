// widget_events.cpp

#include <QtWidgets>
#include <QDebug>
#include "widget_events.hpp"
#include <complex>
#include <iostream>
#include <QEvent>

template<typename EnumType>
QString toString(const EnumType& enumValue) {
	const char* enumName = qt_getEnumName(enumValue);
	const QMetaObject* metaObject = qt_getEnumMetaObject(enumValue);
	if (metaObject)
	{
		const int enumIndex = metaObject->indexOfEnumerator(enumName);
		return QString("%1::%2::%3").arg(metaObject->className(), enumName, metaObject->enumerator(enumIndex).valueToKey(enumValue));
	}

	return QString("%1::%2").arg(enumName).arg(static_cast<int>(enumValue));
}

WidgetEvent::~WidgetEvent() {

}

WidgetEvent::WidgetEvent() {

}

bool WidgetEvent::event(QEvent* ev) {
	qDebug() << "Event Type: " << toString(ev->type());
	std::string mystring;
	std::cin >> mystring;
}


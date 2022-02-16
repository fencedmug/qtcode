#ifndef USE_DATETIME_H
#define USE_DATETIME_H

#endif // USE_DATETIME_H

#include <QDebug>
#include <QDateTime>
#include <iostream>

void DateTimeExample()
{
    qDebug() << "DateTime Example";

    // formats
    QString dateFormat("yyyy-MM-dd");
    QString timeFormat("HH:mm:ss.zzz");

    // get today's date time
    QDateTime datetime = QDateTime::currentDateTime();
    qDebug() << "Today:        " << datetime.toString();
    qDebug() << "Today's date: " << datetime.toString(dateFormat);
    qDebug() << "Today's time: " << datetime.toString(timeFormat);

    // offset by a few seconds
    QDateTime offset = datetime.addSecs(5);
    qDebug() << "Offset time:  " << offset.toString(timeFormat);

    qDebug() << "\n";
}

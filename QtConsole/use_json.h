#ifndef USE_JSON_H
#define USE_JSON_H

#endif // USE_JSON_H

#include <QDebug>
#include <QJsonDocument>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>


void JsonExample()
{
    qDebug() << "Json Example";
    QFile file("example.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "failed to open file";
        return;
    }

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    QJsonObject root = doc.object();
    QJsonArray itemsArray = root["items"].toArray();

    for (int i = 0; i < itemsArray.size(); i++)
    {
        QString itemName = itemsArray[i].toString();
        qDebug() << "item: " << itemName;
    }

    // remember to close the file to release handle
    file.close();

    qDebug() << "\n";
}

#include <QCoreApplication>
#include <iostream>

#include <QJsonDocument>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    //return a.exec();

    QFile file("example.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        std::cout << "failed to open file" << std::endl;
        return 0;
    }

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    QJsonObject root = doc.object();
    QJsonArray itemsArray = root["items"].toArray();

    for (int i = 0; i < itemsArray.size(); i++)
    {
        QString itemName = itemsArray[i].toString();
        std::cout << "item: " << itemName.toStdString() << std::endl;
    }

    file.close();
    return 0;
}

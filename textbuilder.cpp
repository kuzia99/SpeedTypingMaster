#include "textbuilder.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QRandomGenerator>
#include <QDateTime>
#include <QDir>

TextBuilder::TextBuilder()
{

}

QString TextBuilder::generateText(QString language)
{
     QString filePath = QDir::currentPath() + "/" +  language + ".json";
     qDebug() << "path: " << QDir::currentPath();
     QString val;
     QFile file;
     file.setFileName(filePath);
     file.open(QIODevice::ReadOnly | QIODevice::Text);
     val = file.readAll();
     file.close();

    QJsonDocument    doc = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject json = doc.object();
    QJsonArray wordArray = json["words"].toArray();
    int wordsCount = json["wordsCount"].toInt();
    QVector <QVariant> wordVector = wordArray.toVariantList();

    QString rezultBuilding;

    QRandomGenerator gen;
    gen.seed(QDateTime::currentSecsSinceEpoch());

    for (int i = 0; i < 400; ++i)
    {
        rezultBuilding += (wordVector.at(gen.bounded(0, wordsCount)).toString() + " ");
    }
    return rezultBuilding;
}

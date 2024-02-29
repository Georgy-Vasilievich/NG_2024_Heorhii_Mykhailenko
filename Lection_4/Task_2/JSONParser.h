#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include "Parser.h"

class JSONParser : public Parser
{
private:
    QJsonDocument m_file;
public:
    JSONParser();
    void setFile(const QString &pathToFile) override;
    QVariant getKey(const QString &key) override;
    void setKey(const QString &key, const QVariant &data) override;
    bool dumpToFile(const QString &pathToFile) override;
};

#endif // JSONPARSER_H

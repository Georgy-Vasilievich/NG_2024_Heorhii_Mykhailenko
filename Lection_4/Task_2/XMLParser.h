#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QApplication>
#include <QtXml>
#include <QFile>
#include "Parser.h"

class XMLParser : public Parser
{
private:
    QDomDocument m_file;
public:
    XMLParser();
    void setFile(const QString &pathToFile) override;
    QVariant getKey(const QString &key) override;
    void setKey(const QString &key, const QVariant &data) override;
    bool dumpToFile(const QString &pathToFile) override;
};

#endif // XMLPARSER_H

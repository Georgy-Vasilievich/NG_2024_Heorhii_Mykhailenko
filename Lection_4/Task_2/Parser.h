#ifndef PARSER_H
#define PARSER_H

#include <QApplication>

class Parser
{
public:
    virtual void setFile(const QString &pathToFile) = 0;
    virtual QVariant getKey(const QString &key) = 0;
    virtual void setKey(const QString &key, const QVariant &data) = 0;
    virtual bool dumpToFile(const QString &pathToFile) = 0;
};

#endif // PARSER_H

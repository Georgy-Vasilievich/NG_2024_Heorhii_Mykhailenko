#include "JSONParser.h"

JSONParser::JSONParser()
{

}

void JSONParser::setFile(const QString &pathToFile) {
    QFile file(pathToFile);
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        m_file = QJsonDocument::fromJson(data);
        file.close();
    }
}

QVariant JSONParser::getKey(const QString &key) {
    QJsonObject obj = m_file.object();
    return obj.value(key).toVariant();
}

void JSONParser::setKey(const QString &key, const QVariant &data) {
    QJsonObject obj = m_file.object();
    obj.insert(key, QJsonValue::fromVariant(data));
    m_file.setObject(obj);
}

bool JSONParser::dumpToFile(const QString &pathToFile) {
    QFile file(pathToFile);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(m_file.toJson());
        file.close();
        return true;
    }
    return false;
}

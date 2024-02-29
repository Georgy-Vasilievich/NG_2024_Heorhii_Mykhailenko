#include "XMLParser.h"

XMLParser::XMLParser()
{

}

void XMLParser::setFile(const QString &pathToFile) {
    QFile file(pathToFile);
    if (file.open(QIODevice::ReadOnly)) {
        m_file.setContent(&file);
        file.close();
    }
}

QVariant XMLParser::getKey(const QString &key) {
    QDomElement root = m_file.documentElement();
    QDomNodeList items = root.elementsByTagName(key);
    if (!items.isEmpty()) {
        return items.at(0).toElement().text();
    }
    return QVariant();
}

void XMLParser::setKey(const QString &key, const QVariant &data) {
    QDomElement root = m_file.documentElement();
    QDomNodeList items = root.elementsByTagName(key);
    if (!items.isEmpty()) {
        QDomElement element = items.at(0).toElement();
        QDomNode newTextNode = m_file.createTextNode(data.toString());
        element.replaceChild(newTextNode, element.firstChild());
    } else {
        QDomElement newElement = m_file.createElement(key);
        QDomNode newTextNode = m_file.createTextNode(data.toString());
        newElement.appendChild(newTextNode);
        root.appendChild(newElement);
    }
}

bool XMLParser::dumpToFile(const QString &pathToFile) {
    QFile file(pathToFile);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << m_file.toString();
        file.close();
        return true;
    }
    return false;
}

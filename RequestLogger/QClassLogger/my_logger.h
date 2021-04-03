#ifndef MY_LOGGER_H
#define MY_LOGGER_H

#include <QObject>
#include <log4qt/logger.h>

class MyLogger : public QObject
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER

public:
    void debug(const QString &message) {
        logger()->debug(message);
    }
};

#endif // MY_LOGGER_H

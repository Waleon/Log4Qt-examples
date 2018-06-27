#ifndef MY_LOGGER_H
#define MY_LOGGER_H

#include <QObject>
#include <log4qt/logger.h>

LOG4QT_DECLARE_STATIC_LOGGER(logger, MyLogger)

class MyLogger : public QObject
{
    Q_OBJECT

public:
    MyLogger() {}
    void debug(const QString &message) { logger()->debug(message); }
};

#endif // MY_LOGGER_H

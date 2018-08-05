#ifndef MY_LOGGER_H
#define MY_LOGGER_H

#include <QObject>
#include <log4qt/logger.h>
#include <log4qt/loggerrepository.h>

class MyLogger : public QObject
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER

public:
    MyLogger(){}

    // 关闭 logger
    void shutdown() {
        logger()->removeAllAppenders();
        logger()->loggerRepository()->shutdown();
    }
};

#endif // MY_LOGGER_H

#include <QCoreApplication>
#include <qDebug>
#include <log4qt/basicconfigurator.h>
#include <log4qt/logger.h>
#include <log4qt/logmanager.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 一个简单的基础配置
    Log4Qt::BasicConfigurator::configure();

    // 获取 rootLogger
    Log4Qt::Logger *rootLogger = Log4Qt::Logger::rootLogger();
    Log4Qt::Logger *rootLogger2 = Log4Qt::LogManager::rootLogger();
    Log4Qt::Logger *rootLogger3 = Log4Qt::Logger::logger("");
    Log4Qt::Logger *rootLogger4 = Log4Qt::LogManager::logger("");
    Log4Qt::Logger *rootParentLogger = rootLogger->parentLogger();

    qDebug() << "********** rootLogger **********";
    qDebug() << rootLogger << rootLogger2 << rootLogger3 << rootLogger4;
    qDebug() << "name:" << rootLogger->name() << "object name:" << rootLogger->objectName();
    qDebug() << "parent logger:" << rootParentLogger;

    // 获取 logLogger
    Log4Qt::Logger *logLogger = Log4Qt::LogManager::logLogger();
    Log4Qt::Logger *logLogger2 = Log4Qt::Logger::logger("Log4Qt");
    Log4Qt::Logger *logLogger3 = Log4Qt::LogManager::logger("Log4Qt");
    Log4Qt::Logger *logParentLogger = logLogger->parentLogger();

    qDebug() << "********** logLogger **********";
    qDebug() << logLogger << logLogger2 << logLogger3;
    qDebug() << "name:" << logLogger->name() << "object name:" << logLogger->objectName();
    qDebug() << "parent logger:" << logParentLogger;

    // 获取 qtLogger
    Log4Qt::Logger *qtLogger = Log4Qt::LogManager::qtLogger();
    Log4Qt::Logger *qtLogger2 = Log4Qt::Logger::logger("Qt");
    Log4Qt::Logger *qtLogger3 = Log4Qt::LogManager::logger("Qt");
    Log4Qt::Logger *qtParentLogger = qtLogger->parentLogger();

    qDebug() << "********** qtLogger **********";
    qDebug() << qtLogger << qtLogger2 << qtLogger3;
    qDebug() << "name:" << qtLogger->name() << "object name:" << qtLogger->objectName();
    qDebug() << "parent logger:" << qtParentLogger;

    return a.exec();
}

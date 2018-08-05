#include <QCoreApplication>
#include <QtDebug>
#include <log4qt/logger.h>
#include <log4qt/logmanager.h>
#include <log4qt/loggerrepository.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "********** Begin **********";

    // 获取 Logger
    Log4Qt::Logger *logger1 = Log4Qt::LogManager::logger("myLogger1");
    Log4Qt::Logger *logger2 = Log4Qt::LogManager::logger("myLogger2");

    // 打印信息
    logger1->debug("Hello, logger1!");
    logger2->debug("Hello, logger2!");

    // 关闭 logger
    logger1->removeAllAppenders();
    logger1->loggerRepository()->shutdown();
    logger2->removeAllAppenders();
    logger2->loggerRepository()->shutdown();

    qDebug() << "********** End **********";

    return a.exec();
}

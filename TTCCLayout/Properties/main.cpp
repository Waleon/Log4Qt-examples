#include <QCoreApplication>
#include <log4qt/logger.h>
#include <log4qt/loggerrepository.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 获取 rootLogger
    Log4Qt::Logger* logger = Log4Qt::Logger::rootLogger();

    // 打印消息
    logger->debug("Hello, Log4Qt!");

    // 关闭 rootLogger
    logger->removeAllAppenders();
    logger->loggerRepository()->shutdown();

    return a.exec();
}

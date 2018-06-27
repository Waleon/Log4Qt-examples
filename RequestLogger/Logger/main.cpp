#include <QCoreApplication>
#include <log4qt/basicconfigurator.h>
#include <log4qt/logger.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 一个简单的基础配置
    Log4Qt::BasicConfigurator::configure();

    // 获取 rootLogger
    Log4Qt::Logger* logger = Log4Qt::Logger::rootLogger();

    // 输出
    logger->debug("Hello, Log4Qt!");

    return a.exec();
}

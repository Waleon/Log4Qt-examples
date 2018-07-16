#include <QCoreApplication>
#include <log4qt/logger.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 获取 rootLogger
    Log4Qt::Logger* logger = Log4Qt::Logger::rootLogger();

    // 打印消息
    logger->trace("This is a trace message.");
    logger->debug("This is a debug message.");
    logger->info("This is a info message.");
    logger->warn("This is a warn message.");
    logger->error("This is a error message.");
    logger->fatal("This is a fatal message.");

    return a.exec();
}

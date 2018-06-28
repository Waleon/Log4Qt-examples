#include <QCoreApplication>
#include <log4qt/logger.h>
#include "my_application.h"

int main(int argc, char *argv[])
{
    MyApplication app(argc, argv);

    // 设置配置信息
    app.setupLog4Qt();

    // 现在，可以使用 logger 了。
    Log4Qt::Logger* logger = Log4Qt::Logger::rootLogger();

    logger->trace("This is a trace message.");
    logger->debug("This is a debug message.");
    logger->info("This is a info message.");
    logger->warn("This is a warn message.");
    logger->error("This is a error message.");
    logger->fatal("This is a fatal message.");

    return 0;
}

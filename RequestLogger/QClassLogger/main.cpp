#include <QCoreApplication>
#include <log4qt/basicconfigurator.h>
#include "my_logger.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 一个简单的基础配置
    Log4Qt::BasicConfigurator::configure();

    // 使用自定义的 logger
    MyLogger logger;
    logger.debug("Hello, Log4Qt!");

    return a.exec();
}

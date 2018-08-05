#include <QCoreApplication>
#include <QtDebug>
#include "my_logger.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "********** Begin **********";

    // 使用自定义的 logger
    MyLogger myLogger;

    // 输出信息
    myLogger.logger()->debug("Hello, Log4Qt!");
    myLogger.logger()->info("Hello, Qt!");

    // 关闭 logger
    myLogger.shutdown();

    qDebug() << "********** End **********";

    return a.exec();
}

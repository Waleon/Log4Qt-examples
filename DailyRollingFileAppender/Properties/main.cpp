#include <QCoreApplication>
#include <QThread>
#include <QtDebug>
#include <qt_windows.h>
#include <log4qt/logger.h>
#include <log4qt/loggerrepository.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "********** Begin **********";

    // 获取 rootLogger
    Log4Qt::Logger* logger = Log4Qt::Logger::rootLogger();

    int count = 0;
    while (count < 10) {
        // 输出信息
        logger->info("Hello, Log4Qt!");
        QThread::sleep(30);
        ++count;
    }

    // 关闭 rootLogger
    logger->removeAllAppenders();
    logger->loggerRepository()->shutdown();

    qDebug() << "********** End **********";

    return a.exec();
}

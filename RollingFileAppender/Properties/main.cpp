#include <QCoreApplication>
#include <QtDebug>
#include <log4qt/logger.h>
#include <log4qt/loggerrepository.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "********** Begin **********";

    // 获取 rootLogger
    Log4Qt::Logger* logger = Log4Qt::Logger::rootLogger();

    // 读取文件，并写入日志
    QString appPath = QCoreApplication::applicationDirPath();
    QFile f(appPath + "/QtSrc.log");
    if (f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&f);
        QString line;
        while (!in.atEnd()) {
            line = in.readLine();
            logger->info(line);
        }
        f.close();
    } else {
        qDebug() << "Open failed: " << f.errorString();
    }

    // 关闭 rootLogger
    logger->removeAllAppenders();
    logger->loggerRepository()->shutdown();

    qDebug() << "********** End **********";

    return a.exec();
}

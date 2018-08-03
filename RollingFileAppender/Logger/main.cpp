#include <QCoreApplication>
#include <QtDebug>
#include <log4qt/logger.h>
#include <log4qt/ttcclayout.h>
#include <log4qt/RollingFileAppender.h>
#include <log4qt/loggerrepository.h>
#include <qt_windows.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "********** Begin **********";

    // 使用 rootLogger 打印日志
    Log4Qt::Logger *logger = Log4Qt::Logger::rootLogger();

    // 创建一个 TTCCLayout（输出时间、线程、Logger 以及消息内容）
    Log4Qt::TTCCLayout *layout = new Log4Qt::TTCCLayout();
    layout->setName("My Layout");
    layout->activateOptions();

    // 创建一个 RollingFileAppender（滚动多个文件）
    Log4Qt::RollingFileAppender *appender = new Log4Qt::RollingFileAppender();
    appender->setName("My Appender");
    appender->setLayout(layout);
    appender->setFile(QCoreApplication::applicationDirPath() + "/log.out");
    appender->setImmediateFlush(true);  // 立即刷新
    appender->setThreshold(Log4Qt::Level::INFO_INT);  // 设置阈值级别为 INFO
    appender->setAppendFile(true);  // 追加的方式
    // 等价于 appender->setMaximumFileSize(10 * 1024);
    appender->setMaxFileSize("10KB"); // 在滚动之前设置文件的最大大小
    appender->setMaxBackupIndex(5);  // 设置备份索引

    appender->activateOptions();

    // 在 logger 上添加 appender
    logger->addAppender(appender);

    // 设置级别为 DEBUG
    logger->setLevel(Log4Qt::Level::DEBUG_INT);

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

    // 关闭 logger
    logger->removeAllAppenders();
    logger->loggerRepository()->shutdown();

    qDebug() << "********** End **********";

    return a.exec();
}

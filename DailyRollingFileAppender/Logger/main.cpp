#include <QCoreApplication>
#include <QThread>
#include <QtDebug>
#include <log4qt/logger.h>
#include <log4qt/ttcclayout.h>
#include <log4qt/dailyrollingfileappender.h>
#include <log4qt/loggerrepository.h>

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

    // 创建一个 DailyRollingFileAppender（以指定的频率滚动）
    Log4Qt::DailyRollingFileAppender *appender = new Log4Qt::DailyRollingFileAppender();
    appender->setName("My Appender");
    appender->setLayout(layout);
    appender->setFile(QCoreApplication::applicationDirPath() + "/log.out");
    appender->setImmediateFlush(true);  // 立即刷新
    appender->setThreshold(Log4Qt::Level::INFO_INT);  // 设置阈值级别为 INFO
    appender->setAppendFile(true);  // 追加的方式

    // 等价于 appender->setDatePattern("'.'yyyy-MM-dd-hh-mm");
    appender->setDatePattern(Log4Qt::DailyRollingFileAppender::MINUTELY_ROLLOVER); // 日期模式

    appender->activateOptions();

    // 在 logger 上添加 appender
    logger->addAppender(appender);

    // 设置级别为 DEBUG
    logger->setLevel(Log4Qt::Level::DEBUG_INT);

    int count = 0;
    while (count < 10) {
        // 输出信息
        logger->info("Hello, Log4Qt!");
        QThread::sleep(30);
        ++count;
    }

    // 关闭 logger
    logger->removeAllAppenders();
    logger->loggerRepository()->shutdown();

    qDebug() << "********** End **********";

    return a.exec();
}

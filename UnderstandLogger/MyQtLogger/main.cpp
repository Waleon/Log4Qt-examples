#include <QCoreApplication>
#include <QtDebug>
#include <log4qt/logger.h>
#include <log4qt/logmanager.h>
#include <log4qt/ttcclayout.h>
#include <log4qt/fileappender.h>
#include <log4qt/loggerrepository.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 创建一个 TTCCLayout（输出时间、线程、Logger 以及消息内容）
    Log4Qt::Logger *logger = Log4Qt::Logger::rootLogger();
    Log4Qt::TTCCLayout *layout = new Log4Qt::TTCCLayout();
    layout->setName("My Layout");
    layout->activateOptions();

    // 创建一个 FileAppender（将日志内容输出到文件中）
    // true 以 Append 方式打开文件，false 以 Truncate 方式打开文件。
    QString file = QCoreApplication::applicationDirPath() + "/test.log";
    Log4Qt::FileAppender *appender = new Log4Qt::FileAppender(layout, file, true);
    appender->setName("My Appender");
    appender->activateOptions();
    // 在 rootLogger 上添加 fileAppender
    logger->addAppender(appender);

    // 设置级别为 DEBUG
    logger->setLevel(Log4Qt::Level::DEBUG_INT);

    // 允许处理 Qt 消息
    Log4Qt::LogManager::setHandleQtMessages(true);

    // 输出信息
    logger->debug("This is a debug message.");
    qDebug() << "This is a debug message too.";

    // 关闭 rootLogger
    logger->removeAllAppenders();
    logger->loggerRepository()->shutdown();

    return a.exec();
}

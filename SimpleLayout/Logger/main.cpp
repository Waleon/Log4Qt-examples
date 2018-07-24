#include <QCoreApplication>
#include <log4qt/logger.h>
#include <log4qt/simplelayout.h>
#include <log4qt/consoleappender.h>
#include <log4qt/loggerrepository.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 创建一个 SimpleLayout（输出日志的级别和消息内容）
    Log4Qt::Logger *logger = Log4Qt::Logger::rootLogger();
    Log4Qt::SimpleLayout *layout = new Log4Qt::SimpleLayout();
    layout->setName("My Layout");
    // layout->setShowLevel(false);
    layout->activateOptions();

    // 创建一个 ConsoleAppender（将日志内容输出到控制台上）
    Log4Qt::ConsoleAppender *appender = new Log4Qt::ConsoleAppender(layout, Log4Qt::ConsoleAppender::STDOUT_TARGET);
    appender->setName("My Appender");
    appender->activateOptions();
    logger->addAppender(appender);

    logger->setLevel(Log4Qt::Level::DEBUG_INT);
    logger->debug("Hello, Log4Qt!");

    // 关闭 logger
    logger->removeAllAppenders();
    logger->loggerRepository()->shutdown();

    return a.exec();
}

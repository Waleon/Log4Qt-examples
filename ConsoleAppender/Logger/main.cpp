#include <QCoreApplication>
#include <QTextCodec>
#include <log4qt/logger.h>
#include <log4qt/ttcclayout.h>
#include <log4qt/consoleappender.h>
#include <log4qt/loggerrepository.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 创建一个 TTCCLayout（输出时间、线程、Logger 以及消息内容）
    Log4Qt::Logger *logger = Log4Qt::Logger::rootLogger();
    Log4Qt::TTCCLayout *layout = new Log4Qt::TTCCLayout();
    layout->setName("My Layout");
    layout->activateOptions();

    // 创建一个 ConsoleAppender（将日志内容输出到控制台上）
    Log4Qt::ConsoleAppender *appender = new Log4Qt::ConsoleAppender();
    appender->setName("My Appender");
    appender->setLayout(layout);
    appender->setEncoding(QTextCodec::codecForName("UTF-8"));  // 设置编码
    appender->setTarget(Log4Qt::ConsoleAppender::STDOUT_TARGET);  // 输出到 stdout
    appender->setImmediateFlush(true);  // 立即刷新
    appender->setThreshold(Log4Qt::Level::INFO_INT);  // 设置阈值级别为 INFO
    appender->activateOptions();

    // 在 logger 上添加 appender
    logger->addAppender(appender);

    // 设置级别为 DEBUG
    logger->setLevel(Log4Qt::Level::DEBUG_INT);

    // 输出信息
    logger->debug("Hello, Log4Qt!");
    logger->info("Hello, Qt!");

    // 关闭 logger
    logger->removeAllAppenders();
    logger->loggerRepository()->shutdown();

    return a.exec();
}

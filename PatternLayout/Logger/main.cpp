#include <QCoreApplication>
#include <log4qt/logger.h>
#include <log4qt/patternlayout.h>
#include <log4qt/consoleappender.h>
#include <log4qt/loggerrepository.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 创建一个 PatternLayout（根据模式字符串输出日志事件）
    Log4Qt::Logger *logger = Log4Qt::Logger::rootLogger();
    Log4Qt::PatternLayout *layout = new Log4Qt::PatternLayout();
    layout->setHeader("----- Header -----");  // 设置标头信息
    layout->setFooter("----- Footer -----");  // 设置页脚信息
    layout->setName("My Layout");
    // layout->setConversionPattern(Log4Qt::PatternLayout::TTCC_CONVERSION_PATTERN);
    // layout->setConversionPattern("%d{yyyy-MM-dd hh:mm:ss} - %m%n");
    // layout->setConversionPattern("The output message is: %m%n");
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

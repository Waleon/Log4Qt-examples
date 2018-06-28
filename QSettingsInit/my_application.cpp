#include "my_application.h"
#include <log4qt/logger.h>
#include <QSettings>

MyApplication::MyApplication(int &argc, char **argv, int)
    : QCoreApplication(argc, argv)
{
    // 设置应用程序数据，以允许 Log4Qt 初始化读取正确的值
    setOrganizationName("MyOrganisation");
    setApplicationName("MyApplication");
    setOrganizationDomain("https://github.com/Waleon");
}

MyApplication::~MyApplication()
{
}

void MyApplication::setupLog4Qt()
{
    QSettings s;

    QStringList groups = s.childGroups();
    if (!groups.contains("Log4Qt")) {
        // 将 Log4Qt 的日志级别设置为 INFO
        s.beginGroup("Log4Qt");
        s.setValue("Debug", "INFO");

        // 配置日志输出至文件 logger.log，使用级别 INFO
        s.beginGroup("Properties");
        s.setValue("log4j.rootLogger", "INFO, logFile");
        s.setValue("log4j.appender.logFile", "org.apache.log4j.FileAppender");
        s.setValue("log4j.appender.logFile.file", "logger.log");
        s.setValue("log4j.appender.logFile.layout", "org.apache.log4j.TTCCLayout");
        s.setValue("log4j.appender.logFile.layout.dateFormat", "ISO8601");
    }
}

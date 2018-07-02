#include <QCoreApplication>
#include <QStandardPaths>
#include <QFile>
#include <log4qt/logger.h>
#include <log4qt/propertyconfigurator.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString configLoc = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);

    // 用指定的配置文件进行配置
    QString configFile = configLoc + "/log4qt.conf";
    if (QFile::exists(configFile))
        Log4Qt::PropertyConfigurator::configureAndWatch(configFile);

    Log4Qt::Logger* logger = Log4Qt::Logger::rootLogger();

    logger->trace("This is a trace message.");
    logger->debug("This is a debug message.");
    logger->info("This is a info message.");
    logger->warn("This is a warn message.");
    logger->error("This is a error message.");
    logger->fatal("This is a fatal message.");

    return 0;
}

#include <QCoreApplication>
#include <QSqlQuery>
#include <QtDebug>
#include <log4qt/logger.h>
#include <log4qt/logmanager.h>
#include <log4qt/loggerrepository.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 数据库连接名
    const QString connectionName = "MyConnection";

    // 数据库名
    const QString databaseName = "MyDB.db";

    // 表名
    const QString tableName = "MyTable";

    // 表中的字段名
    const QString timeStampField = "TimeStamp";
    const QString loggeNameField = "LoggeName";
    const QString threadNameField = "ThreadName";
    const QString levelField = "Level";
    const QString messageField = "Message";

    // 建表语句
    const QString createStatement = QString("create table %1"
                                            "(%2 varchar,%3 varchar,%4 varchar,%5 varchar,%6 varchar)")
            .arg(tableName).arg(timeStampField).arg(loggeNameField)
            .arg(threadNameField).arg(levelField).arg(messageField);

    qDebug() << "********** Begin **********";

    // 创建连接，并打开数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    db.setDatabaseName(databaseName);
    if (!db.open()) {
        qDebug() << "Database open failed.";
        return 0;
    }

    // 数据库中的表
    QStringList tables = db.tables();
    qDebug() << "Tables: " << db.tables();

    // 若表不存在，则创建
    if (!tables.contains(tableName)) {

        qDebug() << "Table does not exist.";

        QSqlQuery query(db);
        bool success = query.exec(createStatement);
        if (!success) {
            qDebug() << "Create table failed.";
            return 0;
        }
    }

    // 创建一个 layout（用于控制日志输出格式）
    Log4Qt::Logger *logger = Log4Qt::Logger::rootLogger();

    // 设置级别为 DEBUG
    logger->setLevel(Log4Qt::Level::DEBUG_INT);

    // 输出信息
    logger->debug("Hello, Log4Qt!");

    // 关闭 rootLogger
    logger->removeAllAppenders();
    logger->loggerRepository()->shutdown();

    qDebug() << "********** End **********";

    return a.exec();
}

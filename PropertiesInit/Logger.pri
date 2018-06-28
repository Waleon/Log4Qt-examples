# 定义 Log4Qt 源码路径
LOG4QT_SRC_PATH = $$PWD/../Log4Qt-master/src

# 定义 Log4Qt 源码路径
LOG4QT_SRC_PATH = $$PWD/../Log4Qt-master/src

# 指定链接到项目中的库列表
LIBS += -L$$PWD/../Libs -llog4qt

# 指定编译项目时应该被搜索的 #include 目录
INCLUDEPATH += $$LOG4QT_SRC_PATH

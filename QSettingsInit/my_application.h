#ifndef MY_APPLICATION_H
#define MY_APPLICATION_H

#include <QCoreApplication>

class MyApplication : public QCoreApplication
{
    Q_OBJECT

public:
    MyApplication(int &argc, char **argv, int = ApplicationFlags);
    ~MyApplication();
    void setupLog4Qt();
};

#endif // MY_APPLICATION_H

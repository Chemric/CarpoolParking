#include "programThreadBash.h"

ProgramThread::ProgramThread(QProcess* proc, QString* prog, QStringList* arg)
{
    proces=proc;
    program=prog;
    args=arg;

    start();
}


void ProgramThread::run()
{
    int exitCode = proces->execute(*program , *args);
    //qDebug() << exitCode;
}

ProgramThread::~ProgramThread()
{
    proces->close();

}

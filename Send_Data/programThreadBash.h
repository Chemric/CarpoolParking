#ifndef PROGRAMTHREADBASH_H
#define PROGRAMTHREADBASH_H
#include <qthread.h>
#include <QProcess>
#include <QtDebug>

class ProgramThread : public QThread
{
    Q_OBJECT
public:
    ProgramThread(QProcess* proc, QString* prog, QStringList* arg);
    ~ProgramThread();

protected:
    void run();

private:
    QProcess* proces;
    QString* program;
    QStringList* args;
};

#endif // PROGRAMTHREADBASH_H

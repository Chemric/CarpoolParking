#ifndef EVENT_H
#define EVENT_H
#include <stdio.h>
#include <QVector>
#include <QProcess>
#include <QString>
#include <QStringList>
#include <QtDebug>
#include <qobject.h>
#include "activeaccounts.h"
#include "nummerplaten.h"
#include "programThreadBash.h"

class Event: public QObject
{
    Q_OBJECT

public:
    Event();

    void RunPythonScript();
    void RunBashFile();
    void updateAantalPersonen();
    void checkvoldoendePers();


    //getters
    int getId() const;
    int getAantalPersonen() const;
    bool getGenoegPers() const;

    //setters
    void setId(int value);
    void setAantalPersonen(int value);

protected:
    int id;
    int aantalPersonen;
    bool genoegPers = false;
};

#endif // EVENT_H

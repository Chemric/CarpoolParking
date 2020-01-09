#ifndef NUMMERPLATEN_H
#define NUMMERPLATEN_H
#include <stdio.h>
#include <QSqlQuery>
#include <string>
#include <QFile>
#include <QtDebug>

class NummerPlaten
{
public:
    NummerPlaten(int id);

    QByteArray updateFoto();
    QByteArray leesNummerplaat();
    float leesZekerheid();


    //getters
    int getEventID() const;
    QByteArray getNummer() const;
    float getZekerheid() const;
    QByteArray getFoto() const;

protected:
    int EventID;
    QByteArray foto;
    QByteArray Nummer;
    float zekerheid;

};

#endif // NUMMERPLATEN_H

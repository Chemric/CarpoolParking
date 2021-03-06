/*
 *Programma voor het versturen van de data naar de MYSQL server
 * @author: Christiaan Prévot
 * @date: 4/01/2020
*/
#include <cstdio>
#include <QCoreApplication>
#include <QtDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QFile>
#include <QSqlQuery>
#include <QProcess>
#include <QString>
#include <QStringList>

#include <wiringPi.h>

#include "event.h"
#include "activeaccounts.h"
#include "nummerplaten.h"


/*
 * Functie om connectie met de database te maken en de nodige informatie te sturen
*/
void makeConnection(){

    wiringPiSetup();
    pinMode (0, INPUT);
    pinMode (2, OUTPUT);
    pinMode (3, OUTPUT);

    Event* event =new Event();

    if(event->getGenoegPers()){
        NummerPlaten* nummerplaten;
        int fotoID;

        QSqlDatabase db = QSqlDatabase :: addDatabase("QMYSQL");
        db.setHostName("db.pxl-ea-ict.be");
        db.setDatabaseName("pxleai1q_jungleb");
        db.setUserName("pxleai1q_jungleb");
        db.setPassword("ohFacJR7mMAUpywl");
        bool ok = db.open();

        if(ok)
        {
            qDebug()<<"connected";
        }
        else {
            qDebug()<<"error no connection";
        }

        QSqlQuery queryAantalMensen;

        queryAantalMensen.prepare("INSERT INTO Event ( AantalMensen) VALUES (:pers) ");
        queryAantalMensen.bindValue(":pers", event->getAantalPersonen());
        qDebug()<<"aantal pers sended";

        if(!queryAantalMensen.exec()){
            qDebug()<<"error send #mensen failed";
        }

        QSqlQuery queryGetEventID;

        queryGetEventID.exec("SELECT MAX(ID) FROM Event");
        queryGetEventID.first();
        event->setId( queryGetEventID.value(0).toInt() );
        qDebug()<<event->getId();
        nummerplaten = new NummerPlaten(event->getId());
        qDebug()<<"get eventID";

        QSqlQuery queryFoto;

        queryFoto.prepare("INSERT INTO Foto (PNG) Values (:foto)");
        queryFoto.bindValue(":foto", nummerplaten->getFoto());
        qDebug()<<"Foto sended";

        if(!queryFoto.exec()){
            qDebug()<<"error send foto failed";
        }

        QSqlQuery queryGetFotoID;
        queryGetFotoID.exec("SELECT MAX(ID) FROM Foto");
        queryGetFotoID.first();
        fotoID = queryGetFotoID.value(0).toInt();
        qDebug()<<"get fotoID";


        QSqlQuery queryNummerPlaat;
        queryNummerPlaat.prepare("INSERT INTO NummerPlaten (EventID, FotoID, Nummer, zekerheid) VALUES (:id,:foto,:nummer,:zekerheid)");
        queryNummerPlaat.bindValue(":id", event->getId());
        queryNummerPlaat.bindValue(":foto",fotoID);
        queryNummerPlaat.bindValue(":nummer",nummerplaten->getNummer());
        queryNummerPlaat.bindValue(":zekerheid",nummerplaten->getZekerheid());
        qDebug()<<"nummerplaat sended";

        if(!queryNummerPlaat.exec()){
            qDebug()<<"error send nummerplaat failed";
        }

        db.close();
        qDebug()<<"closed";

        qDebug()<<"rijd maar verder \n";
        while(digitalRead(0) == 1){

            digitalWrite(2,1);
            digitalWrite(3,0);
        }
    }

    else{
        qDebug()<<"onvoldoende personen rijd terug";
    }

    while(digitalRead(0) == 1){   
        digitalWrite(2,0);
        digitalWrite(3,1);
    }
}

/*
 * Functie om de io pin te lezen die controleerd of er een auto voor de slachtboom staat
*/
void readIo (){

    wiringPiSetup();
    pinMode (0, INPUT);
    pinMode (2, OUTPUT);
    pinMode (3, OUTPUT);

    while(1){
        //qDebug()<< digitalRead(0);

        if (digitalRead(0) == 1){
            makeConnection();
            digitalWrite(2,0);
            digitalWrite(3,0);
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    readIo();

    return a.exec();

}

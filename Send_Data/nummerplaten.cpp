#include "nummerplaten.h"

NummerPlaten::NummerPlaten(int id, float zekerheids)
{

    EventID = id;
    foto = updateFoto();
    Nummer = leesNummerplaat();
    zekerheid = zekerheids;

}

/*
 * de foto wordt uit een file gehaald.
*/
QByteArray NummerPlaten::updateFoto()
{
    QFile file;
    file.setFileName("/home/student/Desktop/Code_github/TextDetection/images/filename2.jpg");

    if(!file.exists()){

        qDebug()<<"error no file found";

    }

    file.open(QIODevice::ReadOnly);
    return file.readAll();

}

/*
 * functie die de gegeven nummerplaat uitleest
*/
QByteArray NummerPlaten::leesNummerplaat()
{
    QFile file("/home/student/Desktop/Code_github/TextDetection/laatstePlaat.txt");

    if(!file.exists()){
        qDebug()<<"error no file found";
    }
    file.open(QIODevice::ReadOnly);
    QByteArray readValue = file.readAll();
    qDebug()<< readValue ;
    file.close();
    return readValue;

}

int NummerPlaten::getEventID() const
{
    return EventID;
}



QByteArray NummerPlaten::getNummer() const
{
    return Nummer;
}

float NummerPlaten::getZekerheid() const
{
    return zekerheid;
}

QByteArray NummerPlaten::getFoto() const
{
    return foto;
}

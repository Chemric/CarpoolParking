#include "event.h"

Event::Event()
{
    RunBashFile();

    checkvoldoendePers();

    if (genoegPers == true){
        RunPythonScript();
    }
}

int Event::getId() const
{
    return id;
}

void Event::setId(int value)
{
    id = value;
}

void Event::setAantalPersonen(int value)
{
    aantalPersonen = value;
}

int Event::getAantalPersonen() const
{
    return aantalPersonen;
}

/*
 * functie om de shell script op te roepen om het aantal geconnecteerde devices te tellen.
*/
void Event::RunBashFile()
{
    QString program = "bash";
    QStringList  args = QStringList() << "/home/student/Desktop/Code_github/WatchConnection/pingArpClientsQT.sh";
    QProcess proces;

    int exitCode = proces.execute(program , args);

    proces.close();
    qDebug()<<proces.isOpen();
    updateAantalPersonen();
}
/*
 * Het aantal personen wordt uit een txt file gelezen.
*/
void Event::updateAantalPersonen()
{
    QFile file("/home/student/Desktop/Code_github/WatchConnection/aantalConnections.txt");

    if(!file.exists()){
        qDebug()<<"error no file found";
    }
    file.open(QIODevice::ReadOnly);
    QByteArray readValue = file.readAll();
    readValue=readValue.left(1);
    qDebug()<< "testje ";
    qDebug()<< readValue ;
    setAantalPersonen(readValue.toInt());
    qDebug()<< readValue.toInt() ;
}

/*
 * kontroleer of er genoeg personen zijn geconnecteerd
*/
void Event::checkvoldoendePers()
{
    int i=0;

    for(i=0;i<=2; i++){
        if (getAantalPersonen() >= 2)
        {
            genoegPers=true;
            return;
        }

        else{
            RunBashFile();
        }
    }
    genoegPers=false;
    qDebug()<<"Error niet voldoende personen";
    qDebug()<< getAantalPersonen();
}


/*
 * functie om de python script op te roepen en een foto te maken van de nummerplaat en deze te analyseren.
*/
void Event::RunPythonScript()
{
    QString program =  "python3.7";
    QStringList  args = QStringList() << "/home/student/Desktop/Code_github/TextDetection/text_recognition.py";
    QProcess proces;
    int exitCode = proces.execute( program , args);
    qDebug() << exitCode;
}


bool Event::getGenoegPers() const
{
    return genoegPers;
}


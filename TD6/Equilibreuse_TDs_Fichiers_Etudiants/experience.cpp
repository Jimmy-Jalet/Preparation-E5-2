#include <QFileInfo>
#include <QSettings>
#include <QDebug>
#include <QDataStream>
#include <QPointF>


#include "experience.h"

Experience::Experience(QObject *parent) : QObject(parent)
  , vitesseMaxi(0)
  , nbEchantillons(0)
  , origine(0)
  , vitesse(0)
  , mesuresBrutes(nullptr)
{
    LireFichierIni();
}

void Experience::LireFichierIni()
{
    int capacite;
    float sensibilite;
    QChar date,modele,serie;
    QString nomFichierIni = "equilibreuse.ini";
    QFileInfo fichierIni(nomFichierIni);
    if (fichierIni.exists() && fichierIni.isFile())
    {
        // à compléter la lecture du fichier
        //JaugeA
        QSettings paramsEquilibreuse(nomFichierIni,QSettings::IniFormat);
        paliers[]capacite =paramsEquilibreuse.value("JaugeA/capacite","25").toInt();
        date=paramsEquilibreuse.value("JaugeA/date","09-22-1998").toString().at(0);
        modele =paramsEquilibreuse.value("JaugeA/modele","MB-25").toInt();
        sensibilite =paramsEquilibreuse.value("JaugeA/sensibilite","3.348").toInt();
        serie =paramsEquilibreuse.value("JaugeA/serie","C30629").toString().at(0);
        //JaugeO
        capacite =paramsEquilibreuse.value("JaugeO/capacite","25").toInt();
        date=paramsEquilibreuse.value("JaugeO/date","10-05-1998").toString().at(0);
        modele =paramsEquilibreuse.value("JaugeO/modele","MB-25").toInt();
        sensibilite =paramsEquilibreuse.value("JaugeO/sensibilite","3.328").toInt();
        serie =paramsEquilibreuse.value("JaugeO/serie","C30637").toString().at(0);





    }
    else
    {
        // si le fichier n’existe pas, il est créé avec les valeurs par défaut
        QString nomFichierIni=qApp->Equilibreuse()+".ini";
        QSettings paramsEquilibreuse(nomFichierIni,QSettings::IniFormat);

        //JaugeA
        paramsEquilibreuse.beginGroup("JaugeA");
        paramsEquilibreuse.setValue("capacite","25");
        paramsEquilibreuse.setValue("date","09-22-1998");
        paramsEquilibreuse.setValue("modele","MB-25");
        paramsEquilibreuse.setValue("sensibilite","3.348");
        paramsEquilibreuse.setValue("serie","C30629");
        paramsEquilibreuse.endGroup();

        //JaugeO
        paramsEquilibreuse.beginGroup("JaugeO");
        paramsEquilibreuse.setValue("capacite","25");
        paramsEquilibreuse.setValue("date","10-05-1998");
        paramsEquilibreuse.setValue("modele","MB-25");
        paramsEquilibreuse.setValue("sensibilite","3.328");
        paramsEquilibreuse.setValue("serie","C30637");
        paramsEquilibreuse.endGroup();

        // il est ensuite enregistré
    }
}

void Experience::EnregistreFichierIni(const typePalier _paliers[])
{
    // à compléter l’enregistrement du fichier
}

typePalier *Experience::ObtenirCarateristiquesPaliers()
{
    return paliers;
}

void Experience::LireMesuresBrutes(QString &_nomFichier)
{
    // à completer dans le TD2
}

void Experience::InitiliserCourbes()
{
    int indiceFin = nbEchantillons / 2 ;
    int indiceA = 0;
    int indiceO = nbEchantillons /2 ;

    courbeA.clear();
    courbeO.clear();
    PointDeCourbe unPoint;
    for(int i = 0 ; i < indiceFin ; i++)
    {
        unPoint.setX(i);
        unPoint.setY(mesuresBrutes[indiceA++]);
        courbeA.append(unPoint);
        unPoint.setY(mesuresBrutes[indiceO++]);
        courbeO.append(unPoint);
    }
}

QList<QPointF> *Experience::ObtenirCourbeA()
{
    return (QList<QPointF>*) &courbeA;
}

QList<QPointF> *Experience::ObtenirCourbeO()
{
    return (QList<QPointF>*) &courbeO;
}

void Experience::ObtenirTypeAffichage(bool &_newton, bool &_pointCodeur)
{
    _newton = false;
    _pointCodeur = true;
}

/**
 * @brief Experience::RechercherEffortMax
 * @param courbe définit sur qu'elle courbe la recherche est effectuée 'A' ou 'O'
 * @return Le point possedant la valeur de l'effort le plus grand
 * @details Recherche le point dont l'amplitude est la plus grande sur l'une des 2 courbes.
 */
QPointF Experience::RechercherEffortMax(QChar courbe)
{
    QList<PointDeCourbe> *laCourbe = &courbeO;
    if(courbe =='A')
        laCourbe = &courbeA;

    QList<PointDeCourbe>::iterator max = std::max_element(laCourbe->begin(), laCourbe->end());
    return *max;
}

/**
 * @brief Experience::RechercherEffortAzero
 * @param courbe définit sur qu'elle courbe la recherche est effectuée 'A' ou 'O'
 * @return la valeur de l'effort pour à l'origine de la courbe
 */
double Experience::RechercherEffortAzero(QChar courbe)
{
    QList<PointDeCourbe> *laCourbe = &courbeO;
    if(courbe =='A')
        laCourbe = &courbeA;
    return laCourbe->at(0).y();
}

/**
 * @brief Experience::RechercherEffortAquatreVingtDix
 * @param courbe définit sur qu'elle courbe la recherche est effectuée 'A' ou 'O'
 * @return la valeur de l'effort à 90°
 */
double Experience::RechercherEffortAquatreVingtDix(QChar courbe)
{
    QList<PointDeCourbe> *laCourbe = &courbeO;
    if(courbe =='A')
        laCourbe = &courbeA;
    return laCourbe->at(250).y();   // 90° * 1000 ptsCodeur / 360°
}

/**
 * @brief Experience::ObtenirVitesse
 * @return La vitesse de l'expérience courante
 */
qint16 Experience::ObtenirVitesse()
{
    return vitesse;
}

#pragma once
#include "HCI.h"
#include "ISynchronized.h"

#include <iostream>
#include <fstream>
#include <vector>

/*!
* \class File
* \brief Impl�mentation de l'interface via fichier
* Sorties et entr�es dans un fichier
*
* Les fichiers sont synchronis�s avec le timer pour sortir les donn�es � la fin de chaque tick. Ce m�canisme permet d'afficher plusieurs colonnes de donn�es dans un m�me fichier provenant de diff�rents modules.
*/

class File :
    public HCI, ISynchronized
{
private:
    mutable std::ofstream file; /*!< Le fichier utilis� */
    std::vector<double> dataBuff; /*!< Le tampon des donn�es (et de leur num�ro de colonne) � �crire � chaque pas de temps */
public:
    /*!
    * \fn File(std::string)
    * \brief Ouvre le fichier indiqu�, le cr�� si n�cessaire. L'option loglevel ne sert qu'en cas de fichier de log et non de donn�es.
    */
    File(std::string path, logLevel = INFO);
    ~File();

    /*!
    * \fn logv(std::string mess, bool withTime = true) const
    * \brief Affiche le message mess dans le fichier avec ou sans la valeur du timer actuel.
    */
    void logv(std::string, bool = true) const;

    /*!
    * \fn void addData(double, int)
    * \brief Ajout une valeur � la ligne, dans la colonne indiqu�e par le deuxi�me argument
    */
    void addData(double, int);

    /*!
    * \fn void clock(int) = 0
    * \brief M�thode appell�e � chaque pas de temps pour �crire dans le fichier les donn�es plac�es dans le buffer
    *
    */
    virtual void clock(int);

private:
    /*!
    * \fn void printStr(std::string)
    * \brief Ecrit la ligne dans le fichier et va � la ligne
    */
    void printStr(std::string) const;

};


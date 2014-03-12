#pragma once

#include "Module.h"

/*!
* \class Physics
* \brief Classe abstraite pour d�crire les diff�rentes actions de l'environnement sur les modules
*
* Prend en attribut un module dont elle � le droit de changer les param�tres.
*
*/

class Physics : public ISynchronized
{
protected:
    Module* module;
    
public:
    Physics(Module *);
    virtual ~Physics();

    /*!
    * \fn void clock(int) = 0
    * \brief M�thode appell�e � chaque pas de temps
    *
    */
    virtual void clock(int) = 0;
};


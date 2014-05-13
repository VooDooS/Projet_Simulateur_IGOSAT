#pragma once

#include <iostream>
#include <vector>
#include "Module.h"
#include "Connexion.h"
#include "ISynchronized.h"
#include "Timer.h"

/*!
 * \class MacroModule
 * \brief
 */

/*!
* \typedef typedef std::unordered_map<std::string, std::shared_ptr<Module>> Modules
* \brief Un raccourci pratique pour la hashtable des sous-modules.
*  On utilise un shared_ptr pour s'assurer de la d�l�tion des modules lors de la destruction du macromodule
*/
typedef std::unordered_map<std::string, std::shared_ptr<Module>> SubModules;

/*!
* \typedef ttypedef  std::vector<std::shared_ptr<Connexion>> Connexions
* \brief Un raccourci pratique pour e vector des Connexions.
* On utilise un shared_ptr pour s'assurer de la d�l�tion des connexions lors de la destruction du macromodule
*/
typedef  std::vector<std::shared_ptr<Connexion>> Connexions;

class MacroModule : public Module {
private:
    SubModules modules;       /*!< Les sous-modules de module */
    Connexions connexions;    /*!< Les connexions entre les sous-modules */

public:
    
    /*!
     * \fn MacroModule()
     * \brief Constructeur par d�faut
     */
    MacroModule(std::string = "DefaultName", Params = Params(), std::string cp = std::string());

    /*!
    * \fn MacroModule(std::string, Memory<int>, Params = Params())
    * \brief Constructeur avec m�moire
    */
    MacroModule(std::string, Memory<int>, Params = Params());
    
    /*!
     * \fn ~MacroModule()
     * \brief Destructeur
     */
    virtual ~MacroModule();
    
    /*!
    * \fn void addSubModule(Module* mod)
    * \brief Ajoute un sous-module � la liste
    */
    void addSubModule(Module*);

    /*!
    * \fn void addConnexion(Connexion* conn)
    * \brief Ajoute une connexion � la liste 
    */
    void addConnexion(Connexion*);

    /*!
    * \fn std::shared_ptr<Module> getModuleByName(std::string name)
    * \brief Renvoie le module voulu
    * Exception g�r�e
    */
    std::shared_ptr<Module> getModuleByName(std::string);
    
};
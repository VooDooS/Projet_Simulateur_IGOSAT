#include "Generators.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <direct.h>

using namespace std;


Generators::Generators()
{
}


void Generators::genModule() {
    bool isMacro = false;
    string isMacros = "a";
    string nomModule = "a";

    vector<pair<string, double>> params;
    vector<pair<string, double>> messs;
    vector<string> mods;
    string parami = "", modi = "", messi = "";

    cout << "**GENERATION DE MODULE**" << endl;
    cout << endl << "*INFOS GENERALES*" << endl;

    //Est-ce un macro module ?
    isMacro = getAnswer("Macromodule");

    //Quel est son nom ?
    nomModule = getString("Nom du module");

    //Des param�tres:
    cout << endl << "*PARAMETRES*" << endl;
    
    while (true) {
        cout << "Nom (vide si fin des parametres): ";
        getline(cin, parami);

        //Si fin de la lsite des param�tres, on break:
        if (parami.empty()) break;

        //Sinon on demande la valeur et on pushback:
        params.push_back(make_pair(parami, getDouble("Valeur (double)")));
    }

    //Messages:
    cout << endl << "*MESSAGES*" << endl;

    while (true) {
        cout << "Nom (vide si fin): ";
        getline(cin, messi);

        //Si fin de la lsite des modules, on break:
        if (messi.empty()) break;

        //Sinon on ajoute � la liste avec le temps qui va bien:
        messs.push_back(make_pair(messi, getInt("Temps de transmission (int) (0 = instant)")));
    }

    //Modules connect�s:
    cout << endl << "*MODULES CONNECTES*" << endl;

    while (true) {
        cout << "Nom (vide si fin): ";
        getline(cin, modi);

        //Si fin de la lsite des modules, on break:
        if (modi.empty()) break;

        //Sinon on ajoute � la liste:
        mods.push_back(modi);
    }

    //If macro:
    if (isMacro) {
        nomModule = nomModule + "Module";
    }

    //On g�n�re le code:
    genModuleFiles(isMacro, nomModule, params, messs, mods);
}

void Generators::genModuleFiles(bool macro, string nom,
    vector<pair<string, double>> params,
    vector<pair<string, double>> mess,
    vector<string> connexions){

    //Un fichier xml � g�n�rer, et deux fichiers source:
    _mkdir("GenCode");

    genModXmlFile(nom, params, mess, connexions);
    //genModCPPFile

    cout << "G�n�ration termin�e !" << endl;
}

void Generators::genModXmlFile(string nom,
    vector<pair<string, double>> params,
    vector<pair<string, double>> mess,
    vector<string> connexions) {

    cout << "G�n�ration du XML." < endl;

    //Writing to file:
    ofstream file("GenCode/" + nom + ".xml");
    file << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl;
    file << "<module name=\"" << nom << "\">" << endl;
    
    //Param�tres:
    file << "\t<parameters>" << endl;
    for (int i = 0; i < params.size(); i++) {
        file << "\t\t<parameter name=\"" << params[i].first << "\">" << endl;
        file << "\t\t\t<value>" << params[i].second << "</value>" << endl;
        file << "\t\t\t<unit></unit>" << endl;
        file << "\t\t</parameter>" << endl;
    }
    file << "\t</parameters>" << endl;

    //Messages:
    file << "\t<messages>" << endl;
    for (int i = 0; i < mess.size(); i++) {
        file << "\t\t<message name=\"" << mess[i].first << "\">" << endl;
        file << "\t\t\t<time>" << mess[i].second << "</time>" << endl;
        file << "\t\t</message>" << endl;
    }
    file << "\t</messages>" << endl;

    //Sockets:
    file << "\t<sockets>" << endl;
    for (int i = 0; i < connexions.size(); i++) {
        file << "\t\t<socket name=\"to" << connexions[i] << "\"></socket>" << endl;
    }
    file << "\t</sockets>" << endl;

    file << "</module>" << endl;

    file.close();
}

Generators::~Generators()
{
}

bool Generators::getAnswer(string mess) {
    bool repb = false;
    string rep = "";
    while (rep != "O" && rep != "n") {
        cout << mess << " (O/n) : ";
        getline(cin, rep);
    }
    if (rep == "O") repb = true;
    return repb;
}

string Generators::getString(string mess) {
    string rep = "";
    while (rep.empty()) {
        cout << mess << ": ";
        getline(cin, rep);
    }
    return rep;
}

double Generators::getDouble(string mess) {
    string rep;
    double repd;
    bool ok = false;
    
    while (!ok) {
        rep = getString(mess);
        try {
            repd = stod(rep);
            ok = true;
        }
        catch (invalid_argument) {}
    }

    return repd;
}

int Generators::getInt(string mess) {
    string rep;
    int repd;
    bool ok = false;

    while (!ok) {
        rep = getString(mess);
        try {
            repd = stoi(rep);
            ok = true;
        }
        catch (invalid_argument) {}
    }

    return repd;
}
#pragma once

/*!
* \class ISynchronized
* \brief Interface pour �l�ment synchronis�
*
* Cette interface vise � homog�n�iser la notion de temps (timer) pour les classes qui en d�pendent.
*/

class ISynchronized
{
public:
    virtual ~ISynchronized() {};
    virtual void clock(int time) = 0;
};
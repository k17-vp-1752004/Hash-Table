#ifndef _HASH_ELEMENT
#include "element.h"
#else


template<class K, class V>
Element<K, V>::Element()
{
    this->cle= K();
    this->valeur = V();
}

template<class K, class V>
Element<K, V>::Element(const K& cle, const V& valeur)
{
    this->cle = K(cle);
    this->valeur = V(valeur);
}

#endif
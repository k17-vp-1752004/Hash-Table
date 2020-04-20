#ifndef _HASH_ELEMENT
#define _HASH_ELEMENT

#include "cle.h"
#include "infoassociee.h"

template<class K, class V>
struct Element {
    K cle; //numero de produit
    V valeur; //prix de produit
    Element();
    Element(const K &, const V &);
};

#include "element.cpp"
#endif
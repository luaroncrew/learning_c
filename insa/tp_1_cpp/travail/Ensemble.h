/*************************************************************************
                           Ensemble
                             -------------------
    début                : 28.09.2023
    e-mail               : kirill.makarov@insa-lyon.fr
*************************************************************************/

#if ! defined ( ENSEMBLE_H )
#define ENSEMBLE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes
const int CARD_MAX = 5;
//------------------------------------------------------------------ Types
enum crduEstInclus {NON_INCLUSION, INCLUSION_LARGE, INCLUSION_STRICTE};
enum crduAjouter {DEJA_PRESENT, PLEIN, AJOUTE};
//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//
//
//------------------------------------------------------------------------

class Ensemble {
    public:
        void Afficher(void);
        bool EstEgal(const Ensemble & unEnsemble) const;
        crduEstInclus EstInclus(const Ensemble & unEnsemble) const;
        crduAjouter Ajouter(int aAjouter);
        unsigned int Ajuster(int delta);
        bool Retirer(int element);
        unsigned int Retirer(const Ensemble & unEnsemble);
        int Reunir(const Ensemble & unEnsemble);



    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
        Ensemble(unsigned int cardMax = CARD_MAX);
        Ensemble(int t[], unsigned int nbElements);
        virtual ~Ensemble(){};
//------------------------------------------------------------------ PRIVE

        protected:
            int * numbers;
            unsigned int maxSetLength;
            unsigned int currentSetLength;
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

        };

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // XXX_H


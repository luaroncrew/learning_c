
/*************************************************************************
                           TEnsemble  -  test of Ensemble
                             -------------------
    début                : 28.09.2023
    e-mail               : kirill.makarov@insa-lyon.fr
*************************************************************************/


/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
//------------------------------------------------------ Include personnel
#include "TEnsemble.h"
#include "Ensemble.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées


//////////////////////////////////////////////////////////////////  PUBLIC

void test4() {
    int table[7] = {1, 12, 6, 1, 10, 1, 1};
    int table2[7] = {1, 12, 6, 1, 10, 1, 1};
    Ensemble includedSet = Ensemble(table, 7);
    Ensemble actualSet = Ensemble(table2, 7);

    bool testOne;
    testOne = (includedSet.EstInclus(actualSet) == INCLUSION_LARGE);
    cout << "test 4.1 - ";
    cout << testOne;
    cout << "\n";

    int table3[2] = {1,  1};
    includedSet = Ensemble(table3, 2);
    bool testTwo;
    testTwo = (includedSet.EstInclus(actualSet) == INCLUSION_STRICTE);
    cout << "test 4.2 - ";
    cout << testTwo;
    cout << "\n";

    int table4[3] = {15,  16, 0};
    includedSet = Ensemble(table4, 3);
    bool testThree;
    testThree = (includedSet.EstInclus(actualSet) == NON_INCLUSION);
    cout << "test 4.3 - ";
    cout << testThree;
    cout << "\n";
}


void test5() {
    int table[7] = {1, 12, 6, 1, 10, 1, 1};
    Ensemble set = Ensemble(table, 7);
    crduAjouter result = set.Ajouter(1);
    bool testOne = (result == DEJA_PRESENT);

    cout << "test 5.1 - ";
    cout << testOne;
    cout << "\n";

    result = set.Ajouter(16);
    bool testTwo = (result == AJOUTE);

    cout << "test 5.2 - ";
    cout << testTwo;
    cout << "\n";

    int table2[3] = {1, 2, 3};
    Ensemble fullSet = Ensemble(table2, 3);
    result = fullSet.Ajouter(4);
    bool testThree = (result == PLEIN);

    cout << "test 5.3 - ";
    cout << testThree;
    cout << "\n";

    result = set.Ajouter(17);
    bool testFour = (result == AJOUTE);

    cout << "test 5.4 - ";
    cout << testFour;
    cout << "\n";

    result = set.Ajouter(0);
    bool testFive = (result == AJOUTE);

    cout << "test 5.5 - ";
    cout << testFive;
    cout << "\n";

    result = set.Ajouter(0);
    bool testSix = (result == DEJA_PRESENT);

    cout << "test 5.6 - ";
    cout << testSix;
    cout << "\n";
}

void test6() {
    int table[7] = {1, 12, 6, 1, 10, 1, 1};
    Ensemble set = Ensemble(table, 7);

    unsigned int adjustmentOneResult = set.Ajuster(-5);
    bool testOne = (adjustmentOneResult == 4);

    cout << "test 6.1 - ";
    cout << testOne;
    cout << "\n";

    unsigned int adjustmentTwoResult = set.Ajuster(5);
    bool testTwo = (adjustmentTwoResult == 9);

    cout << "test 6.2 - ";
    cout << testTwo;
    cout << "\n";

    unsigned int adjustmentThreeResult = set.Ajuster(0);
    bool testThree = (adjustmentThreeResult == 9);

    cout << "test 6.3 - ";
    cout << testThree;
    cout << "\n";
}


void test7() {
    int table[7] = {1, 12, 6, 1, 10, 1, 1};
    Ensemble set = Ensemble(table, 7);
    bool result = set.Retirer(1);
    bool testOne = (result == true);

    cout << "test 7.1 - ";
    cout << testOne;
    cout << "\n";

    result = set.Retirer(1);
    bool testTwo = (result == false);

    cout << "test 7.2 - ";
    cout << testTwo;
    cout << "\n";

    result = set.Retirer(1);
    bool testFour = (result == false);

    cout << "test 7.3 - ";
    cout << testFour;
    cout << "\n";

    int table2[7] = {1, 12, 6, 1, 10, 1, 1};
    Ensemble set2 = Ensemble(table2, 7);
    set2.Retirer(34567);
    result = set.Retirer(12);
    bool testThree = (result == true);

    cout << "test 7.4 - ";
    cout << testThree;
    cout << "\n";

    Ensemble ensemble = Ensemble();
    result = ensemble.Retirer(0);
    bool testFive = (result == false);
    cout << "test 7.5 - ";
    cout << testFive;
    cout << "\n";
}


void test8() {
    int table2[7] = {1, 12, 6, 1, 10, 1, 1};
    Ensemble set = Ensemble(table2, 7);

    int toRemove[10] = {1, 1, 1};
    Ensemble setToRemove(toRemove, 10);

    unsigned int result = set.Retirer(setToRemove);

    bool testOne = (result == 1);
    cout << "test 8.1 - ";
    cout << testOne;
    cout << "\n";


    int table3[7] = {1, 12, 6, 1, 10, 1, 1};
    Ensemble set2 = Ensemble(table3, 7);
    Ensemble set3 = Ensemble(table3, 7);
    result = set3.Retirer(set2);

    bool testTwo = (result == 4);
    cout << "test 8.2 - ";
    cout << testTwo;
    cout << "\n";
}


void test9() {
    int table[7] = {1, 12, 6, 1, 10, 1, 1};
    Ensemble set = Ensemble(table, 7);

    int table2[7] = {11, 12, 13};
    Ensemble set2 = Ensemble(table2, 3);

    int result = set.Reunir(set2);
    bool testOne = (result == 2);
    cout << "test 9.1 - ";
    cout << testOne;
    cout << "\n";

    int table3[7] = {1, 2, 3};
    Ensemble set3 = Ensemble(table3, 3);

    int table4[7] = {4, 5, 6};
    Ensemble set4 = Ensemble(table4, 3);

    result = set3.Reunir(set4);
    bool testTwo = (result == -3);
    cout << "test 9.2 - ";
    cout << testTwo;
    cout << "\n";

    int table5[7] = {1, 2, 3};
    Ensemble set5 = Ensemble(table5, 3);

    int table6[7] = {1, 2, 3};
    Ensemble set6 = Ensemble(table6, 3);


    result = set5.Reunir(set6);
    bool testThree = (result == 0);
    cout << "test 9.3 - ";
    cout << testThree;
    cout << "\n";


    int table7[0] = {};
    Ensemble set7 = Ensemble(table7, 0);

    int table8[3] = {1, 2, 3};
    Ensemble set8 = Ensemble(table8, 3);

    result = set7.Reunir(set8);
    bool testFour = (result == -3);
    cout << "test 9.4 - ";
    cout << testFour;
    cout << "\n";

    int table9[0] = {};
    Ensemble set9 = Ensemble(table9, 0);

    int table10[3] = {1, 2, 3};
    Ensemble set10 = Ensemble(table10, 3);

    result = set10.Reunir(set9);
    bool testFive = (result == 0);
    cout << "test 9.5 - ";
    cout << testFive;
    cout << "\n";


}


void test10() {
    int table10[3] = {1, 2, 3};
    Ensemble set10 = Ensemble(table10, 3);

    int table8[3] = {2, 3};
    Ensemble set8 = Ensemble(table8, 3);

    unsigned int elementsToRemove = set10.Intersection(set8);
    bool testOne = (elementsToRemove == 1);
    cout << "test 10.1 - ";
    cout << testOne;
    cout << "\n";

    int table1[7] = {1, 12, 6, 1, 10, 1, 1};
    Ensemble set1 = Ensemble(table1, 7);
    Ensemble wipedSet = Ensemble();

    unsigned int elementsToRemove1 = set1.Intersection(wipedSet);
    bool testTwo = (elementsToRemove1 == 4);
    cout << "test 10.2 - ";
    cout << testTwo;
    cout << "\n";

    set1.Afficher();
    set10.Afficher();

}

int main() {
    // test 1
//    Ensemble ensemble = Ensemble(10);
//    Ensemble ensemble1 = Ensemble(0);
//    Ensemble ensemble2 = Ensemble();
//    ensemble.Afficher();
//    ensemble1.Afficher();
//    ensemble2.Afficher();

    // test 2
//    int * table = new int[20];
//    for (int k = 0; k < 10; k++) {
//        table[k] = k;
//    }
//    for (int k = 0; k < 10; k++) {
//        table[k+10] = k;
//    }
//    Ensemble ensemble3 = Ensemble(table, 20);
//    ensemble3.Afficher();
//
//    int table2[7] = {1, 1, 1, 1, 1, 1, 1};
//    Ensemble ensemble4 = Ensemble(table2, 7);
//    ensemble4.Afficher();
//
//    int table3[7] = {1, 12, 6, 1, 10, 1, 1};
//    Ensemble ensemble6 = Ensemble(table3, 7);
//    ensemble6.Afficher();
//
//    int voidTable[0] = {};
//    Ensemble ensemble5 = Ensemble(voidTable, 0);
//    ensemble5.Afficher();
//
//    return 0;
    // test 3
//    int table[5] = {1, 4, 5, 2, 1};
//    int table2[5] =  {4, 5, 2, 1};
//    Ensemble ensemble = Ensemble(table, 5);
//    Ensemble ensemble2 = Ensemble(table2, 4);
//    bool IE = ensemble.EstEgal(ensemble2);
//    cout << IE;
//    cout << "\r\n";

    //  test 4
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
}
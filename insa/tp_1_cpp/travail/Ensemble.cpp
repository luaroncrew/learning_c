/*************************************************************************
                           Ensemble.cpp
                             -------------------
    début                : 28.09.2023
    e-mail               : kirill.makarov@insa-lyon.fr
*************************************************************************/


using namespace std;
#include <iostream>
#include "Ensemble.h"

int partition(int arr[], int start, int end)
{

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, end);
}


Ensemble::Ensemble(unsigned int cardMax) {
    #ifdef MAP
        cout << "Appel au constructeur de Ensemble" << endl;
    #endif
    maxSetLength = cardMax;
    currentSetLength = 0;
    numbers = new int[cardMax];
}


Ensemble::Ensemble(int *t, unsigned int nbElements) {
    #ifdef MAP
        cout << "Appel au constructeur de Ensemble" << endl;
    #endif
    maxSetLength = nbElements;
    numbers = new int[nbElements];
    currentSetLength = 0;

    for (int k = 0; k < nbElements; k++) {
        int newElement = t[k];
        bool newElementInserted = false;
        for (int i = 0; i < currentSetLength; i++) {
            if (numbers[i] == newElement) {
                newElementInserted = true;
            }
        }
        if (!newElementInserted) {
            numbers[currentSetLength] = newElement;
            currentSetLength += 1;
        }
    }
}


void Ensemble::Afficher() {
    cout << this->currentSetLength << "\r\n";
    cout << this->maxSetLength << "\r\n";

    int * copiedNumbers = new int[currentSetLength];
    for (int i = 0; i < currentSetLength; ++i) {
        copiedNumbers[i] = numbers[i];
    }

    quickSort(copiedNumbers, 0, currentSetLength-1);

    std::cout << "{";
    for (int i = 0; i < currentSetLength; ++i) {
        std::cout << copiedNumbers[i]; // Output the current element

        if (i < currentSetLength - 1) {
            std::cout << ","; // Add a comma and space if it's not the last element
        }
    }
    std::cout << "}\r\n";
}

bool Ensemble::EstEgal(const Ensemble & unEnsemble) const {
    if (currentSetLength != unEnsemble.currentSetLength) {
        return false;
    }
    for (int k = 0; k < currentSetLength; k++) {
        int currentElement = numbers[k];
        bool elementFound = false;
        for (int i = 0; i < currentSetLength; i++) {
            if (currentElement == unEnsemble.numbers[i]) {
                elementFound = true;
            }
        }
        if (!elementFound) {
            return false;
        }
    }
    return true;
}


crduEstInclus Ensemble::EstInclus(const Ensemble & unEnsemble) const {
    if (Ensemble::EstEgal(unEnsemble)) {
        return INCLUSION_LARGE;
    }
    bool isIncluded = true;
    for (int i = 0; i < currentSetLength; i++) {
        int selfElement = numbers[i];
        bool sameElementFoundInGivenSet = false;
        for (int k = 0; k < unEnsemble.currentSetLength; k++) {
            int givenSetElement = unEnsemble.numbers[k];
            if (selfElement == givenSetElement) {
                sameElementFoundInGivenSet = true;
                break;
            }
        }
        if (!sameElementFoundInGivenSet) {
            isIncluded = false;
            break;
        }
    }
    if (isIncluded) {
        return INCLUSION_STRICTE;
    }
    else {
        return NON_INCLUSION;
    }
}


crduAjouter Ensemble::Ajouter(int aAjouter) {
    for (int i = 0; i < currentSetLength; i++) {
        int elementToCheck = numbers[i];
        if (elementToCheck == aAjouter) {
            return DEJA_PRESENT;
        }
    }
    if (currentSetLength == maxSetLength) {
        return PLEIN;
    }
    numbers[currentSetLength] = aAjouter;
    currentSetLength += 1;
    return AJOUTE;
}

unsigned int Ensemble::Ajuster(int delta) {
    int * replacementNumbers;
    if ((maxSetLength + delta) < currentSetLength) {
        maxSetLength = currentSetLength;
        replacementNumbers = new int[currentSetLength];
    }
    else {
        replacementNumbers = new int[(maxSetLength + delta)];
        maxSetLength += delta;
    }
    for (int i = 0; i < currentSetLength; i++) {
        replacementNumbers[i] = numbers[i];
    }
    delete [] numbers;
    numbers = replacementNumbers;
    return maxSetLength;
}

bool Ensemble::Retirer(int element) {
    if (currentSetLength == 0) {
        delete [] numbers;
        numbers = new int[0];
        maxSetLength = currentSetLength;
        return false;
    }
    int foundElementIndex = -1;
    for (int i = 0; i < currentSetLength; i++) {
        if (numbers[i] == element) {
            foundElementIndex = i;
        }
    }
    if (foundElementIndex == (currentSetLength - 1)) {
        int * replacementNumbers = new int[currentSetLength - 1];
        for (int k = 0; k < (currentSetLength - 1); k ++) {
            replacementNumbers[k] = numbers[k];
        }
        delete [] numbers;
        numbers = replacementNumbers;
        currentSetLength -= 1;
        maxSetLength = currentSetLength;
        return true;
    }
    else if (foundElementIndex == -1) {
        int * replacementNumbers = new int[currentSetLength];
        for (int k = 0; k < (currentSetLength); k ++) {
            replacementNumbers[k] = numbers[k];
        }
        delete [] numbers;
        numbers = replacementNumbers;
        maxSetLength = currentSetLength;
        return false;
    }
    else {
        int * replacementNumbers = new int[currentSetLength - 1];
        int replacementIndex = 0;
        for (int k = 0; k < currentSetLength; k++) {
            if (k != foundElementIndex) {
                replacementNumbers[replacementIndex] = numbers[k];
                replacementIndex += 1;
            }
        }
        delete [] numbers;
        numbers = replacementNumbers;
        currentSetLength -= 1;
        maxSetLength = currentSetLength;
        return true;
    }
}


unsigned int Ensemble::Retirer(const Ensemble & unEnsemble) {
    int indicesToRemove[currentSetLength];
    int indicesCounter = 0;
    for (int i = 0; i < currentSetLength; i++) {
        for (int k = 0; k < unEnsemble.currentSetLength; k++) {
            if (unEnsemble.numbers[k] == numbers[i]) {
                indicesToRemove[indicesCounter] = i;
                indicesCounter += 1;
            }
        }
    }
    int * replacementNumbers = new int[maxSetLength];
    int replacementIndex = 0;
    for (int i = 0; i < currentSetLength; i++) {
        bool removeItem = false;
        for (int k = 0; k < indicesCounter; k++) {
            if (i == indicesToRemove[k]) {
                removeItem = true;
            }
        }
        if (!removeItem) {
            replacementNumbers[replacementIndex] = numbers[i];
            replacementIndex += 1;
        }
    }

    delete [] numbers;
    numbers = replacementNumbers;
    currentSetLength -= indicesCounter;
    return indicesCounter;
}


int Ensemble::Reunir(const Ensemble &unEnsemble) {
    unsigned int elementsToAdd = 0;
    int elementsToAddIndices[unEnsemble.currentSetLength];
    for (int i = 0; i < unEnsemble.currentSetLength; i++) {
        bool addingCurrentElement = true;
        for (int k = 0; k < currentSetLength; k++) {
            if (numbers[k] == unEnsemble.numbers[i]) {
                addingCurrentElement = false;
            }
        }
        if (addingCurrentElement) {
            elementsToAddIndices[elementsToAdd] = i;
            elementsToAdd += 1;
        }
    }
    if ((elementsToAdd + currentSetLength) <= maxSetLength) {
        int toAddElementsIndex = 0;
        for (int k = currentSetLength; k < currentSetLength + elementsToAdd; k ++) {
            numbers[k] = unEnsemble.numbers[elementsToAddIndices[toAddElementsIndex]];
            toAddElementsIndex += 1;
        }
        currentSetLength += elementsToAdd;
        return elementsToAdd;
    }
    else {
        int * replacementNumbers = new int[currentSetLength + elementsToAdd];
        int replacementNumbersLength = 0;
        for (int k = 0; k < currentSetLength; k++) {
            replacementNumbers[replacementNumbersLength] = numbers[k];
            replacementNumbersLength += 1;
        }
        delete [] numbers;
        for (int k = 0; k < elementsToAdd; k++) {
            replacementNumbers[replacementNumbersLength] = unEnsemble.numbers[elementsToAddIndices[k]];
            replacementNumbersLength += 1;
        }
        numbers = replacementNumbers;
        currentSetLength = replacementNumbersLength;
        maxSetLength = replacementNumbersLength;
        return -elementsToAdd;
    }
}


unsigned int Ensemble::Intersection(const Ensemble &unEnsemble) {
    int counterElementsToRemove = currentSetLength;
    int elementsToLeaveBits[currentSetLength];
    for (int i = 0; i < unEnsemble.currentSetLength; i++) {
        for (int k = 0; k < currentSetLength; k ++) {
            if (numbers[k] == unEnsemble.numbers[i]) {
                elementsToLeaveBits[k] = 1;
                counterElementsToRemove -= 1;
            }
            else {
                elementsToLeaveBits[k] = 0;
            }
        }
    }
    // debug
    for (int i = 0; i < currentSetLength; i++) {
        cout << " " << elementsToLeaveBits[i];
    }
    cout << "\n";
    if (counterElementsToRemove) {
        int * replacementNumbers = new int[currentSetLength-counterElementsToRemove];
        int replacementNumbersNextIndex = 0;
        for (int i = 0; i < currentSetLength; i++) {
            if (elementsToLeaveBits[i] == 1) {
                replacementNumbers[replacementNumbersNextIndex] = numbers[i];
                replacementNumbersNextIndex += 1;
            }
        };
        delete [] numbers;
    }
    return counterElementsToRemove;
}
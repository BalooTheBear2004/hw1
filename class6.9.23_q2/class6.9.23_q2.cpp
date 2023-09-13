#include <iostream>
using namespace std;
#include<string>


double WeightedAverage(double* x, double* w, int size)  // call by reference a,b are aliases
{
    double wxTotal = 0;
    double wTotal = 0;
    for (int i = 0; i < size; i++) {
        wxTotal += x[i] * w[i];
        wTotal += w[i];
    }
    return (wxTotal / wTotal);
}



bool IsArithmeticProgression(int* arr, int size = 3)
{
    int d = arr[1] - arr[0];
    for (int i = 1; i < size - 1; i++) {
        if ((arr[i+1] - arr[i]) == d) {
            
        }
        else {
            return false;
        }
    }
    return true;
}


char** Spliter(string s , int* size) {
    

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 32) {
            (*size)++;
        }
    }

    char** arr;
    arr = new char* [*size];
    int start = 0;
    int stop = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 32) {
            stop = i ;
            for (int j = start; j < stop; j++) {
                arr[i] = new char[stop - start];
                arr[i][j] = s[j];
            }
            start = stop + 1;
        }
    }

    return arr;
}


char** words(char* sentce, int& size) {
    char temp[100];
    char** word;
    int count = 1;
    for (int i = 0; sentce[i] != '\0'; i++) {
        if (sentce[i] == ' ')count++;
    }
    size = count;
    word = new char* [count];
    count = 0;
    for (int i = 0, j = 0; sentce[i] != '\0'; i++) {
        while (sentce[i] != ' ' && sentce != '\0')
        {
            temp[j] = sentce[i];
            i++;
            j++;
        }
        temp[j] = '\0';
        j = 0;
        word[count] = new char[strlen(temp) + 1];
        strcpy(word[count], temp);
        count++;
    }
    return word;
}
char* doubleWord(char* sentence) {
    int size = strlen(sentence);
    int fullSize = size * 2;
    char desentece[100];
    for (int i = 0; i < size; i++) {
        desentece[i] = sentence[i];
        desentece[i + size] = sentence[i];
    }
    desentece[fullSize] = '\0';
    delete[] sentence;
    sentence = new char(fullSize + 1);
    strcpy(sentence, desentece);
    return sentence;
}

int main()
{
    //********q1******************
    //int size = 4;
    //double* x = NULL;
    //x = new double[size];
    //x[0] = 2;
    //x[1] = 3;
    //x[2] = 4;
    //x[3] = 5;

    //double* w = NULL;
    //w = new double[size];
    //w[0] = 0.2;
    //w[1] = 0.3;
    //w[2] = 0.4;
    //w[3] = 0.5;
    //double avg = WeightedAverage(x, w, size);
    //cout << "the Weighted Average is: " << avg;

    //delete[] x;
    //delete[] w;
    //********q2******************
    //int size = 0;
    //cout << "enter the size of the array: ";
    //cin >> size;
    //int* arr = new int[size];
    //cout << "enter the numbers: "<< endl;
    //for (int i = 0; i < size; i++) {
    //    cin >> arr[i];
    //}
    //bool a = IsArithmeticProgression(arr, size);
    //if (a == true) {
    //    cout << "the array is an arithmetic series";
    //}
    //else {
    //    cout << "the array is not arithmetic series";
    //}
    //delete[] arr;
    char blabla[99] = "lola boba ahaha kfj";
    char** sentence;
    int size;
    sentence = words(blabla, size);
    for (int i = 0; i < size; i++) {
        sentence[i] = doubleWord(sentence[i]);
        cout << sentence[i] << endl;
        delete[] sentence[i];
    }
    delete[] sentence;







    return 0;

}


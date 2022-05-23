// LabVector.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include "headers/List.h"
#include "headers/Vector/Vector.h"
#include "headers/Vector/Vector2D.h"
#include "headers/Vector/Vector3D.h"
#include "headers/IReadable.h"
#include "headers/charline.h"
using namespace std;
void foo(IVector* i) {
    cout << i->LongVectorAB() << endl;
}
const char* Read(IReadable* i) {
    return i->prefix();
}
char* ReternChar(char* elem) 
{ 
    return elem; 
}
List<IVector*> Readable(List<IReadable*> vectors_read) {
    fstream file;
    List<IVector*> vector;
    file.open("DataFile.txt");
    if (!file.is_open()) {
        throw _exception();
    }
    else {
        charline chr, chline;
        int t = 0;
        while (!file.eof())
        {
            file >> chr;
            for (size_t i = 0; i < vectors_read.Count(); i++)
            {
                if (chr == vectors_read[i]->prefix()) {
                    chline.getvalue(file, '\n');
                    vector.Add(vectors_read[i]->Type(chline));
                    vector[t++]->Print();
                }
            }
        }

    }
    file.close();
    return vector;
}
int main()
{
    const int x = 2;
    List<Vector2D> vec2;
    List<Vector3D> vec3;
    List<IReadable*> vectors_read;
    vectors_read.Add(new Vector2D());
    vectors_read.Add(new Vector3D());
    List<IVector*> p = Readable(vectors_read);
    /*p.Add(new Vector2D());
    p.Add(new Vector3D());
    cout << Read(&a);*/

}


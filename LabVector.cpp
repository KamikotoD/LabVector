#include <iostream>
#include <fstream>
#include <string>
#include "headers/List.h"
#include "headers/charline.h"
#include "headers/IReadable.h"
#include "headers/IWritable.h"
#include "headers/Vector/Vector.h"
#include "headers/Vector/Vector2D.h"
#include "headers/Vector/Vector3D.h"
#include "headers/Readable.h"
#include "headers/Writable.h"
int main()
{
    List<IReadable*> vectors_read;
    List<IWritable*> vectors_write;
    vectors_read.Add(new Vector2D());
    vectors_read.Add(new Vector3D());
    Readable DataFromFile;
    Writable DataInFile;
    DataFromFile.ReadableDataFromFile(vectors_read);
    List<IVector*> vector;// = DataFromFile.ReadableDataFromFile(vectors_read);
    for (size_t i = 0; i < vectors_read.Count(); i++)
    {
        vector.Add((IVector*)vectors_read[i]);
    }


    for (size_t i = 0; i < vector.Count(); i++)
    {
        vectors_write.Add(vector[i]);
    }
    DataInFile.WritableDataInFile(vectors_write);
    /*Writable(vectors_read, vector);*/
    /*p.Add(new Vector2D());
    p.Add(new Vector3D());
    cout << Read(&a);*/

}


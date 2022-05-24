#include "headers/function.h"
int main()
{
    List<IReadable*> vectors_read;
    vectors_read.Add(new Vector2D());
    vectors_read.Add(new Vector3D());
    List<IVector*> vector = Readable(vectors_read);
    for (size_t i = 0; i < vector.Count(); i++)
    {
        vector[i]->Print();
    }
    Writable(vectors_read, vector);
    /*p.Add(new Vector2D());
    p.Add(new Vector3D());
    cout << Read(&a);*/

}


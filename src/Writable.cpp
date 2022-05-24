#include "../headers/Writable.h"

void Writable::WritableDataInFile(List<IWritable*> vector, const char* name_file)
{
    ofstream file;
    file.open(name_file);
    if (!file.is_open()) {
        throw _exception();
    }
    for (size_t i = 0; i < vector.Count(); i++)
    {
        file << vector[i]->WriteDataInFile()<< endl;
    }
    file.close();
}

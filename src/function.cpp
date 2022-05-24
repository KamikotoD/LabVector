#include "../headers/function.h"
List<IVector*> Readable(List<IReadable*> vectors_read, const char* name_file) {
    ifstream file;
    List<IVector*> vector;
    file.open(name_file);
    if (!file.is_open()) {
        throw _exception();
    }
    else {
        charline chr, chline;
        while (!file.eof())
        {
            file >> chr;
            for (size_t i = 0; i < vectors_read.Count(); i++)
            {
                if (chr == vectors_read[i]->prefix()) {
                    chline.getvalue(file, '\n');
                    vector.Add(vectors_read[i]->Type(chline));
                }
            }
        }

    }
    file.close();
    return vector;
}

void Writable(List<IReadable*> vectors_read, List<IVector*> vector, const char* name_file)
{
    ofstream file;
    file.open(name_file);
    if (!file.is_open()) {
        throw _exception();
    }
    for (size_t i = 0; i < vector.Count(); i++)
    {
        file << vector[i]->WriteDataInFile();
    }
    file.close();
}

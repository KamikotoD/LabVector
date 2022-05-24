#include "../headers/Readable.h"

void Readable::ReadableDataFromFile(List<IReadable*> &vectors_read, const char* name_file)
{
	ifstream file;
	List<IReadable*> vector;
	file.open(name_file);
	if (!file.is_open()) {
	    throw _exception();
	}
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
	file.close();
	vectors_read = vector;
}

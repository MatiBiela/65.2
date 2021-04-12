#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

class file
{
        ifstream inFile;
        int licznik[1000];
        int mianownik[1000];
        int ileN;

       
        public:
                file();
                ~file();
                void loop(); 
                void nieSkra();
};


file::file()
{
        inFile.open("dane_ulamki.txt"); 
        if (!inFile.good())
        {
                cerr << "Blad - pliku nie da sie otworzyc!\n";
                exit(1);
        }
}

file::~file()
{
        inFile.close();
}



void file::loop()
{
    while (!inFile.eof()) 
    {
        for(int i=0; i<1000; i++) {
            inFile >> licznik[i] >> mianownik[i]; 
		}
                
    }
}
int nwd(int n, int m){

 if (m==0) return n;
 return nwd(m,n%m);
}
void file::nieSkra()
{
	ileN = 0;
	for(int i=0; i<1000; i++){
 		if (nwd(licznik[i],mianownik[i])==1)
 		ileN++;
 	}
 	cout <<"Ulamkow nieskracalnych jest: " << ileN << endl;
}
int main() {
	file f;
	f.loop();
	f.nieSkra();
	return 0;
}


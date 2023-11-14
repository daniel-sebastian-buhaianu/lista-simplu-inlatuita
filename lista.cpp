#include <fstream>
using namespace std;
ifstream fin("lista.in");
ofstream fout("lista.out");
struct Nod { int info; Nod *urm; };
struct Lista { Nod *prim, *ultim; };
void initializeazaLista(Lista &);
void insereazaInLista(Lista &, int);
void afiseazaLista(Lista);
int main()
{
	Lista a;
	int x;
	initializeazaLista(a);
	while (fin >> x) insereazaInLista(a, x);
	fin.close();
	afiseazaLista(a);
	fout.close();
	return 0;
}
void afiseazaLista(Lista a)
{
	for (Nod *p = a.prim; p; p = p->urm)
		fout << p->info << ' ';
	fout << '\n';
}
void insereazaInLista(Lista & a, int x)
{
	Nod *p = new Nod;
	p->info = x;
	p->urm = 0;
	if (!a.ultim)
		a.prim = a.ultim = p;
	else
	{
		a.ultim->urm = p;
		a.ultim = p;
	}
}
void initializeazaLista(Lista & a)
{
	a.prim = a.ultim = 0;
}

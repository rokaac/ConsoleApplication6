#include <iostream>
#include <math.h>
using namespace std;
/*
int main() {
	int prirodan;
	float realan;
	cout << "Unesite prirodan broj" << endl;
	cin >> prirodan;
	cout << "Unesite realan broj" << endl;
	cin >> realan;
	float dijeljenje;
	dijeljenje = prirodan / realan;
	cout << dijeljenje << endl;
}
*/
// 1.
/*
char parnost(int n) {
	if (n % 2 == 0) {
		cout << "paran";
	}
	if (n % 2 != 0)
		cout << "neparan";
	return 0;
}

int main(int n) {
	cin >> n;
	cout << parnost(n);

}
*/
/*
int zbroj(int br1,int br2) {
	return br1 + br2;
}

int main(int br1, int  br2) {
	cin >> br1;
	cin >> br2;
	cout << zbroj(br1, br2);
}
*/

/*
float funkcija(float n) {
	if (n > 0)
		return sqrt(n);
	if (n < 0)
		return pow(n, 3);
}

int main(int n) {
	cin >> n;
	cout << funkcija(n);
}
*/

/*
float dijeljenje(int a, float b) {
	if (b == 0) {
		cout << "nije dozvoljeno dijeliti sa nula" << endl;
	}
	return a / b;
	cout << 3 << endl;
}

int main(int a, float b) {
	cin >> a;
	cin >> b;
	cout << dijeljenje(a, b);
}
*/

// napisi funkciju ciji ce ulazni pareametri biti koeficijenti
// kvadratne jednadzbe funkcija treba ispisati poruku 
// POSTOJE REALNA RJESENJA; nema

// ZADACI, REKURZIVNI
/*
bool djeljivo(int broj) {
	if (broj < 10) {
		return broj % 3 == 0;
	}
	else {
		int prva = broj / 10;
		int ostatak = broj % 10;
		return ostatak % 3 == 0 && djeljivo(prva);
	}
}

int main() {
	int broj;
	cin >> broj;

	if (djeljivo(broj)) {
		cout << "Sve znamenke broja su djeljive sa 3";
	}
	else
	{
		cout << "Sve znamenke broja nisu djeljive sa 3";
	}
}
*/
/*
int brojPonavljanja(char znak, char* niz) {
	if (*niz == '\0') {
		return 0;
	}
	else {
		if (*niz == znak) {
			return 1 + brojPonavljanja(znak, niz + 1);
		}
		else {
			return brojPonavljanja(znak, niz + 1);
		}
	}
}

// novo gradivo
#include <iostream>

using namespace std;

int main() {
	FILE* izlaz;
	izlaz = fopen("mojFajl.txt", "r");
	int polje[10000][3];
	for (int i = 0; i < 1000; i++) {
		//fprintf(izlaz, "%d %d %d\n", rand()%100, rand()%100, rand()%100);

		fscanf(izlaz, "%d %d %d\n", &a, &b, &c);
		polje[i][0] = a;
		polje[i][1] = b;
		polje[i][2] = c;
		//printf("%d %d %d\n", a,b,c);
		//cout<<a<<" "<<b<<" "<<c<<endl;

	}

	int a, b, c, brojIspravnih = 0;
	while (fscanf(izlaz, "%d %d %d\n", &a, &b, &c) != EOF) {
		if (a + b == c)
			brojIspravnih++;
	}
	fclose(izlaz);
	for (int i = 0; i < 100; i++)
		if (polje[i][0] + polje[i][1] == polje[i][2])
			fprintf(izlaz, "%d %d %d %c\n",
				polje[i][0], polje[i][1], polje[i][2], 'T');
		else
			fprintf(izlaz, "%d %d %d %c\n",
				polje[i][0], polje[i][1], polje[i][2], 'N');

	return 0;
}
*/

// ponavalje



int brojParnih(int num) {
	if (num < 10) {
		if (num % 2 == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		int jedinica = num % 10;
		if (jedinica % 2 == 0) {
			return 1 + brojParnih(num / 10);
		}
		else {
			return brojParnih(num / 10);
		}
	}
}

int main() {
	int broj;
	cout << "Unesite broj: ";
	cin >> broj;
	cout << "Broj parnih znamenaka u broju " << broj << " je: " << brojParnih(broj) << endl;
	return 0;
}


int kolko0(char arr[], char target, int size) {
	if (size == 0) {
		return 0;
	}
	else {
		if (arr[0] == target) {
			return 1 + kolko0(arr + 1, target, size - 1);
		}
		else {
			return kolko0(arr + 1, target, size - 1);
		}
	}
}

int main() {
	char arr[] = { 'a', 'b', 'c', 'a', 'd', 'a', 'e', 'f', 'a' };
	char target = 'a';
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "Broj ponavljanja slova '" << target << "' u polju je: " << kolko0(arr, target, size) << endl;

	return 0;
}

int sumDigitsUntil8(int num, int sum) {
	if (num < 10 && num != 8) {
		return -1;
	}

	else if (num < 10 && num == 8) {
		return sum + num;
	}
	else {
		int lastDigit = num % 10;
		if (sum + lastDigit == 8) {
			return sum + lastDigit;
		}
		else if (sum + lastDigit > 8) {
			return -1;
		}
		else {
			return sumDigitsUntil8(num / 10, sum + lastDigit);
		}
	}
}

int main() {
	int number;
	cout << "Unesite broj: ";
	cin >> number;

	int sum = sumDigitsUntil8(number, 0);
	if (sum != -1) {
		cout << "Zbroj znamenaka do 8 je: " << sum << endl;
	}
	else {
		cout << "Zbroj znamenaka ne doseže 8." << endl;
	}

	return 0;
}

#include <string>

void changeAfterDot(string& sentence, size_t index) {
	if (index >= sentence.length()) {
		return;
	}

	if (sentence[index] == '.') {
		size_t nextIndex = index + 1;
		while (nextIndex < sentence.length() && sentence[nextIndex] == ' ') {
			nextIndex++;
		}

		if (nextIndex < sentence.length()) {
			if (isalpha(sentence[nextIndex])) {
				sentence[nextIndex] = '#';
				return;
			}
		}
	}

	changeAfterDot(sentence, index + 1);
}

int main() {
	string sentence;
	cout << "Unesite rečenicu: ";
	getline(cin, sentence);

	changeAfterDot(sentence, 0);

	cout << "Rečenica nakon promjene: " << sentence << endl;

	return 0;
}
FILE* test;
test = fopen("a.txt", "r");
if (test == NULL)
    cout << "Greska";
int brojP;
char slovo;
cin >> slovo;
char ulaz;
while(fscanf(test, "%c", &ulaz) != EOF) {
    if (ulaz == slovo)
        brojP++;
}
cout << brojP;
fclose(test);
return 0;
#include <iostream>

using namespace std;

int main()
{
    FILE *unos;
    int broj;
    unos = fopen("C:\\Users\\ucenik\\Desktop\\prvi.txt","a+");
    while (1){
        cin >> broj;
        if (broj == 0)
            break;
        fprintf(unos, "%d\n",broj);
    }
    fclose(unos);

    int redak=0;
    int trazeni;
    cout << endl << "upisi trazeni: ";
    cin >> trazeni;
    unos = fopen("C:\\Users\\ucenik\\Desktop\\prvi.txt","r");
    while(1){
        fscanf(unos,"%d\n",&broj);
        redak ++;
        if (broj == trazeni){
            cout << endl << redak;
            break;
        }
    }
    fclose(unos);

    cout << endl << endl;
    int n=0;
    int Zbroj[26];
    char slovo;
    int broj1;

    unos = fopen("C:\\Users\\ucenik\\Desktop\\treci.txt","r");
    for (int i=1; i<28;i++){
        Zbroj[i] = 0;
    }
    while (fscanf(unos, "%d,%c\n", &broj1, &slovo) != EOF){
        Zbroj[slovo-'a'] +=broj1;
    }

    for (int i=0; i<26; i++){
        slovo = 'a' + i;
        cout << slovo << " " << Zbroj[i] << endl;
    }
    cout << endl << endl;
    fclose(unos);



    char a,b,c;
    char tocno[1000][4];
    int brojtocno=0;
    unos =fopen("C:\\Users\\ucenik\\Desktop\\cetvrti.txt","r");
    while (fscanf(unos, "%c,%c,%c\n", &a, &b, &c) != EOF){

        tocno[brojtocno][0] =a;
        tocno[brojtocno][1] =b;
        tocno[brojtocno][2] =c;
        if (a < b && b<c)
            tocno[brojtocno][3] ='T';
        else
            tocno[brojtocno][3] ='N';
        brojtocno++;
    }
    fclose(unos);
    unos =fopen("C:\\Users\\ucenik\\Desktop\\cetvrti.txt","w+");
    for(int i=0; i<brojtocno;i++){
        fprintf(unos,"%c,%c,%c%c\n",tocno[i][0],tocno[i][1],tocno[i][2],tocno[i][3]);
    }
    fclose(unos);
}








#include <iostream>
#include <fstream>
#include<string>

using namespace std;
//ispise brojeve jedne ispod drugih v datoteku
/*int main() {
   string ime = "datokeka.txt";
   ofstream datokeka(ime);
   int  broj;
   while (cin>>broj&&broj!=0) {
           datokeka << broj<<endl;
   }
   datokeka.close();
   return 0;
}
*/
//iz datoteke u cmd
/*
int main(){
   string ime = "znam.txt";
   ifstream znam(ime);
   int broj;
   while (znam>> broj && broj != 0) {
       cout << broj << endl;
   }
   znam.close();
   return 0;
}
*/

//ispiše koliko je znakova napisano u filu
/*
int main() {
   string ime = "datokeka.txt";
   ifstream datokeka(ime);
   char broj;
   int broj_znakova=-10;
   while (datokeka.get(broj)) {
       broj_znakova++;
   }
   cout << broj_znakova << endl;
   datokeka.close();
   return 0;
}
*/

//pronađe znak koji trazis
/*
int main() {
   string prezime = "debil.txt";
   ifstream debil(prezime);
   char znak;
   char trazeni;
   cout << "upisi znak: " << endl;
   cin >> znak;
   bool pron = false;
   while(debil.get(trazeni)) {
       if (trazeni == znak) {
           cout << "znak koji se nalazi u datoteci je:" << znak << endl;
           pron = true;
           break;
       }
   }
   if (!pron) {
       cout << "znak nije pronađen" << endl;
   }
   debil.close();
   return 0;
}
*/
/*
int main() {
   string prezime = "debil.txt";
   ifstream debil(prezime);
   char znak;
   cout << "Unesite znak koji tražite: ";
   cin >> znak;
   bool pron = false;
   char trenutni_znak;
   int redak = 1;
   while (debil.get(trenutni_znak)) {
       if (trenutni_znak == znak) {
           cout << "Znak koji tražite je pronađen u retku " << redak << endl;
           pron = true;
           break;
       }
       if (trenutni_znak == '\n') {
           redak++;
       }
   }
   if (!pron) {
       cout << "Znak nije pronađen." << endl;
   }
   debil.close();
   return 0;
}
*/
//ovaj kod ispisuje rijecu u novi red
/*
int main() {
   string ime = "datokeka.txt";
   ofstream datokeka(ime);
   string rijec;
   while (cin >> rijec&&rijec!="kraj") {
       datokeka << rijec << endl;
       
   }
   datokeka.close();
   return 0;
}
*/
//ispise u datoteci svaku unesenu račenicu u novi red
/*
int main() {
   string ime = "datokeka.txt";
   ofstream datokeka(ime);
   string linija;
   while (getline(cin, linija) && linija != "kraj") {
       datokeka << linija << endl;
   }
   datokeka.close();
   return 0;
}
*/
//ispise u 2 stucpac 1 su parni a drugi su neparni
/*
int main() {
   string ime = "datokeka.txt";
   ofstream datokeka(ime);
   int broj;
   int brojac = 0;
   while (cin >> broj && broj != 0) {
       if (brojac % 2 == 0) {
           datokeka << broj << "\t";
       }
       else {
           datokeka << broj << endl;
       }
       brojac++;
   }
   datokeka.close();
   return 0;
}
*/
//is datoteke ispise u cmd u 4 stupca
/*
int main() {
   string ime = "datokeka.txt";
   ifstream datokeka(ime);
   

   int broj;
   int brojac = 0;
   const int BROJ_STUPACA = 4;
   while (datokeka>> broj && broj != 0) {
       cout << broj << "\t";
       brojac++;
       if (brojac % BROJ_STUPACA == 0) {
           cout << endl;
       }
   }
   datokeka.close();
   return 0;
}
*/
//ispise mi velicinu u datoteku od 1 do 20 bez da ja unosim brojeve
/*
int main() {
   string ime = "datokeka.txt";
   ofstream datokeka(ime);
   const int VELICINA_POLJA = 20;
   int polje[VELICINA_POLJA];
   for (int i = 0; i < VELICINA_POLJA; i++) {
       polje[i]=i+1;
   }
   for (int i = 0; i < VELICINA_POLJA; i++) {
       datokeka << polje[i] << endl;
   }
   datokeka.close();
   return 0;
   
}
*/
//provjeri dali su brojevi u 1 i 2 stupcu jednaki brojevima u 3 stupcu
/*
int main() {
   string ime = "datokeka.txt";
   ifstream datokeka(ime);
   int broj1, broj2, broj3;
   int brojac = 0;
   bool jednakost = false;
   while (datokeka >> broj1 >> broj2 >> broj3) {
       if (broj1 + broj2 == broj3) {
           jednakost = true;
           break;
       }
   }
   if (jednakost) {
       cout << "Zbrojevi brojeva u prvom i drugom redu su jednaki broju u trećem redu." << endl;
   }
   else {
       cout << "Zbrojevi brojeva u prvom i drugom redu nisu jednaki broju u trećem redu." << endl;
   }
   datokeka.close();
   return 0;
}
*/
//ispise broj rijeci u datoteci
/*
int main() {
   string ime = "datokeka.txt";
   ifstream datokeka(ime);
   int brojac = 0;
   string rijec;
   while (datokeka >> rijec && rijec != "kraj") {
       brojac++;

   }
   cout << brojac;
   datokeka.close();
   return 0;
}
*/
-------------------------------------------------------------
using namespace std;

int main()
{
   FILEdatoteka;

   datoteka=fopen("tekst.txt","w+");
   for(int i=0;i<3;i++){
   fprintf(datoteka,"%d %d %d\n",1,2,3);

   }
   fclose(datoteka);
   int brojac=0;
   datoteka=fopen("tekst.txt","r");
   int a,b,c;
   for(int i=0;i<3;i++){
   fscanf(datoteka,"%d %d %d",&a,&b,&c);
   if(a+b==c){
       brojac+=1;
   }
   }
   cout<<brojac;

#include <iostream>

using namespace std;

int main()
{
   FILEdatoteka;

   datoteka=fopen("tekst.txt","w+");
   for(int i=0;i<3;i++){
   fprintf(datoteka,"%d %d %d\n",1,2,3);

   }
   fclose(datoteka);
   int brojac=0;
   datoteka=fopen("tekst.txt","r");
   int polje[3][3];
   int a,b,c;
   char poljeznakova[3];

   for(int i=0;i<3;i++){
   fscanf(datoteka,"%d %d %d",&a,&b,&c);
   polje[i][1]=a;
   polje[i][2]=b;
   polje[i][3]=c;

   if (polje[i][1]+polje[i][2]==polje[i][3]){
       poljeznakova[i]='t';
       brojac++;
   }
   else{poljeznakova[i]='n';}
   }
   fclose(datoteka);


   datoteka=fopen("tekst.txt","w+");
   for(int i=0;i<3;i++){
   fprintf(datoteka,"%d %d %d %c\n",polje[i][1],polje[i][2]=b,polje[i][3],poljeznakova[i]);

   }


   cout<<brojac;



   return 0;
}

#include <iostream>

using namespace std;

int main(){
   FILE *izlaz;
   izlaz = fopen("brojRj.txt","w+");
   string recenica[100];
   int brojac = 0;

   fprintf(izlaz, "%s %s %s %s %s", "m", "e", "m", "m", "m");

   fclose(izlaz);

   izlaz = fopen("brojRj.txt","r");
   while(fscanf(izlaz,"%s",recenica)!=EOF){
       brojac++;
   }
   cout << brojac;
   return 0;
}
---------------------------------------------------------------
#include <iostream>

using namespace std;

int main()
{
   FILE *unos;
   int broj;
   unos = fopen("C:\\Users\\ucenik\\Desktop\\prvi.txt","a+");
   while (1){
       cin >> broj;
       if (broj == 0)
           break;
       fprintf(unos, "%d\n",broj);
   }
   fclose(unos);

   int redak=0;
   int trazeni;
   cout << endl << "upisi trazeni: ";
   cin >> trazeni;
   unos = fopen("C:\\Users\\ucenik\\Desktop\\prvi.txt","r");
   while(1){
       fscanf(unos,"%d\n",&broj);
       redak ++;
       if (broj == trazeni){
           cout << endl << redak;
           break;
       }
   }
   fclose(unos);

   cout << endl << endl;
   int n=0;
   int Zbroj[26];
   char slovo;
   int broj1;

   unos = fopen("C:\\Users\\ucenik\\Desktop\\treci.txt","r");
   for (int i=1; i<28;i++){
       Zbroj[i] = 0;
   }
   while (fscanf(unos, "%d,%c\n", &broj1, &slovo) != EOF){
       Zbroj[slovo-'a'] +=broj1;
   }

   for (int i=0; i<26; i++){
       slovo = 'a' + i;
       cout << slovo << " " << Zbroj[i] << endl;
   }
   cout << endl << endl;
   fclose(unos);



   char a,b,c;
   char tocno[1000][4];
   int brojtocno=0;
   unos =fopen("C:\\Users\\ucenik\\Desktop\\cetvrti.txt","r");
   while (fscanf(unos, "%c,%c,%c\n", &a, &b, &c) != EOF){

       tocno[brojtocno][0] =a;
       tocno[brojtocno][1] =b;
       tocno[brojtocno][2] =c;
       if (a < b && b<c)
           tocno[brojtocno][3] ='T';
       else
           tocno[brojtocno][3] ='N';
       brojtocno++;
   }
   fclose(unos);
   unos =fopen("C:\\Users\\ucenik\\Desktop\\cetvrti.txt","w+");
   for(int i=0; i<brojtocno;i++){
       fprintf(unos,"%c,%c,%c%c\n",tocno[i][0],tocno[i][1],tocno[i][2],tocno[i][3]);
   }
   fclose(unos);
}

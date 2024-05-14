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

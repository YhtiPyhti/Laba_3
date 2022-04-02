#include <iostream>
using namespace std;

void zad_1() {
	for (double x = -5; x < 5; x++)
	{
		if (x <= -2) {
			cout << "y = " << (x + 2) / 2 << " x = " << x << endl;
		}
		else if (x > -2 && x <= 2) {
			cout << "y = " << sin(x * 3.14 / 360)/cos(x*3.14/360) <<  " x = " << x << endl;
		}
		else if (x > 2 && x < 5){
			cout << "y = " << (x -  3)/2 <<  " x = " << x << endl;
		}
	}
}

bool Pros(int a, int p){
	int t = 0;
	for (int i = 2; i < sqrt(a) || i < sqrt(p); i++) {
		if (a % i == 0 || p % i == 0) t = 1 ;
	}
	if (t == 1) return false;
	else return true;
}

void zad_2() {
	int a = 6, x = 12, p = 13, q = 0;
	if (p - 1 == x && Pros(a, p)) {
		q = 1 % p;
		cout << q;
	}
	else cout << "Теорема Ферма не работает";
}
void zad_3() {
	int b = 1234, a = 54;
	while (b != 0) {
		a %= b;
		swap(a, b);
	}
	cout << "НОД = " << a;
}

void zad_4() {
	int a = 1234, b = 54, y = 0, y1 = 1, x = 1, x1 = 0, q = 0, r = 0, r1 = 0, y2 = 0, x2 = 0;
	while (b != 0) {
		q = a / b;
		a %= b;
		x2 = x - q * x1;
		y2 = y - q * y1;
		cout << "Остаток = " << a << " X = " << x2 << " Y = " << y2  << " Частные = " << q << endl;
		x = x1;
		y = y1;
		x1 = x2;
		y1 = y2;
		swap(a, b);
	}
}

int mod(int g, int X ,int p) {
	int t = 0, t0 = g % p;
	for (int i = 1; i <= X; i++) {
		t = g % p;
		g = t * t0;
	}
	return t;
}


void zad_5() {
	int g = 5, p = 23, Xa = 4, Xb = 11, Ya = 0, Yb = 0 , k = 7, r = 0, e = 0, m = 10 , m1 = 0 , t=0;
	Ya = mod(g, Xa, p);
	Yb = mod(g, Xb, p);
	cout << "Абонент A" << " Секретный ключ - " << Xa << " Открытый ключ - " << Ya << endl;
	cout << "Абонент B" << " Секретный ключ - " << Xb << " Открытый ключ - " << Yb << endl;
	r = mod(g, k, p);
	t = mod(Yb, k, p);
	e = ((m % p) * t) % p;
	g = p - 1 - Xb;
	t = mod(r, g, p);
	m1 = ((e % p) * t) % p;

	cout << m << endl;
	cout << m1 << endl;
}

void zad_6() {

}

void zad_7() {

}

int main(){
	setlocale(LC_ALL, "Russian");
    //zad_1();
	//zad_2();
	//zad_3();
	//zad_4();
	//zad_5();
	//zad_6();
	zad_7();
}
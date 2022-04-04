#include <iostream>
#include <random>
#include <ctime>
#include <vector>
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
	for (int j = 2; j < sqrt(a); j++) {
		if (a % j == 0 ) t = 1 ;
	}
	for (int j = 2; j < sqrt(p); j++) {
		if (p % j == 0) t = 1;
	}
	if (t == 1) return false;
	else return true;
}

void zad_2() {
	int a = 3, x = 12, p = 13, q = 0;
	int t = 0, t0 = a % p;
	if (p - 1 == x && Pros(a, p) == true) {
		q = 1 % p;
		cout << "Теорема Ферма работает ";
		cout << q;
	}
	for (int i = 1; i <= x; i++) {
		t = a % p;
		a = t * t0;
	}
	cout << t;
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

	cout << "Исходный текст:" << m << endl;
	cout << "Зашифрованный текст:" << r << ", " << e << endl;
	cout << "Расшифрованный текст:" << m1 << endl;
}

int Test_Mil(int n, int &t) {
	cout << endl;
	int div = 2, g = n - 1;
	vector <int> kan;
	vector <int> num;

	mt19937 gen(time(0));
	uniform_int_distribution <int> uid1(2, n-1);

	while (g > 1) {
		while (g % div == 0) {
			kan.push_back(div);
			g /= div;
		}
		div++;
	}

	for (int i = 0; i < t ; i++) {
		num.push_back(uid1(gen));
	}

	for (auto a : num) {
		if (mod(a, n - 1, n) == 1) {
			cout << "n – составное число" << endl;
			return n;
		}
	}

	for (auto a : num) {
		for (auto q : kan) {
			if (mod(a, (n - 1) / q , n) != 1) {
				continue;
			}
		}
	}

	cout << "n – простое число" << endl;
	return n;
}

void zad_6() {
	//1
	int N = 500;
	vector<int> v(N+1);
	for (size_t i = 0; i < N + 1; i++) {
		v[i] = i;
	}

	v[0] = v[1] = 0;
	for (int i = 2; i <=N; ++i) {
		if (v[i]) {
			if (i * 1ll * i <= N) { // long long
				for (int j = i * i; j <= N; j += i)
					v[j] = 0;
			}
		}
	}
	v.erase(remove(v.begin(), v.end(), 0), v.end());
	for (auto i : v){
		cout << i << " ";
	}

	//1 a
	int r = 59, m = 0, n = 0, i = 1, t = 4;
	n = Test_Mil(r,t);

	cout << n;


}

void zad_7() {
	int x = 3, r = 7, r1 = 8, t = x % 10, t2 = r % 4 , Num = 0, Num_st = 0; //mod 4
	if (t == 0) cout << "Последняя цифра числа: 0";
	else if (t == 1) cout << "Последняя цифра числа: 1";
	else if (t == 5) cout << "Последняя цифра числа: 5";
	else if (t == 6) cout << "Последняя цифра числа: 6";
	else {
		for (int i = 1; i <= r1; i++) {
			Num_st = (r % 4);
			r = t2 * Num_st;
		}
		if(Num_st == 0) cout << "Последняя цифра числа: 1";
		else {
			for (int j = 1; j <= Num_st; j++) {
				Num = (x % 10);
				x = t * Num;
			}
			cout << "Последняя цифра числа: " << Num;
		}
	}
}

int main(){
	setlocale(LC_ALL, "Russian");
    //zad_1();
	zad_2();
	//zad_3();
	//zad_4();
	//zad_5();
	//zad_6();
	//zad_7();
}
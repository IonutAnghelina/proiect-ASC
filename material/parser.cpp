#include <string>
#include <vector>
#include <map>

using namespace std;

#include <fstream>
ifstream cin("input.txt"); ofstream cout("output.txt");

map < int, char > D;

void make_D() {

	for (char x = 'a'; x <= 'z'; x++) {
		D[int(x)] = x;
	}
	for (char x = 'A'; x <= 'Z'; x++) {
		D[int(x)] = char(x - 'A' + 'a');
	}

	D[-125] = '@'; //'ă'
	D[-94] = '/'; //'â'
	D[-101] = ','; //'ț'
	D[-103] = '.'; //'ș'
	D[-82] = '|'; //'î'
	D[-126] = '@'; //'Ă'
	D[-126] = '/'; //'Â'
	D[-102] = ','; //'Ț'
	D[-104] = '.'; //'Ș'
	D[-114] = '|'; //'Î'
}

int main()
{
	make_D();

	string s;

	while (cin>>s) {

		string t = "";

		for (auto& x : s) {
			if (D[x]) {
				t += D[x];
			}
		}

		if (t.empty()) {
			continue;
		}

		cout << t << " ";
	}
	
	return 0;
}
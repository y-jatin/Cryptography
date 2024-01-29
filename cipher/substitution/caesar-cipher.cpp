#include <bits/stdc++.h>
using namespace std;

string encrypt(string msg, int shift)
{
	string enc = "";
	for (int i = 0; i < msg.length(); i++) {
	    if (msg[i] == ' ') enc += msg[i];
		else if (isupper(msg[i]))
			enc += char(int(msg[i] + shift - 65) % 26 + 65);
		else
			enc += char(int(msg[i] + shift - 97) % 26 + 97);
	}
	return enc;
}

string decrypt(string enc, int shift)
{
	string dec = "";
	for (int i = 0; i < enc.length(); i++) {
	    if (enc[i] == ' ') dec += enc[i];
		else if (isupper(enc[i]))
			dec += char(int(enc[i] - shift - 65 + 26) % 26 + 65);
		else
			dec += char(int(enc[i] - shift - 97 + 26) % 26 + 97);
	}
	return dec;
}

int main()
{
    string msg, enc, dec; int shift;
    cout << "Enter message: "; getline(cin, msg);
    cout << "Enter shift: "; cin >> shift;
	enc = encrypt(msg, shift); cout << "Encrypted message: " << enc << endl;
	dec = decrypt(enc, shift); cout << "Decrypted message: " << dec << endl;
	return 0;
}

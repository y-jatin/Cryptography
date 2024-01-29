#include <bits/stdc++.h>
using namespace std;

string encrypt(string msg, int key){
    char matrix[key][msg.length()]; int k = -1, row = 0, col = 0; string str = "";
    for(int i = 0; i < key; ++i)
        for(int j = 0; j < msg.length(); ++j)
            matrix[i][j] = '\n';
            
    for (int i = 0; i < msg.length(); i++){
        matrix[row][col++] = msg[i];
        if (row == 0 || row == key-1)
            k = k*(-1);
        row += k;
    }
    for (int i = 0; i < key; i++){
        for (int j = 0; j < msg.length(); j++){
            if (matrix[i][j] != '\n')
                str += matrix[i][j];
        }
    }
    return str;
}

string decrypt(string enc, int key){
    char matrix[key][enc.length()]; int k = -1, row = 0, col = 0, m = 0; string str = "";
    for(int i = 0; i < key; ++i)
        for(int j = 0; j < enc.length(); ++j)
            matrix[i][j] = '\n';
            
    for (int i = 0; i < enc.length(); i++){
        matrix[row][col++] = '*';
        if (row == 0 || row == key-1)
            k = k*(-1);
        row += k;
    }
    for (int i = 0; i < key; i++){
        for (int j = 0; j < enc.length(); j++){
            if (matrix[i][j] == '*')
                matrix[i][j] = enc[m++];
        }
    }
    
    row = col = 0; k = -1;
    for(int i = 0; i < enc.length(); i++){
        str += matrix[row][col++];
 
        if(row == 0 || row == key-1)
            k= k * (-1);
 
        row = row + k;
    }
    
    return str;
}

int main()
{
    string msg, enc, dec; int key;
    cout << "Enter message: "; getline(cin, msg);
    cout << "Enter key: "; cin >> key;
    enc = encrypt(msg, key); cout << "Encrypted message: " << enc << endl;
    dec = decrypt(enc, key); cout << "Decrypted message: " << dec << endl;
    return 0;
}

#include <iostream>
#include <string>

using namespace std;

// Function to encrypt/decrypt using Caesar Cipher logic
string processCipher(string text, int key, bool encrypt) {
    string result = "";
    // If decrypting, we just reverse the shift
    if (!encrypt) key = 26 - (key % 26);

    for (char &c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += (char)((((c - base) + key) % 26) + base);
        } else {
            result += c; // Keep spaces and symbols as they are
        }
    }
    return result;
}

int main() {
    string message;
    int key, choice;

    cout << "--- 🛡️ CipherBeast CLI Tool ---" << endl;
    cout << "1. Encrypt Message" << endl;
    cout << "2. Decrypt Message" << endl;
    cout << "Select (1-2): ";
    cin >> choice;

    cin.ignore(); // Clear buffer
    cout << "Enter your message: ";
    getline(cin, message);

    cout << "Enter Key (1-25): ";
    cin >> key;

    if (choice == 1) {
        cout << "\n🔒 Encrypted: " << processCipher(message, key, true) << endl;
    } else {
        cout << "\n🔓 Decrypted: " << processCipher(message, key, false) << endl;
    }

    return 0;
}
#include <iostream>
#include <cctype>
#include <cstring>
#include <string>

using namespace std;
string cipherencyption()
{
    string message, key;
    int i = 0, j = 0;
    string ciphermessage = "";
    cout << "Enter the message \n";
    // Enter the message
    getline(cin, message);
    while (message.length() > 80)
    {
        cout << "the message is longer than 80 words. please enter smaller message";
        getline(cin, message);
    }
    // convert the message to upper
    for (char &c : message)
    {
        c = toupper(c);
    }
    // Enter the key
    cout << "Enter the key \n";
    getline(cin, key);
    while (key.length() > 8)
    {
        cout << "the key is longer than 8 words. please enter smaller key";
        getline(cin, key);
    }
    for (char c : key)
    {
        if (!isalpha(c))
        {
            cout << " the key contains an alphabetical letter \n";
            cout << " please enter valid key ";
            getline(cin, key);
        }
    }
    for (int i = 0; i < key.length(); i++)
    {
        for (char &c : key)
        {

            c = toupper(c);
        }
    }
    for (int i = 0; i < message.length(); i++)
    {
        if (isspace(message[i]))
        {
            ciphermessage += " ";
            j++;
            if (i < message.length())
            {
                if (j == key.length())
                {
                    j = 0;
                }
            }
        }
        else if (isalpha(message[i]))
        {

            char messagechar = message[i];
            char keychar = key[j];
            j++;
            char encryptedchar = ((messagechar + keychar) % 26) + 'A';
            ciphermessage += encryptedchar;
            if (i < message.length())
            {
                if (j == key.length())
                {
                    j = 0;
                }
            }
        }

        else
        {
            ciphermessage += message[i];
            j++;
            if (i < message.length())
            {
                if (j == key.length())
                {
                    j = 0;
                }
            }
        }
    }
    return ciphermessage;
}

string decyption()
{
    string message, key;
    int i = 0, j = 0;
    string deciphermessage = "";
    cout << "Enter the message\n";
    // Enter the message
    getline(cin, message);
    while (message.length() > 80)
    {
        cout << "the message is longer than 80 words. please enter smaller message";
        getline(cin, message);
    }
    // convert the message to upper
    for (char &c : message)
    {
        c = toupper(c);
    }
    // Enter the key
    cout << "Enter the key \n";
    getline(cin, key);
    while (key.length() > 8)
    {
        cout << "the key is longer than 8 words. please enter smaller key";
        getline(cin, key);
    }
    for (char c : key)
    {
        if (!isalpha(c))
        {
            cout << " the key contains an alphabetical letter \n";
            cout << " please enter valid key ";
            getline(cin, key);
        }
    }
    for (int i = 0; i < key.length(); i++)
    {
        for (char &c : key)
        {
            c = toupper(c);
        }
    }

    for (int i = 0; i < message.length(); i++)
    {
        if (isspace(message[i]))
        {

            deciphermessage += " ";
            j++;
            if (i < message.length())
            {
                if (j == key.length())
                {
                    j = 0;
                }
            }
        }
        else if (isalpha(message[i]))
        {
            char messagechar = message[i];
            char keychar = key[j];
            j++;
            char decryptedchar = ((messagechar - keychar + 26) % 26) + 'A';
            deciphermessage += decryptedchar;
            if (i < message.length())
            {
                if (j == key.length())
                {
                    j = 0;
                }
            }
        }
        else
        {
            deciphermessage += message[i];
            j++;
            if (i < message.length())
            {
                if (j == key.length())
                {
                    j = 0;
                }
            }
        }
    }
    return deciphermessage;
}

int main()
{
    cout << "WELCOM IN VIGENER CIPHER\n";
    cout << "1. Encryption\n2. Decryption\n3. EXIT\nEnter choice  ";
    string choice;
    getline(cin, choice);

    if (choice == "1")
    {
        string dencryptedText = cipherencyption();
        cout << "\nEncryption : " << dencryptedText << endl;
    }
    else if (choice == "2")
    {
        string encryptedText = decyption();
        cout << "\nEncryption : " << encryptedText << endl;
    }
    else if (choice == "3")
    {
        cout << " EXIT FROM VIGENER CIPHER";
        exit(0);
    }
    else
    {
        cout << "Invalid choice. Please enter 1 or 2 or 3\n";
    }

    return 0;
}



#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000

char* base64Encoder(char input_str[], int len_str)
{
    char char_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    char *res_str = (char *) malloc(SIZE * sizeof(char));

    int index, no_of_bits = 0, padding = 0, val = 0, count = 0, temp;
    int i, j, k = 0;

    for (i = 0; i < len_str; i += 3)
    {
        val = 0, count = 0, no_of_bits = 0;

        for (j = i; j < len_str && j <= i + 2; j++)
        {
            val = val << 8;

            val = val | input_str[j];

            count++;

        }

        no_of_bits = count * 8;


        padding = no_of_bits % 3;

        while (no_of_bits != 0)
        {
            if (no_of_bits >= 6)
            {
                temp = no_of_bits - 6;

                index = (val >> temp) & 63;
                no_of_bits -= 6;
            }
            else
            {
                temp = 6 - no_of_bits;

                index = (val << temp) & 63;
                no_of_bits = 0;
            }
            res_str[k++] = char_set[index];
        }
    }

    for (i = 1; i <= padding; i++)
    {
        res_str[k++] = '=';
    }

    res_str[k] = '\0';

    return res_str;

}

int main()
{
    char input_str[SIZE];

    cout << "Enter input string: ";
    cin.getline(input_str, SIZE);

    int len_str = strlen(input_str);

    cout << "Input string is: " << input_str << endl;
    cout << "Encoded string is: " << base64Encoder(input_str, len_str) << endl;

    return 0;
}
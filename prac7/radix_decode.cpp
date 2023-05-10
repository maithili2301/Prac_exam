#include <bits/stdc++.h>
using namespace std;
#define SIZE 100

char* base64Decoder(char encoded[], int len_str)
{
	char* decoded_string;

	decoded_string = (char*)malloc(sizeof(char) * SIZE);

	int i, j, k = 0;

	int num = 0;

	int count_bits = 0;

	for (i = 0; i < len_str; i += 4)
	{
		num = 0, count_bits = 0;
		for (j = 0; j < 4; j++)
		{
			
			if (encoded[i + j] != '=')
			{
				num = num << 6;
				count_bits += 6;
			}

			if (encoded[i + j] >= 'A' && encoded[i + j] <= 'Z')
				num = num | (encoded[i + j] - 'A');

			else if (encoded[i + j] >= 'a' && encoded[i + j] <= 'z')
				num = num | (encoded[i + j] - 'a' + 26);

			else if (encoded[i + j] >= '0' && encoded[i + j] <= '9')
				num = num | (encoded[i + j] - '0' + 52);

			else if (encoded[i + j] == '+')
				num = num | 62;

			else if (encoded[i + j] == '/')
				num = num | 63;

			else {
				num = num >> 2;
				count_bits -= 2;
			}
		}

		while (count_bits != 0)
		{
			count_bits -= 8;

			decoded_string[k++] = (num >> count_bits) & 255;
		}
	}

	decoded_string[k] = '\0';

	return decoded_string;
}

int main()
{
char input_str[SIZE];

    cout << "Enter encoded string: ";
    cin.getline(input_str, SIZE);

    int len_str = strlen(input_str);
    cout << "Encoded string is: " << input_str << endl;
    cout << "Decoded string is: " << base64Decoder(input_str, len_str) << endl;

	return 0;
}
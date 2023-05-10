#include<iostream>
#include<fstream>

using namespace std;
int main()
{
   char filename[30], ch, str[1000];
   int tot=0, i=0, vowels=0, consonants=0, ascii;
   ifstream fp;
   cout<<"Enter the Name of File: ";
   cin>>filename;
   fp.open(filename, ifstream::in);
   if(!fp)
   {
      cout<<endl<<"File doesn't exist or Access denied!";
      return 0;
   }
   while(fp>>noskipws>>ch)
   {
      str[tot] = ch;
      tot++;
   }
   fp.close();
   str[tot]='\0';

   int  j;
   float countt=0 ,alphabet[26] = {0};
   while (str[i] != '\0') {
      if (str[i] >= 'a' && str[i] <= 'z') {
         j = str[i] - 'a';
         ++alphabet[j];
         countt++;
      }
      ++i;
   }
   float per;
   cout<<countt;
   cout<<"Frequency of all alphabets in the string is:"<<endl;
   for (i = 0; i < 26; i++)
   {
    per= (alphabet[i] * 100.00)/countt;
   cout<< char(i + 'a')<<" : "<< per<< endl;
       
   }
   return 0;
}

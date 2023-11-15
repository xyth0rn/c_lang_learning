// paste things to vim
:set paste
// finish using ctrl+shift+v
:set no paste

// Basic operators and grammar
// if use <math.h>, when compiling: gcc my_code.c -lm
#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
// upon seeing "ADD" it reads as "0"
#define ADD 0

/*
---NOTE ABOUT ARRAYS---
Arrays are saved and read by using the location of a[0] and then literally counting bits of memories to access a[i].
If the value is an int, the size of each object in the array is 4 bits.
-> this is why you need to define the dimensions of an array when initializing

When transfering int / float / bool / double between functions, it calls by "value".
This maens a copy of the original value is created at a different memory location
for manipulation within the function.
Thus, the original value won't be affected.

HOWEVER, when transfering arrays between functions, it calls by "reference" aka memory location, not value
Therefore, when you WILL change the original value within the original array.

To call multidimensional arrays, only the first dimension doesn't require decleration (but you'll need to input the first dimension size):

  void call_3D_array(int array[][3][3], int size){
    ...
  }
*/


// bubble sort ---
void bubbleSort(int array[], int size) {
  for (int step = 0; step < size - 1; ++step) {
    for (int i = 0; i < size - step - 1; ++i) {
      if (array[i] > array[i + 1]) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
}}}}
/*
Because arrays are called by reference (aka memory location), you need to input the size of the array.
Note that it WILL CHANGE the value of the original array.
*/


// gcd ---
int gcd(int i, int j){
  int k;
  scanf("%d%d", &i, &j);
  while(i % j != 0){
    k = i % j;
    i = j;
    j = k;
  }
  return j;
}


int main() {
  int a=1, b=0;
  // c has <= and >= operators
  // boolean (1 for true and 0 for false)
  bool c = (a >= b);

  float  flt = 12.3456;  //  float memory size is 4 bytes
  double dbl = 1.23456789;  // double memory size is 8 bytes
  printf("%ld\n", sizeof(flt));  // printout memory size of float number flt
  printf("%f", flt);
  printf("%lf", dbl);
  printf("%6.4f", flt);  // total 6 digits, 4 decimal digits => output 12.3456
  printf("%.3f", flt);  // prints 3 decimal digits => output 1.234
  
  int flt_to_int;
  flt_to_int = (int) flt;  // (int), (float), (double), etc can be used to change variable type

  // initializing 1D array (fills with 0)
  int array_1D[3] = {0};

  // initializing multi-D array
  int array_3D[2][3][4];
  for(int i=0; i<2; i++){
    for(int j=0; j<3; j++){
      for(int k=0; k<4; k++){
        array_3D[i][j][k] = 0;
  }}}
  
  
  // check if still have input
  int aa;
  while(scanf("%d", &aa) != EOF){ printf("%d\n", aa); }
 
    
  // (cond) ? expression 1 : expression2
  // if a > 0, c = a; else c = -a;
  int c = (a > 0)?  a: -a;

  // math.h functions ---
  double power = pow(3.4 , 2.0);
  double square_root = sqrt(9);
  double get_ceiling = ceil(8.5);  // smallest integer >= x
  double get_floor = floor(8.5);   // largest integer <= x

  // stdlib.h functions ---

  // switch-case ---
  switch (flag){
  case 1:
    statements;
    break;
 
  case 2:
    statement2;
    break;
 
  default:
    default_statement;
  }
  // end of switch-case ---

  // char (1 byte)
  char c = 'a';  // using ASCII
  printf("%c", c);
  // can also use int as ASCII code value
  int c_int = 'a';
  printf("%c", c_int);

  // ctype.h functions ---
  isalnum();
  isaplha();
  islower();
  isupper();
  isdigit();  // is number
  isxdigit();  // is hexagonal number
  isprint();  // can be printed (includes space)
  isgraph();  // can be printed (excludes space)
  isspace();
  ispunct();
  iscntrl();  // is control character
  tolower();
  toupper();

  // convert char to int
  int char_to_int = '9' - '0';  // because ASCII code

  // initialize a string (aka array of char)
  // end of string must be '\0'  -> don't need to specify length of string as it uses '\0' as end
  char s[5] = {'m', 'a', 'i', 'n', '\0'};
  // or
  char s[] = {'m', 'a', 'i', 'n', '\0'};
  /*
  don't need to write '\0', but must leave one space for '\0' to be at the end
  char s[5] = {'m', 'a', 'i', 'n'};
  
  note that empty string == "" == {'\0'}
  thus the length of an empty string is 1 byte
  */
  
  int length = sizeof(s) / sizeof(char);
  /* compute s length */
  for (int i = 0; i < length; i++){ printf("%c", s[i]); }

  printf("%s", s);

  // using pointer as string init
  char str1[STRINGLEN] = "programming";
  char str2[] = "programming";
  char *str3 = "programming";
  printf("sizeof(str1) = %ld\n", sizeof(str1));
  printf("sizeof(str2) = %ld\n", sizeof(str2));
  printf("sizeof(str3) = %ld\n", sizeof(str3));
  /* result
  sizeof(str1) = 80
  sizeof(str2) = 12
  sizeof(str3) = 8
  */

  // string.h functions
  strlen();  // find length of string (excluding ending '\0')
  char *strcpy(char *s1, char *s2);  // copy s1 to s2
  char *strncpy(char *s1, const char *s2, size_t n);  // copy at most n characters from s1 to s2
  char *strcat(char *s1, char *s2);  // copy s1 and append to the end of s2
  char *strncat(char *s1, const char *s2, size_t);  // copy at most n characters from s1 to s2
  int strcmp(const char *s1, const char *s2);  // compare if s1 and s2 is the same
  int strncmp(const char *s1, const char *s2, size_t n);  // compare if the first n characters of s1 and s2 is the same
  char *strchr(const char *s, int c);  // return the pointer to the first time c appeared in s
  char *strtok(char *s1, const char *s2);  // cut s1 using s2
  // need to be cautious this may trigger "buffer overrun"

  strcmp(str_a, str_b);
  /*
  if a > b  -> return positive num
  if a < b  -> return negative num
  if a == b -> return 0
  */

  
  return 0;
}







// prime num list under 2000
2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373, 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511, 1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 1597, 1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 1663, 1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723, 1733, 1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811, 1823, 1831, 1847, 1861, 1867, 1871, 1873, 1877, 1879, 1889, 1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987, 1993, 1997, 1999

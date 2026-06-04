#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    char s1[] = {'H', 'a', 'p', 'p', 'y', '\0'};
    char s2[] = "Life\0";
    char s3[20] = {'H', 'a', 'p', 'p', 'y', '\0'};

    cout << s1 << " " << s2 << endl;

    cout << strlen(s1) << endl;
    cout << strlen(s2) << endl;
    cout << strlen(s3) << endl;

    cout << sizeof(s1) << endl;
    cout << sizeof(s2) << endl;
    cout << sizeof(s3) << endl;

    strcat(s3, s2);
    strcat(s3, " ");
    strcat(s3, s1);

    cout << s3 << endl;

    cout << strcpy(s2, s1) << endl;
    cout << strcmp(s3, s2) << endl;
    cout << strchr(s1, 'p') << endl;
    cout << strlen(s1) << endl;
    cout << sizeof(s1) << endl;
    cout << strlen(s3) << endl;
    return 0;
}
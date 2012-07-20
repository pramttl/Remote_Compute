#include <QtCore/QCoreApplication>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    // QCoreApplication a(argc, argv);
    
    int i = 0,n = 10;
    int sum = 0;

    n = atoi(argv[1]);

    for(i=1;i<=n;i++){
        sum += i;
    }

     cout << sum;  

     exit(sum);
     return sum;
}

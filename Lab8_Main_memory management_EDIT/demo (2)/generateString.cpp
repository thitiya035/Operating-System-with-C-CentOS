#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


char* gen_random(const int len) {
	char *s;
    static const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	srand((unsigned) time(&t));
    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand()% (sizeof(alphanum) - 1)];
    }

    s[len] = 0;
    return s;
}

int main(){
	printf("%s", gen_random(20));
	
}

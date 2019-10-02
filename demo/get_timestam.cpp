#include <time.h>
#include <stdio.h>

int main()
{
    time_t clk = time(NULL);
    printf("%s %d", ctime(&clk), clk);
    return 0;
}

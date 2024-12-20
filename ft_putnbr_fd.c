#include "libft.h"
void ft_putnbr_fd(int n, int fd)
{
    char print;

    if (n < 0)
    {
        print = '-';
        write(fd, &print, 1);
        if (n == INT_MIN)
        {
            write(fd, "2147483648", 10);
            return;
        }
        n *= -1;
    }
    if (n > INT_MAX)
        n = INT_MAX;
    if (n == 0)
    {
        print = '0';
        write(fd, &print, 1);
        return;
    }

    if (n / 10 != 0)
    {
        ft_putnbr_fd(n / 10, fd);
    }
    print = (n % 10) + '0';
    write(fd, &print, 1);
}
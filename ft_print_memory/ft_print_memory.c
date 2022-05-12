#include <stdio.h>
#include <unistd.h>
typedef unsigned long long int ulli_t;

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    while (*str)
        ft_putchar(*str++);
}

void    print_hex(ulli_t addr, int itrno){
    /*
     * itrno: iteration number, there must be 15 iterations
    */
    if (itrno > 0) {
        print_hex(addr / 16, itrno - 1);
        ft_putchar("0123456789abcdef"[addr % 16]);
    }
}


void    *ft_print_memory(void *addr, unsigned int size)
{
    char    *addr_copy;
    unsigned int    bt_sep;
    unsigned int    str_idx;
    char            string[17];

    addr_copy = (char *)addr;
    while (size > (unsigned int)0)
    {
        // print current address
        print_hex((ulli_t)addr_copy, 15);
        ft_putstr(": ");
        str_idx = 0;
        // with each iteration, there's 16 sub iterations for reading 16 byte lines;
        bt_sep = 0;
        while (str_idx < 16)
        {
            if (size > (unsigned int)0){
                print_hex((ulli_t) addr_copy[0], 2);
                if (addr_copy[0] > 32 && addr_copy[0] < 127)
                    string[str_idx++] = addr_copy[0];
                else
                    string[str_idx++] = '.';
                addr_copy++;
            } else
            {
                ft_putstr("  ");
                string[str_idx++] = 0;
            }
            bt_sep++;
            if (bt_sep >= 2)
            {
                ft_putstr(" ");
                bt_sep = 0;
            }
            string[16] = 0;
            if (size > 0)
                size--;
        }
        ft_putstr(string);
        ft_putchar('\n');

    }
    return addr;
}

#include <stdlib.h>
int main() {
    char *bloob = (char *)malloc(98);
    ft_print_memory(bloob, 198);
    return 0;
}

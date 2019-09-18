ft_sleep(int i)
{
    int     j;

    j = 0;
    while (j < (i * 100000))
        j++;
}
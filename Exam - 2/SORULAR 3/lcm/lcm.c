unsigned int    lcm(unsigned int a, unsigned int b)
{
    unsigned int k;
    
    if (a == 0 || b == 0)
        return 0;
    
    if (a > b)
        k = a;
    else
        k = b;

    while (1)
    {
        if ((k % a == 0) && (k % b == 0))
            return k;
        else
            k++;
    }
}
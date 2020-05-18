

int power(int x, int e)
{
    if(e > 0)
    {
        return x*power(x, e-1);
    }
    else
    {
        return 1;
    }

}

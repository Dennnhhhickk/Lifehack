int
bitcount(STYPE value)
{
    int res = 0;
    UTYPE tmp = value;
    while (tmp) {
        if (tmp & 1) {
            res++;
        }
        tmp >>= 1;
    }
    return res;
}

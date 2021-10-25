

STYPE bit_reverse(STYPE value)
{
    UTYPE f = -1;
    UTYPE u = (UTYPE)value;
    UTYPE ans = 0;
    while (f) {
        ans <<= 1;
        ans += u % 2;
        u /= 2;
        f /= 2;
    }
    return ans;
}

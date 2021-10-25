#include <stdio.h>
#include <math.h>
#include <string.h>

typedef long long ll;

int min (int a, int b)
{
    if (a < b)
        return a;
    return b;
}

void f(char *a, char *b)
{
    int n = strlen(b), m = strlen(a), bol = 0;
    for (int i = 0; i < min(m, n); i++)
        if (b[n - min(m, n) + i] != a[i])
        {
            bol = 1;
            break;
        }

    if (bol == 0)
    {
        printf("%d", min(m, n));
        return;
    }

    int z[1000010] = {0};

    int l = 0, r = 0;
    z[0] = 0;

    for (int i = 1; i < n; i++)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        for (; i + z[i] < n && z[i] < strlen(a) && a[z[i]] == b[i + z[i]];)
            z[i]++;
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }

    for(int i = 0; i <= n; i++)
        if (z[i] + i == n)
        {
            printf("%d", z[i]);
            break;
        }
}

int main(void)
{
    char a[1000010], b[1000010];
    scanf("%s %s", a, b);
    f(a, b);
    printf(" ");
    f(b, a);
    printf("\n");
    return 0;
}

/*

H
HEQwFgYVwlSsmXmIvatRdfUNltxSmAmIEkuuKlsYbGEpBeIAlXLLjIlmCZoSaGekHHtCzbnlpJOlScowwoUNoCqYrGqLDwCzUWpnilWbkaSrAKaIIchdBofoeLStJaNVQkALnRgkoekcazupKLrsGpXPUbanazIfFrGaOLjnnRDCiRtQmYUJRXjuVGWuTlxKyHUspCZRQyLnqKWisHKqAWZOMKQfoRJJUUzCnEtWqpjkfdBrDnYivoLmUAuHSgtlTSzNYrhPGWxcfMsclIOtmAIZmfkEmRAFYwFtFNJkKtHeyKPMqwJLlEYqftgPhQXEBzmmyctVxHfwuxBfPgspTmhAPJgBboxFheQLcDZEItwIkrlhhniVbyqtsCdZbVMJHbUGakNDHSCIThGKQolBGJBvTiCcgzFECNSZDPjpWUmNGGLGkVdIZewWIKzjovLknyPWmELXnmeZjavDCtXiJbJlrqJneKBqwuIIkOhdOMPVMlLFsmJrpXXxLXWemDKVKtItYrHQhoYooyjFLbifkpGQRFVOKcDtzCpOAavbJFsYHiLVTVhGcAEqsJYFUfndhvwSYHwjfMesGbOZbpImEzGHhMXVeRsULXdScqLoQmBxXfowBNLOtxRxdmmYdisjGoGFHoTjcVltpZFNQIpbSRilILGfrjPqJnfiXVUPcehknaAYsMbGPEBfYfbjinloOPFmHCyeZjDSSzNBWmVCcQGGmKXcRBatLSTzIAXnutcFYQvoxHtGBpjl

*/
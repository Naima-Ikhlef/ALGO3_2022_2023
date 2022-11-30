void triSelection(Tab t, int n)
{
    int i, j, min, tmp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (t[j] < t[min])
                min = j;
        tmp = t[i];
        t[i] = t[min];
        t[min] = tmp;
    }
}

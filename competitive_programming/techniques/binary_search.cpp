auto binary_search(vector<int> v, int val) -> int
{
    int l = -1;
    int r = n;
    while(r > l + 1)
    {
        int m = (l+r)/2;
        if( v[m] >= x ) r = m;
        else l = m;
    }
    return r;
}

long long read(int l,int R, int x, int l, int r)
{
	if(L>r or R<l)
	{
		return inf;
	}
	if(L>=l and R<=r)
	{
		return T[x];
	}
	int d= (L+R)/2;
	T[2*x] = min(star[x],T[2*x]);
	T[2*x+1] = min(star[x],T[2*x+1]);
	star[2*x] = min(star[x],star[2*x]);
	star[2*x+1] = min(star[x],star[2*x+1]);
	return min(check(L,d,2*x,l,r),check(d+1,R,2*x+1,l,r));
}
void change(int L,int R,int x,int l, int r, int c)
{
	if(L>r or R<l)
	{
		return;
	}
	if(T[x]>c)
	{
		T[x]= c;
	}
	if(L>=l and R<=r and T[x]>=c)
	{
		star[x] = c;
		T[x]=c;
		return;
	}
	if(L==R)
	{
		return;
	}
	T[2*x] = min(star[x],T[2*x]);
	T[2*x+1] = min(star[x],T[2*x+1]);
	star[2*x] = min(star[x],star[2*x]);
	star[2*x+1] = min(star[x],star[2*x+1]);
	int d= (L+R)/2;
	change(L,d,2*x,l,r,c);
	change(d+1,R,2*x+1,l,r,c);
}
main()

{

static int n[3][3]=

{2,4,3,
6, 8, 5,
3,5,1};
int i, *ptr;
ptr = n;
printf ("%d", n[2]);
printf ("%d", ptr[2]);
printf ("%d", *(ptr+2));

}
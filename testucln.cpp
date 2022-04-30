int ucln(int a, int b){
    if(b == 0)
        return a;
    return ucln(b, a%b);
}
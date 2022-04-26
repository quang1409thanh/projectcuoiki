class MyIntSet{
    public:
    MyIntSet():num(0){}
    MyIntSet(int a[], int n){
        if(n>maxSize) num=maxSize;
        else num=n;
        for(int i=0;i<num;i++) elements[i]=a[i];
    }
    ~MyIntSet();
    bool insertVal(int v){

    }
    bool eraseVal(int v){

    }
    void clearAll(){

    }
    bool findVal(int v) const{

    }
    int getSize()const {

    }
    const int* getBedinPtr() const{

    }
    const int* getEndPtr() const {

    }
    private:
    int maxSize;
    int* elements;
    int num;
};
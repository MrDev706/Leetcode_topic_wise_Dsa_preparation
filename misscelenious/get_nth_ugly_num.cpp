//Get the Nth ughly number 


int maxDivide(int a, int b)
{
    while (a % b == 0)
        a = a / b;
         
    return a;
}

int isUgly(int no) 
{
    no = maxDivide(no, 2);
    no = maxDivide(no, 3);
    no = maxDivide(no, 5);
 
    return (no == 1) ? 1 : 0;
}
 


int getNthUgly(int n){
    int count = 1;
    int i=0;
    while(n>count){
        i++;
        if(isUgly(i)){
            count++;

        }


    }
    return i;
}

int main(){
    unsigned no = getNthUgly(150);
    cout<<no<<endl;
}
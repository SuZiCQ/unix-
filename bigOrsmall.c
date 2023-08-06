#include<stdio.h>

union test{

	int a;

	struct{
		short b;
		short c;	
	};
};




int main(){

	union test t;
	t.a=0x00060002;
	printf("%d %d\n",t.b,t.c);
	return 0;

}

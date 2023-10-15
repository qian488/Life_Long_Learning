#include<stdio.h>
#include<math.h>
int main(){
	double s,v;
	scanf("%lf %lf",&s,&v);
	int t=(int)ceil(s/v)+10;//上（1） 
	int h=8,min=0;
	for(int i=t;i>0;i--){//上（2） 
		if(min==0){
			if(h>0){
				h--;
				min=59;
			}
			else{
				h=23;
				min=59;
			}
		}
		else
			min--;
	}
	printf("%02d:%02d",h,min);//上（3） 
 	return 0;
}

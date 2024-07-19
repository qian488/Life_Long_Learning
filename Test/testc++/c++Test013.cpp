#include <cstdio>
#include <cstring>
using namespace std;

struct bign{
	int d[1000];
	int len;
	bign(){
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bign add(bign a, bign b){
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; i++){
		int t = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = t % 10;
		carry = t /10;
	}
	if(carry != 0){
		c.d[c.len++] = carry;
	}
	return c;
}

bign mul(bign a, int b){
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len; i++){
		int t = a.d[i] * b + carry;
		c.d[c.len++] = t % 10;
		carry = t / 10;
	}
	while(carry != 0){
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}

void print(bign a){
	for(int i = a.len - 1; i >= 0; i--){
		printf("%d", a.d[i]);
	}	
}

int main(){
	int n;
	scanf("%d",&n);
	bign sum, a;
	a.d[0] = 1;
	a.len = 1;
	for(int i = 1; i <= n; i++){
		a = mul(a, i);
		sum = add(sum, a);
	}
	print(sum);
	return 0;
}

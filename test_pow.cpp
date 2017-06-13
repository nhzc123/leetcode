if (n == 0) return 1;
if (n == 1) return x;
int tem = pow(x, abs(n / 2));
int result = 0;
 
if (n > 0){
	if (n & 1) return tem * tem * x;
	else return tem * tem;
}
else{
	if (n & 1) return 1.0 / (tem * tem * x);
    else return 1.0 / (tem * tem);
	

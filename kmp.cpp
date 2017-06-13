void makeNext(char *p){
	int len = strlen(p);
    next[0] = -1;
    int j = 0, k = -1;
    while (j < len - 1){
		if (k == -1 || s[j] == p[k]){
			j ++;
			k ++;
			if (s[j] != p[k]){
				next[j] = k;
			}
			else{
				next[j] = next[k];
			}
		}
		else{
			k = next[j];
		}
	}
}

void kmp(char *s, char *p){
	i = 0, j = 0;
	int lens, lenp;
	while (i < lens && j < lenp){
		if (j == -1 || s[i] == p[j]){
			i ++;
			j ++;
		}
		else{
			j = next[j];
		}
	}

}

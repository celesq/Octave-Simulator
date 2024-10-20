//312CA Celescu Rares Andrei
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void incarcare(int *m, int *n, int ult, int cnt, int ****a)
{
	int ***mat= *a;
	scanf("%d%d",m ,n);
	cnt++;	
	if (cnt == 1){
		ult = cnt * 2;
		mat = (int ***) malloc(ult * sizeof(int **));
		if (mat == NULL) {
			free(mat);
			exit(-1);
		}
	}
	else if (cnt > ult){
		ult = cnt * 2;
		int ***newmat = (int ***) realloc(mat, ult * sizeof(int **));
		if (newmat == NULL) {
			free(mat);
			exit(-1);
		}
		mat = newmat;
	}	
	mat[cnt - 1] = (int **) malloc(*m * sizeof(int *));
	if (mat[cnt - 1] == NULL) {
		free(mat);
		exit(-1);
	}
	for (int i = 0; i < *m; i++){
		mat[cnt - 1][i] = (int *) malloc(*n * sizeof(int));
		if (mat[cnt - 1][i] == NULL){
			for (int j = i; j >= 0; j--)
				free(mat[cnt - 1][j]);
			free(mat[cnt - 1]);
			free(mat);
			exit(-1);
		}
	}
	for (int i = 0; i < *m ; i++)
		memset(mat[cnt - 1][i], 0, *n * sizeof(int));
	if(mat != NULL)
		*a=mat;
}

void redimensionare( int ****a, int index, int m1, int n1, int *nrlinii, int *nrcol, int cnt)
{
	int l, c;
	int ***mat = *a;
	int	**copie = (int **) malloc(m1 * sizeof(int *));
	for(int i = 0; i < m1; i++) {
		copie[i]= (int *) malloc(n1 * sizeof(int));
		if(copie[i] == NULL) {
			for (int j = i; j >= 0 ;j--)
				free(copie[i]);
			free(copie);
			exit(-1);
		}
	}
	for(int i = 0; i < m1; i++)
		for(int j = 0; j < n1; j++)
			{
				copie[i][j] = mat[index][i][j];
			}
	scanf("%d",&l);
	int *linii = (int *) malloc(l * sizeof(int));
	if (linii == NULL) {
		free(linii);
		exit(-1);
	}
	for (int i = 0 ; i < l ; i++)
		scanf("%d",&linii[i]);
	scanf("%d",&c);
	int *coloane = (int *) malloc(c * sizeof(int));
	if (coloane == NULL) {
		free(coloane);
		exit(-1);
	}
	for (int i = 0; i < c; i++)
		scanf("%d",&coloane[i]);
	if (index >= cnt || index < 0)
		printf("No matrix with the given index\n");
	else {
	mat[index] = (int **) realloc(mat[index], l * sizeof(int *));
	for (int i = 0; i < l; i++){
		mat[index][i] = (int *) realloc(mat[index][i], c * sizeof(int));
		if (mat[index][i] == NULL){
			for (int j = i; j >= 0; j--)
				free(mat[index][j]);
			free(mat[index]);
			exit(-1);
		}
	}
	for (int i = 0; i < l; i++)
		for(int j = 0; j < c; j++){
			int x = linii[i];
			int y = coloane[j];
			mat[index][i][j] = copie[x][y];
		}
	*nrcol = c;
	*nrlinii = l;
	*a = mat;
	}
	for(int i = 0; i < m1; i++)
			free(copie[i]);
	free(copie);
	free(linii);
	free(coloane);	
}
void schimbare(int ***a, int ***b)
{
	int **aux = *a;
	*a = *b;
	*b = aux;
}

void sortare(int ****a, int cnt, int *nrlinii, int *nrcol)
{
	int ***mat=*a;
	int *v = (int *) malloc( cnt * sizeof(int));
	if (v == NULL) {
		free(v);
		exit(-1);
	}
	for ( int k = 0; k < cnt; k++){
		int s = 0;
		int m1 = nrlinii[k];
		int n1 = nrcol[k];
		for (int i = 0; i < m1; i++)
			for (int j = 0;j < n1; j++){
				s = s + mat[k][i][j];
			}
		s = s % 10007;
		if (s < 0)
			s = s + 10007;
		v[k] = s;
		}
		for (int i = 0; i < cnt - 1; i++)
			for (int j = i; j < cnt ;j++){
					if (v[i] > v[j]){
					int aux1 = nrlinii[i];
					nrlinii[i] = nrlinii[j];
					nrlinii[j] = aux1;
					int aux2 = nrcol[i];
					nrcol[i] = nrcol[j];
					nrcol[j] = aux2;
					schimbare(&mat[i], &mat[j]);
					int aux = v[i];
					v[i] = v[j];
					v[j] = aux;
				}
			}
	free(v);
}

void transpusa(int ***a, int nrlinii, int nrcol, int index)
{
	int ***mat = a;
	int	**copie = (int **) malloc(nrlinii * sizeof(int *));
	for(int i = 0; i < nrlinii; i++){
		copie[i]= (int *) malloc(nrcol * sizeof(int));
		if(copie[i] == NULL) {
			for (int j = i; j >= 0 ;j--)
				free(copie[i]);
			free(copie);
			exit(-1);
		}
	}
	for(int i = 0; i < nrlinii; i++)
		for(int j = 0; j < nrcol; j++)
			{
				copie[i][j] = mat[index][i][j];
			}
	for (int i = 0; i < nrlinii; i++)
		free(mat[index][i]);
	free(mat[index]);
	mat[index] = (int **) malloc( nrcol * sizeof(int *));
	for (int i = 0; i < nrcol; i++){
		mat[index][i] = (int *) malloc( nrlinii * sizeof(int));
		if (mat[index][i] == NULL){
			for (int j = i; j >= 0; j--)
				free(mat[index][j]);
			free(mat[index]);
		}
	}
	int aux = nrlinii;
	nrlinii = nrcol;
	nrcol = aux;
	for (int i = 0; i < nrlinii; i++)
		for (int j = 0; j < nrcol; j++)
			mat[index][i][j] = copie[j][i];
	a = mat;
	for (int i = 0; i < nrcol; i++)
		free(copie[i]);
	free(copie);
}

int **inmultire(int **a, int **b, int **c, int la, int ca, int cb)
{
	for (int i = 0; i < la; i++)
		for (int j = 0; j < cb; j++)
			{
				c[i][j] = 0;
			}
	for ( int i = 0; i < la; i++)
		for (int j = 0; j < cb; j++)
			for (int k = 0; k < ca; k++){
				c[i][j] = ( c[i][j] + (a[i][k] * b[k][j]) ) % 10007;
				if (c[i][j] < 0)
					c[i][j] = 10007 + c[i][j];
			}
	return c;
}

int **suma(int **a, int **b, int nrl)
{
	for (int i = 0; i < nrl; i++)
		for (int j = 0;j < nrl; j++)
			a[i][j] = a[i][j] + b[i][j];
	return a;
}

int **diferenta(int **a, int **b, int nrl)
{
	for (int i = 0; i < nrl; i++)
		for (int j = 0;j < nrl; j++)
			a[i][j] = a[i][j] - b[i][j];
	return a;
}
/*
int **strassen(int **a, int **b, int **c, int la, int ca, int cb)
{
	int bloc = la / 2;
	while (bloc > 8) {
	int **A1 = (int **) malloc(bloc * sizeof(int *));
	for (int i = 0; i < bloc; i++)
		A1[i] = (int *) malloc(bloc * sizeof(int));
	int **A2 = (int **) malloc(bloc * sizeof(int *));
	for (int i = 0; i < bloc; i++)
		A2[i] = (int *) malloc(bloc * sizeof(int));
	int **A3 = (int **) malloc(bloc * sizeof(int *));
	for (int i = 0; i < bloc; i++)
		A3[i] = (int *) malloc(bloc * sizeof(int));
	int **A4 = (int **) malloc(bloc * sizeof(int *));
	for (int i = 0; i < bloc; i++)
		A4[i] = (int *) malloc(bloc * sizeof(int));
	for ( int i = 0; i < bloc; i++)
		for(int j = 0; j < bloc; j++)
			A1[i][j] = a[i][j];
	for (int i = 0; i < bloc; i++)
		for (int j = bloc; j < la; j++)
			A2[i][j] = a[i][j];
	for (int i = bloc; i < la; i++)
		for (int j = 0; j < bloc; j++)
			A3[i][j] = a[i][j];
	for (int i = bloc; i < la; i++)
		for (int j = bloc; j < la; j++)
			A4[i][j] = a[i][j];
	int **M1 = (int **) malloc(bloc * sizeof(int *));
	for (int i = 0; i < bloc; i++)
		M1[i] = (int *) malloc(bloc * sizeof(int));
	int **M2 = (int **) malloc(bloc * sizeof(int *));
	for (int i = 0; i < bloc; i++)
		M2[i] = (int *) malloc(bloc * sizeof(int));
	int **M3 = (int **) malloc(bloc * sizeof(int *));
	for (int i = 0; i < bloc; i++)
		M3[i] = (int *) malloc(bloc * sizeof(int));
	int **M4 = (int **) malloc(bloc * sizeof(int *));
	for (int i = 0; i < bloc; i++)
		M4[i] = (int *) malloc(bloc * sizeof(int));
	int **M5 = (int **) malloc(bloc * sizeof(int *));
	for (int i = 0; i < bloc; i++)
		M5[i] = (int *) malloc(bloc * sizeof(int));
	int **M6 = (int **) malloc(bloc * sizeof(int *));
	for (int i = 0; i < bloc; i++)
		M6[i] = (int *) malloc(bloc * sizeof(int));
	int **M7 = (int **) malloc(bloc * sizeof(int *));
	for (int i = 0; i < bloc; i++)
		M7[i] = (int *) malloc(bloc * sizeof(int));
	int **C1 = (int **) malloc(bloc * sizeof(int *));
	for (int i = 0; i < bloc; i++)
		C1[i] = (int *) malloc(bloc * sizeof(int));
	int **C2 = (int **) malloc(bloc * sizeof(int *));
	for (int i = 0; i < bloc; i++)
		C2[i] = (int *) malloc(bloc * sizeof(int));
	int **C3 = (int **) malloc(bloc * sizeof(int *));
	for (int i = 0; i < bloc; i++)
		C3[i] = (int *) malloc(bloc * sizeof(int));
	int **C4 = (int **) malloc(bloc * sizeof(int *));
	for (int i = 0; i < bloc; i++)
		C4[i] = (int *) malloc(bloc * sizeof(int));
	C1 = suma(diferenta(suma(M1, M4, bloc) ,M5, bloc) ,M7, bloc);
	C2 = suma(M3, M5, bloc);
	C3 = suma(M2, M4, bloc);
	C4 = suma(suma(diferenta(M1, M2, bloc), M3, bloc),M6, bloc);
	for ( int i = 0; i < bloc; i++)
		for(int j = 0; j < bloc; j++)
			a[i][j] = C1[i][j];
	for (int i = 0; i < bloc; i++)
		for (int j = bloc; j < la; j++)
			a[i][j] = C2[i][j];
	for (int i = bloc; i < la; i++)
		for (int j = 0; j < bloc; j++)
			a[i][j] = C3[i][j];
	for (int i = bloc; i < la; i++)
		for (int j = bloc; j < la; j++)
			a[i][j] = C4[i][j];
	bloc = bloc / 2;
	return a;
	}
}
*/
void eliberare( int **a, int nrlinii)
{
	for (int i = 0; i < nrlinii; i++)
		free(a[i]);
	free(a);
}

int **ridicare( int **a, long long put, int nrlinii, int nrcol)
{
	int **copie = (int **) malloc(nrlinii * sizeof(int *));
	for (int i = 0; i < nrlinii; i++) {
		copie[i]= (int *) malloc(nrcol * sizeof(int));
		if(copie[i] == NULL) {
			for (int j = i; j >= 0 ;j--)
				free(copie[i]);
			free(copie);
			exit(-1);
		}
	}
	int **copie1 = (int **) malloc(nrlinii * sizeof(int *));
	for (int i = 0; i < nrlinii; i++) {
		copie1[i]= (int *) malloc(nrcol * sizeof(int));
		if(copie1[i] == NULL) {
			for (int j = i; j >= 0 ;j--)
				free(copie1[i]);
			free(copie1);
			exit(-1);
		}
	}
	for (int i = 0; i < nrlinii; i++)
		for(int j = 0; j < nrcol; j++){
			copie1[i][j] = a[i][j];
			copie[i][j] = a[i][j];
		}
	if (put == 0){
		for ( int i = 0; i < nrlinii; i++)
			for(int j = 0; j < nrcol; j++)
				if (i == j)
					a[i][j] = 1;
				else
					a[i][j] = 0;
		return a;
	} else if (put == 1)
		return a;
	else if (put % 2 == 0)
		return ridicare(inmultire(a, copie1, copie, nrlinii, nrcol, nrcol), put/2, nrlinii, nrcol);
	else
		return inmultire(a, ridicare(inmultire(a, copie1, copie, nrlinii, nrcol, nrcol), (put - 1)/2 ,nrlinii, nrcol), copie1, nrlinii, nrcol, nrcol);
	for(int i = 0; i < nrlinii; i++){
		free(copie[i]);
		free(copie1[i]);
	}
	free(copie);
	free(copie1);
}

void Eliberare1(int ***a, int *nrlinii, int *nrcol, int cnt, int index)
{
	for (int i = 0; i < nrlinii[index]; i++)
		free(a[index][i]);
	free(a[index]);
	for (int i = index + 1; i < cnt; i++){
		a[i - 1] = a[i];
		nrlinii[i - 1] = nrlinii[i];
		nrcol[i - 1] = nrcol[i];
	}
}
int main(void)
{
    int n, m , index, ult = 0, cnt = 0, ***a;
	char carac;
	int *nrcol = malloc(sizeof(int *));
	int *nrlinii = malloc(sizeof(int *));
	while(1){
		scanf("%s",&carac);
		switch (carac) {
			case 'L':
			{
				incarcare(&m, &n, ult, cnt, &a);
				nrlinii[cnt] = m;
				nrcol[cnt] = n;
				for (int i = 0; i < m; i++)
					for (int j = 0; j < n; j++)
						scanf("%d ",&a[cnt][i][j]);
				cnt++;
				if(cnt > ult)
					{
						ult = cnt * 2;
						int *nrcol1 = realloc(nrcol , ult * sizeof(int *));
						int *nrlinii1 = realloc(nrlinii, ult * sizeof(int *));
						if (nrcol1 != NULL) {
							//free(nrcol);
							nrcol = nrcol1;
						}
						else
							exit(-1);
						if (nrlinii1 != NULL) {
							//free(nrlinii);
							nrlinii = nrlinii1;
						}
						else
							exit(-1);
					}
				break;
			}
			case 'D':
			{
				scanf("%d",&index);
				if(index < cnt && index > -1)
					printf("%d %d\n",nrlinii[index],nrcol[index]);
				else
					printf("No matrix with the given index\n");
				break;
			}
			case 'P':
			{
				scanf("%d",&index);
				if(index < cnt && index > -1){
					m = nrlinii[index];
					n = nrcol[index];
					for (int i = 0; i < m; i++){
						for (int j = 0; j < n; j++)
							printf("%d ",a[index][i][j]);
						printf("\n");
					}
				}else 
					printf("No matrix with the given index\n");
				break;
			}
			case 'C':
			{
				scanf("%d",&index);
				int m1 = nrlinii[index];
				int n1 = nrcol[index];
				if (index >= cnt || index < 0){
					m1 = 3;
					n1 = 3;
				}
				redimensionare( &a, index , m1 , n1, &nrlinii[index], &nrcol[index], cnt);
				break;
			}
			case 'O':
			{
				sortare(&a, cnt, nrlinii, nrcol);
				break;
			}
			case 'T':
			{
				scanf("%d",&index);
				if (index < cnt && index > -1){
					transpusa(a, nrlinii[index], nrcol[index], index);
					int aux = nrlinii[index];
					nrlinii[index] = nrcol[index];
					nrcol[index] = aux;
				}
				else
					printf("No matrix with the given index\n");
				break;
			}
			case 'M':
			{
				int i1, i2;
				scanf("%d %d",&i1,&i2);
				if (i1 >= cnt || a[i1] == NULL || a[i2] == NULL || i1 < 0 || i2 < 0 || i2 >= cnt)
					printf("No matrix with the given index\n");
				else if (nrcol[i1] != nrlinii[i2])
					printf("Cannot perform matrix multiplication\n");
				else{
					cnt++;
					if (cnt > ult){
						ult = cnt * 2;
						a = realloc(a, ult * sizeof(int **));
						//if (a1!=NULL)
							//a=a1;
					}
					nrlinii[cnt - 1] = nrlinii[i1];
					nrcol[cnt - 1] = nrcol[i2];
					a[cnt - 1] =  malloc(nrlinii[cnt - 1] * sizeof(int *));
					for (int i = 0; i < nrlinii[cnt - 1]; i++) {
						a[cnt - 1][i]=  malloc(nrcol[cnt - 1] * sizeof(int ));
						if (a[cnt - 1][i] == NULL) {	
							for (int j = i; j >= 0; j--)
								free(a[cnt - 1][j]);
							free(a[cnt - 1]);
							exit(-1);
						}
					}
					a[cnt - 1] = inmultire(a[i1], a[i2], a[cnt - 1], nrlinii[i1], nrcol[i1], nrcol[i2]);
				}
				break;
			}
			case 'R':
			{
				long long put;
				scanf("%d %lld",&index,&put);
				if(index >= cnt || index < 0)
					printf("No matrix with the given index\n");
				else if (put < 0)
					printf("Power should be positive\n");
				else if(nrcol[index] != nrlinii[index])
					printf("Cannot perform matrix multiplication\n");
				else
					a[index] = ridicare(a[index], put, nrlinii[index], nrcol[index]);
				break;
			}
			case 'S':
			{
				int i1, i2;
				scanf("%d %d",&i1,&i2);
				if (index >= cnt || a[i1] == NULL || a[i2] == NULL || index < 0)
					printf("No matrix with the given index\n");
				else if (nrcol[i1] != nrlinii[i2])
					printf("Cannot perform matrix multiplication\n");
				else{
					cnt++;
					if (cnt > ult){
						ult = cnt * 2;
						a = realloc(a, ult * sizeof(int **));
					}
					nrlinii[cnt - 1] = nrlinii[i1];
					nrcol[cnt - 1] = nrcol[i2];
					a[cnt - 1] =  malloc(nrlinii[cnt - 1] * sizeof(int *));
					for (int i = 0; i < nrlinii[cnt - 1]; i++)
						a[cnt - 1][i]=  malloc(nrcol[cnt - 1] * sizeof(int ));
				}
				a[cnt - 1] = inmultire(a[i1], a[i2], a[cnt - 1], nrlinii[i1], nrcol[i1], nrcol[i2]);
				break;
			}
			case 'F':
			{
				scanf("%d",&index);
				if (index < cnt && index > -1) {
					Eliberare1(a, nrlinii, nrcol, cnt, index);
					if (cnt < ult / 2)
						a = (int ***) realloc(a , (ult / 2) *sizeof(int **) );
					cnt--;
				} else 
					printf("No matrix with the given index\n");
				break;
			}
			case 'Q':
			{
				for (int i = 0; i < cnt; i++)
					eliberare(a[i], nrlinii[i]);
				free(nrlinii);
				free(nrcol);
				free(a);
				return 0;
			}
			default:
			{	
				printf("Unrecognized command\n");
				break;
			}
		}
	}
	return 0;
}
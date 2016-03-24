#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000 /* max #lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */

int mygetline(char *,int);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void myqsort(void *lineptr[], int left, int right,
        int (*comp)(void *, void *));
int numcmp(char *, char *);

/* sort input lines */
main(int argc, char *argv[]){
    int nlines; /* number of input lines read */
    int numeric = 0; /* 1 if numeric sort */

    if(argc > 1 && strcmp(argv[1],"-n") == 0)
        numeric = 1;
    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        myqsort((void **)lineptr,0,nlines-1,
            (int (*)(void*,void*))(numeric ? numcmp: strcmp));
        writelines(lineptr,nlines);
        return 0;
    }else{
        printf("input too big to sort \n");
        return 1;
    }
}

/* myqsort: sort v[left]...v[right] into increment */
void myqsort(void *v[], int left, int right,
        int (*comp)(void *, void *)){
    int i,last;

    void swap(void *v[],int,int);

    if(left >= right) /* do nothing if array contains */
        return; /* fewer than two elements */
    swap(v,left,(left + right)/2);
    last = left;
    for(i = left + 1; i<= right;i++)
        if((*comp)(v[i],v[left]) < 0)
            swap(v,++last,i);
    swap(v,left,last);
    myqsort(v,left,last-1,comp);
    myqsort(v,last+1,right,comp);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2){
    double v1,v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if(v1 < v2)
        return -1;
    else if(v1 > v2)
        return 1;
    else 
        return 0;
}

void swap(void *v[], int i, int j){
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLINES];

    nlines = 0;
    while((len = mygetline(line, MAXLINES)) >0 )
        if(nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else{
            line[len-1] = '\0'; /* delete newline */
            strcpy(p,line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines){
    while (nlines-- > 0)
        printf("%s \n", *lineptr++);
}

int mygetline(char *line, int max){
    char c;
    int i = 0;

    while((c = getchar())!= EOF){
        if(c != '\n')
            line[i++] = c;
        else{
            line[i] = '\0';
            return i;
        }
            
    }
    
}

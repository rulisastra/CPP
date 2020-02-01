#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

long long c=0;
int *z,n,cc=0,p=0;

void buatdata(int *x,int &n)
{int i;
 cout<<"banyak data :";cin>>n;
 srand(time(NULL));
 for (i=1;i<=n;i++) {
    x[i]= rand()%10000+1;
    cout<<x[i]<<" ";
   }
 cout<<endl;
 cout<<endl;
}
void sortB(int *x,int n)
{int i,j,t ;
 for (i=1;i<=n-1;i++)
  for (j=1;j<=n-i;j++) 
   if (x[j]>x[j+1]) {t=x[j];x[j]=x[j+1];x[j+1]=t;}
  }

void cetakdata(int *x,int n)
{int i;
 for (i=1;i<=n;i++) {
    cout<<x[i]<<" ";
   }
 cout<<endl;
 cout<<endl;getch();
}

void partisi(int *x,int aw,int ak,int &id)
{ int i,j,t,pivot;
   pivot=x[aw];j=aw;
   for (i=aw+1;i<=ak;i++)
     if (x[i]<pivot) {
       j++;t=x[i];x[i]=x[j];x[j]=t;
     }
  x[aw]=x[j];x[j]=pivot;
  id=j;
}
void qsort(int *x,int aw,int ak)
{int j;
  if (aw<ak) {
     partisi(x,aw,ak,j);
     qsort(x,aw,j-1);
     qsort(x,j+1,ak);
  }
}

void merge(int *x,int aw,int mid,int ak)
{
  int i,j,k,l;
  i=aw; j=mid+1;  k=aw;
  do {
    if(x[i]<=x[j]) {z[k]=x[i];i++;}
    else {z[k]=x[j];j++;}
    k++;}
  while ((i<=mid) && (j<=ak));
  if (i>mid) for (l=j;l<=ak;l++) {z[k]=x[l];k++;}
  else for (l=i;l<=mid;l++) {z[k]=x[l];k++;}
  for (k=aw;k<=ak;k++) x[k]=z[k];
}
void mergesort(int *x,int aw,int ak)
{int mid;
  if(aw<ak) {
    mid =(aw+ak)/2;
    mergesort(x,aw,mid);
    mergesort(x,mid+1,ak);
    merge(x,aw,mid,ak);
  }
}

void MergeQuick(int *x,int aw,int ak)
{int mid;
  if(ak-aw<100000) qsort(x,aw,ak);
  else {
    mid =(aw+ak)/2;
    MergeQuick(x,aw,mid);
    MergeQuick(x,mid+1,ak);
    merge(x,aw,mid,ak);
  }
}
void create_heap(int *a,int n)
{
int q,i,j,key;
  for(q=2;q<=n;q++)
  {
    i=q;
    key=a[i];
    j=i/2;
    while(i>1 && key>a[j])
      {
         a[i]=a[j];
         i=j;
         j=i/2;
         if(j<1)
            j=1;
      }
    a[i]=key;
    }
}

void sort_heap(int *a,int n)
{
int q,i,j,key,temp;
  create_heap(a,n);
  for(q=n;q>=1;q--)
  {
     temp=a[1];
     a[1]=a[q];
     a[q]=temp;
     i=1;
     key=a[i];
     j=2*i;
     if(j+1 < q)
     {
         if(a[j+1] > a[j])
            j++;
        }
     while(j<=q-1 && key<a[j])
     {
       a[i]=a[j];
       i=j;
       j=2*i;
       if(j+1 < q)
       {
          if(a[j+1] > a[j])
             j++;
       }
       else break;
     }
     a[i]=key;
    }
}

main()
{ int i,j,*x;
  cout<<"banyak data :";cin>>n;
  x=new int[n+1];
  z=new int[n+1];
  srand(time(NULL));
  for (i=1;i<=n;i++) {
    x[i]= rand()%100000+1;
    }
  cout<<endl;
 // cetakdata(x,n);
  clock_t begin_time = clock();
   //qsort(x,1,n);
     //mergesort(x,1,n);
    //sortB(x,n);
   //MergeQuick(x,1,n);
   //sort_heap(x,n);
   cout << float( clock () - begin_time )/CLOCKS_PER_SEC;
 // cetakdata(x,n);
 // cout<<"\n perbandingan = "<<p;
 getch();
}

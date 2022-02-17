#include<stdio.h>

int b[10][10],c[10][10];

void disp(int m[10][10])
{
  int i,j;
  for(i=0;i<=2;i++)
  {
   for(j=0;j<=2;j++)
     printf(" %d ",m[i][j]);
   printf("\n");
  }
}

void reinit(int m[10][10])
{
  int i,j;
  for(i=0;i<=2;i++)
  {
   for(j=0;j<=2;j++)
     m[i][j]=c[i][j];
  }
}

void up(int m[10][10])
{
 int q,i,j;
 for(i=0;i<=2;i++)
  {
   for(j=0;j<=2;j++)
     {
      if(m[i][j]==0)
       {
q=m[i-1][j];
m[i-1][j]=0;
m[i][j]=q;goto e1;
       }
    }
  }
e1: ;
}

void down(int m[10][10])
{
 int q,i,j;
 for(i=0;i<=2;i++)
  {
   for(j=0;j<=2;j++)
    {
      if(m[i][j]==0)
       {
q=m[i+1][j];
m[i+1][j]=0;
m[i][j]=q;goto e2;
       }
    }
  }
e2: ;
}

void left(int m[10][10])
{
 int q,j,i;
 for(i=0;i<=2;i++)
  {
   for(j=0;j<=2;j++)
    {
      if(m[i][j]==0)
       {
q=m[i][j-1];
m[i][j-1]=0;
m[i][j]=q;goto e3;
       }
    }
  }
e3: ;
}

void right(int m[10][10])
{
 int q,i,j;
 for(i=0;i<=2;i++)
  {
   for(j=0;j<=2;j++)
    {
      if(m[i][j]==0)
       {
q=m[i][j+1];
m[i][j+1]=0;
m[i][j]=q;goto e4;
       }
    }
  }
e4: ;
}


int hueristic(int m[10][10])
{
 int cn=0,i,j;
 for(i=0;i<=2;i++)
  {
   for(j=0;j<=2;j++)
    {
      if(m[i][j]==b[i][j])
cn++;
    }
  }
 return(cn);
}


void main()
{
 int a[10][10],temp[10][10];
 int a1[10][10],a2[10][10],a3[10][10],a4[10][10];
 int i,j,h,k=0,s,x,flag=0,h1,h2,h3,h4,fg=0;
 printf("\n\nEnter initial State: \n");
 for(i=0;i<=2;i++)
  {
   for(j=0;j<=2;j++)
    scanf("%d",&a[i][j]);
  }

 printf("\nEnter Goal State: \n");
 for(i=0;i<=2;i++)
  {
   for(j=0;j<=2;j++)
    scanf("%d",&b[i][j]);
  }
 for(i=0;i<=2;i++)
  {
   for(j=0;j<=2;j++)
     c[i][j]=a[i][j];
  }

while(1)
 {
   h=hueristic(c);k=0;flag=0;
   printf("\nNew Current State: \n");
   disp(c);
   printf("Hueristic value of Current State :%d\n",h);
   if(h==9)
     { fg=1;
       break;
     }
   for(i=0;i<=2;i++)
    {
     for(j=0;j<=2;j++)
      temp[i][j]=c[i][j];
    }

  for(i=0;i<=2;i++)
   {
    for(j=0;j<=2;j++)
     {
      if(temp[i][j]==0)
       { s=i;x=j;flag=1;break; }
     }
    if(flag==1)
       break;
   }

 if(s==0 && x==0)
   {
    down(temp);
    for(i=0;i<=2;i++)
     {
      for(j=0;j<=2;j++)
       a1[i][j]=temp[i][j];
     }
    h1=hueristic(a1);
    reinit(temp);
    right(temp);
    for(i=0;i<=2;i++)
     {
      for(j=0;j<=2;j++)
a2[i][j]=temp[i][j];
     }
    h2=hueristic(a2);
    reinit(temp);
    if(h>=h1 && h>=h2)
goto end;
    if(h1>h2)
     {
      for(i=0;i<=2;i++)
       {
for(j=0;j<=2;j++)
 c[i][j]=a1[i][j];
       }
     }
    else
     {
      for(i=0;i<=2;i++)
      {
       for(j=0;j<=2;j++)
       c[i][j]=a2[i][j];
      }
     }         //////////////////////
   }
 else if(s==0 && x==1)
   {
    left(temp);
    for(i=0;i<=2;i++)
    {
     for(j=0;j<=2;j++)
      a1[i][j]=temp[i][j];
    }
    h1=hueristic(a1);k=1;
    reinit(temp);
    right(temp);
    for(i=0;i<=2;i++)
     {
      for(j=0;j<=2;j++)
a2[i][j]=temp[i][j];
     }
    h2=hueristic(a2);
    if(h2>h1)
      { k=2; }
    reinit(temp);
    down(temp);
    for(i=0;i<=2;i++)
     {
      for(j=0;j<=2;j++)
a3[i][j]=temp[i][j];
     }
    h3=hueristic(a3);reinit(temp);
    if(h3>h2 && h3>h1)
      { k=3; }
    if(h>=h1 && h>=h2 && h>=h3)
       goto end;

    if(k==1)
     {
      for(i=0;i<=2;i++)
      {
       for(j=0;j<=2;j++)
c[i][j]=a1[i][j];
      }
     }
    else if(k==2)
     {
      for(i=0;i<=2;i++)
      {
       for(j=0;j<=2;j++)
c[i][j]=a2[i][j];
      }
     }
    else if(k==3)
     {
      for(i=0;i<=2;i++)
      {
       for(j=0;j<=2;j++)
c[i][j]=a3[i][j];
      }
     }
   }
 else if(s==0 && x==2)
   {
    left(temp);
    for(i=0;i<=2;i++)
     {
      for(j=0;j<=2;j++)
       a1[i][j]=temp[i][j];
     }
    h1=hueristic(a1);
    reinit(temp);
    down(temp);
    for(i=0;i<=2;i++)
     {
      for(j=0;j<=2;j++)
       a2[i][j]=temp[i][j];
     }
    h2=hueristic(a2);reinit(temp);
    if(h>=h1 && h>=h2)
       goto end;
    if(h1>h2)
     {
      for(i=0;i<=2;i++)
       {
for(j=0;j<=2;j++)
c[i][j]=a1[i][j];
       }
     }
    else
     {
      for(i=0;i<=2;i++)
       {
for(j=0;j<=2;j++)
c[i][j]=a2[i][j];
       }
     }
   }
 else if(s==1 && x==0)
   {
    up(temp);
    for(i=0;i<=2;i++)
     {
      for(j=0;j<=2;j++)
       a1[i][j]=temp[i][j];
     }
    h1=hueristic(a1);k=1;
    reinit(temp);
    down(temp);
    for(i=0;i<=2;i++)
     {
      for(j=0;j<=2;j++)
       a2[i][j]=temp[i][j];
     }
    h2=hueristic(a2);
    if(h2>h1)
       { k=2; }
    reinit(temp);
    right(temp);
    for(i=0;i<=2;i++)
     {
      for(j=0;j<=2;j++)
       a3[i][j]=temp[i][j];  /////////////////////
     }
    h3=hueristic(a3);reinit(temp);
    if(h3>h2 && h3>h1)
       { k=3; }
    if(h>=h1 && h>=h2 && h>=h3)
goto end;
    if(k==1)
      {
       for(i=0;i<=2;i++)
{
for(j=0;j<=2;j++)
 c[i][j]=a1[i][j];
}
      }
    else if(k==2)
     {
      for(i=0;i<=2;i++)
       {
for(j=0;j<=2;j++)
c[i][j]=a2[i][j];
       }
     }
    else if(k==3)
     {
      for(i=0;i<=2;i++)
       {
for(j=0;j<=2;j++)
c[i][j]=a3[i][j];
       }
     }
   }
 else if(s==1 && x==1)
   {
    up(temp);
    for(i=0;i<=2;i++)
     {
      for(j=0;j<=2;j++)
a1[i][j]=temp[i][j];
     }
    h1=hueristic(a1);k=1;
    reinit(temp);
    down(temp);
    for(i=0;i<=2;i++)
     {
      for(j=0;j<=2;j++)
a2[i][j]=temp[i][j];
     }
    h2=hueristic(a2);
    if(h2>h1)
       { k=2; }
    reinit(temp);
    right(temp);
    for(i=0;i<=2;i++)
     {
      for(j=0;j<=2;j++)
       a3[i][j]=temp[i][j];
     }
    h3=hueristic(a3);
    if(h3>h2 && h3>h1)
      { k=3; }
    reinit(temp);
    left(temp);
    for(i=0;i<=2;i++)
     {
      for(j=0;j<=2;j++)
       a4[i][j]=temp[i][j];
     }
    h4=hueristic(a4);reinit(temp);
    if(h4>h3 && h4>h2 && h4>h1)
      { k=4; }
    if(h>=h1 && h>=h2 && h>=h3 && h>=h4)
       goto end;
    if(k==1)
     {
      for(i=0;i<=2;i++)
       {
for(j=0;j<=2;j++)
c[i][j]=a1[i][j];
       }
     }
    else if(k==2)
     {
      for(i=0;i<=2;i++)
       {
for(j=0;j<=2;j++)
c[i][j]=a2[i][j];
       }
     }
    else if(k==3)
     {
      for(i=0;i<=2;i++)
       {
for(j=0;j<=2;j++)
c[i][j]=a3[i][j];
       }
     }
    else if(k==3)
     {
      for(i=0;i<=2;i++)
       {
for(j=0;j<=2;j++)
 c[i][j]=a4[i][j];
       }
     }
   }
 else if(s==1 && x==2)
   {
    up(temp);
    for(i=0;i<=2;i++)
     {
      for(j=0;j<=2;j++)
       a1[i][j]=temp[i][j];
     }
    h1=hueristic(a1);k=1;
    reinit(temp);
    down(temp);
    for(i=0;i<=2;i++)
     {
      for(j=0;j<=2;j++)
       a2[i][j]=temp[i][j];
     }
    h2=hueristic(a2);
    if(h2>h1)
      { k=2; }
    reinit(temp);
    left(temp);
    for(i=0;i<=2;i++)
     {
      for(j=0;j<=2;j++)
       a3[i][j]=temp[i][j];
     }
    h3=hueristic(a3);reinit(temp);
    if(h3>h2 && h3>h1)
      { k=3; }
    if(h>=h1 && h>=h2 && h>=h3)
       goto end;
    if(k==1)
      {
       for(i=0;i<=2;i++)
{
for(j=0;j<=2;j++)
  c[i][j]=a1[i][j];
}
      }
    else if(k==2)
      {
       for(i=0;i<=2;i++)
{
for(j=0;j<=2;j++)
  c[i][j]=a2[i][j];
}
      }
    else if(k==3)
      {
       for(i=0;i<=2;i++)
{
for(j=0;j<=2;j++)
 c[i][j]=a3[i][j];
}
      }
   }
 else if(s==2 && x==0)
   {
    up(temp);
    for(i=0;i<=2;i++)
     {
      for(j=0;j<=2;j++)
       a1[i][j]=temp[i][j];
     }
    h1=hueristic(a1);
    reinit(temp);
    right(temp);
    for(i=0;i<=2;i++)
     {
      for(j=0;j<=2;j++)
       a2[i][j]=temp[i][j];
     }
    h2=hueristic(a2);reinit(temp);
    if(h>=h1 && h>=h2)
       goto end;
    if(h1>h2)
     {
      for(i=0;i<=2;i++)
       {
for(j=0;j<=2;j++)
 c[i][j]=a1[i][j];
       }
     }
    else
     {
      for(i=0;i<=2;i++)
       {
for(j=0;j<=2;j++)
  c[i][j]=a2[i][j];
       }
     }
   }
 else if(s==2 && x==1)
   {
    up(temp);
    for(i=0;i<=2;i++)
     {
      for(j=0;j<=2;j++)
       a1[i][j]=temp[i][j];
     }
    h1=hueristic(a1);k=1;
    reinit(temp);
    left(temp);
    for(i=0;i<=2;i++)
     {
      for(j=0;j<=2;j++)
       a2[i][j]=temp[i][j];
     }
    h2=hueristic(a2);
    if(h2>h1)
      { k=2; }
    reinit(temp);
    right(temp);
    for(i=0;i<=2;i++)
     {
      for(j=0;j<=2;j++)
       a3[i][j]=temp[i][j];
     }
    h3=hueristic(a3);reinit(temp);
    if(h3>h2 && h3>h1)
       { k=3; }
    if(h>=h1 && h>=h2 && h>=h3)
       goto end;
    if(k==1)
     {
      for(i=0;i<=2;i++)
       {
for(j=0;j<=2;j++)
 c[i][j]=a1[i][j];
       }
     }
    else if(k==2)
     {
      for(i=0;i<=2;i++)
       {
for(j=0;j<=2;j++)
c[i][j]=a2[i][j];
       }
     }
    else if(k==3)
     {
      for(i=0;i<=2;i++)
       {
for(j=0;j<=2;j++)
c[i][j]=a3[i][j];
       }
     }
   }
 else if(s==2 && x==2)
   {
    up(temp);
    for(i=0;i<=2;i++)
     {
      for(j=0;j<=2;j++)
       a1[i][j]=temp[i][j];
     }
    h1=hueristic(a1);
    reinit(temp);
    left(temp);
    for(i=0;i<=2;i++)
     {
      for(j=0;j<=2;j++)
       a2[i][j]=temp[i][j];
     }
    h2=hueristic(a2);reinit(temp);
    if(h>=h1 && h>=h2)
      goto end;
    if(h1>h2)
     {
      for(i=0;i<=2;i++)
       {
for(j=0;j<=2;j++)
 c[i][j]=a1[i][j];
       }
     }
    else
     {
      for(i=0;i<=2;i++)
       {
for(j=0;j<=2;j++)
c[i][j]=a2[i][j];
       }
     }
   }
 }

 if(fg==1)
  {
   printf("\nGoal State Reached: \n");
   disp(c);
   printf("\n\t\t\tSearch Terminated Successfully");
  }
 else
  end: printf("\n\t\tStuck at Local maximum\n\t\tSearch Terminated Unsuccessfully");
 getch();
}

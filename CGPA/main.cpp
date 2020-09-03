#include <iostream>
#include <windows.h> 
int cr_reg[10];
int j,sum_nele,sum_ele,sum_labs,sumcg,sumcr,count_nele,count_ele,count_labs;
int data_in(int sem_no,int k);
//int data_out();
int passed(int count_ele,int count_nele,int count_labs,int k,int sum_nele,int sum_ele,int sum_labs);
//int failed();
using namespace std;
int main()
{
    int sem_no;
     system("Color 0A");
     cout<<"How many semester result u have ?"<<endl;
     cin>>sem_no;
     for(int k=0;k<sem_no;k++)
     {
        data_in(sem_no,k);
        passed(count_ele,count_nele,count_labs,k,sum_nele,sum_ele,sum_labs);
     }
    return 0;
}
int data_in(int sem_no,int k)
{
      int n_ele,ele,labs;


      int CiGi[10];
      int n_ele_marks[5],ele_marks[3],lab_marks[2];
      int ne_bl,e_bl,lab_bl;

     {
     sum_nele=0;
     sum_ele=0;
     sum_labs=0;

     sumcg=0;
     sumcr=0;



     count_nele=0;
     count_ele=0;
     count_labs=0;
     cout<<"Enter the no of subjects for non elective, elective and labs for sem "<<k+1<<endl;
     cin>>n_ele>>ele>>labs;

      cr_reg[k] = n_ele*4+ele*3+labs*2;
     cout<<"Enter the grades that you have obtained for theory(non elective)"<<endl;

     for(j=0;j<n_ele;j++)
     {
     cin>>n_ele_marks[j];
     if(n_ele_marks[j]<4)
     {
         n_ele_marks[j]=0;
         count_ele++;
         ne_bl++;
     }
     }
     cout<<"Enter the grades that you have obtained for theory(elective)"<<endl;
      for(j=0;j<ele;j++)
      {
     cin>>ele_marks[j];
      if(ele_marks[j]<4)
      {
         ele_marks[j]=0;
         count_nele++;
         e_bl++;
      }
      }
     cout<<"Enter the grades that you have obtained for lab"<<endl;

      for(j=0;j<labs;j++)
      {
     cin>>lab_marks[j];
      if(lab_marks[j]<4)
      {
        lab_marks[j]=0;
        count_labs++;
        lab_bl++;
      }
      }

     for(int i=0;i<(n_ele);i++)
         n_ele_marks[i]=n_ele_marks[i]*4;
     for(int i=0;i<(ele);i++)
         ele_marks[i]=ele_marks[i]*3;
     for(int i=0;i<(labs);i++)
         lab_marks[i]=lab_marks[i]*2;

       for(int i=0;i<(n_ele);i++)
     {
        sum_nele=sum_nele+n_ele_marks[i];
     }
     cout<<"n ele="<<sum_nele<<endl;

     for(int i=0;i<(ele);i++)
     {
        sum_ele=sum_ele+ele_marks[i];
     }
     cout<<"ele="<<sum_ele<<endl;

     for(int i=0;i<(labs);i++)
     {
        sum_labs=sum_labs+lab_marks[i];
     }
     cout<<"lab="<<sum_labs<<endl;
       cout<<"The number of subjects failed is "<<count_ele+count_nele+count_labs<<endl;
}
}





int passed(int count_ele,int count_nele,int count_labs,int k,int sum_nele,int sum_ele,int sum_labs)
{
    int CiGi[10];
    CiGi[k]=sum_ele+sum_labs+sum_nele;
    cout<<"CiGi of "<<k+1<<" sem is "<<CiGi[k]<<endl;
    float SGPA=CiGi[k]/cr_reg[k];
    cout<<"SGPA of sem "<<k+1<<" is "<<SGPA<<endl;

    sumcg=CiGi[k]+sumcg;
    sumcr=cr_reg[k]+sumcr;

    float CGPA =(sumcg/sumcr);
     cout<<"CGPA is : "<<CGPA<<endl;
}


/*
Knowns: At t=0
Requirements: Mass flow rate, rate of pressure and pressure 
Time interval: 0.01s, given
Events: At certain times, Change to G
*/

#include <stdio.h>

float BETA=10.0f;

float VA=100.0f;
float VC=1.0f;

// To execute C, please define "int main()"

int main() {
  // 0.01 time step and end result of 10, so 1001 values
  float PA[1001],PC[1001],PT[1001],DPDTA[1001],DPDTC[1001],QF[1001],QD[1001],TIME[1001];
  float timestep=0.01f;
  // Time 0 parameters are first values
  PA[0] = 1000.0f;
  PC[0] = 0.0f;
  PT[0] = 0.0f;
  //Set events
  int G1[1001], G2[1001];
  //Ensure data is zeroed out
  for(int i=0;i<1001;i++)
  {
    G1[i]=0;G2[i]=0;PT[i]=0;
    if(i>=100 && i<=400)  G1[i]=1;
    if(i>=800)  G2[i]=1;
  }
  for(int i=1;i<1001;i++)
  {
    //each i represents 0.01 time step
    //TIME[i]=(float)(i*1.0f)/100.0f;
    TIME[i]=TIME[i-1]+timestep;
    //Calculate flow rate
    QF[i]=G1[i-1]*(PA[i-1]-PC[i-1]);
    QD[i]=G2[i-1]*(PC[i-1]-PT[i-1]);
    //Calculate pressure drop
    DPDTA[i]=(float)(BETA*1.0f/VA)*(-QF[i]);
    DPDTC[i]=(float)(BETA*1.0f/VC)*(QF[i]-QD[i]);
    //Calculate new pressure
    PA[i]=PA[i-1]+DPDTA[i]*1.0f*(timestep);
    PC[i]=PC[i-1]+DPDTC[i]*1.0f*(timestep);
    //printf("PC[i-1]: %f\n", PC[i-1]);
    //printf("time delta: %f\n", TIME[i]-TIME[i-1]);
    //Outputs
    printf("%6.2f: accumulator %.5f cylinder %.5f\n",TIME[i],PA[i],PC[i]);
    //printf("%f,%f,%f,%f,%f,%f\n",DPDTA[i],DPDTC[i],PA[i],QF[i],PC[i],QD[i]);
    //Events
    if(G1[i]!=G1[i-1])
    {
      if(G1[i]==1)  printf("%6.2f: event %s\n",TIME[i],"fill_on");
      else    printf("%6.2f: event %s\n",TIME[i],"fill_off");
    }
    if(G2[i]!=G2[i-1])
    {
      if(G2[i]==1)  printf("%6.2f: event %s\n",TIME[i],"drain_on");
      else    printf("%6.2f: event %s\n\n",TIME[i],"drain_on");
    }
  }
  return 0;
}

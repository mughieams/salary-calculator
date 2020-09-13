#include <stdio.h>
#include <strings.h>

const unsigned int BASIC_SALARY = 2000000;
const unsigned int MINIMUM_WORKING_HOURS = 8;
const unsigned int OVERTIME_ALLOWANCE = 3000;
const unsigned int WORKING_DAYS_IN_MONTH = 20;

struct Map {
  char group[5];
  float percentage;
};

struct Map Position[3] = {
  {"1", 0.05},
  {"2", 0.1},
  {"3", 0.15}
};

struct Map Education[3] = {
  {"SMA", 0.025},
  {"D3", 0.05},
  {"S1", 0.1}
};

int getPositionIndex(char group[]){
  int length = sizeof(Position) / sizeof(Position[0]);
  for(int i = 0; i < 3; i++){
    if(strcasecmp(group, Position[i].group) == 0){
      return i;
    }
  }
  return -1;
}

int getEducationIndex(char group[]){
  int length = sizeof(Education) / sizeof(Education[0]);
  for(int i = 0; i < 3; i++){
    if(strcasecmp(group, Education[i].group) == 0){
      return i;
    }
  }
  return -1;
}

int countEducationAllowance(int index){
  return BASIC_SALARY * Education[index].percentage;
};

int countPositionAllowance(int index){
  return BASIC_SALARY * Position[index].percentage;
};

int countOvertimeAllowance(int hours){
  return hours > MINIMUM_WORKING_HOURS ? OVERTIME_ALLOWANCE * ((hours - MINIMUM_WORKING_HOURS) * WORKING_DAYS_IN_MONTH) : 0;
}

int countTotalSalary(int positionAllowance, int educationAllowance, int overtimeAllowance){
  return BASIC_SALARY + positionAllowance + educationAllowance + overtimeAllowance;
}

int main(void) {
  char employeeName[20], employeePosition[3], employeeEducation[3];
  int employeeWorkingHours;

  printf("PROGRAM HITUNG GAJI KARYAWAN\n");
  printf("Nama Karyawan: "); scanf("%[^\n]%*c", employeeName);
  printf("Golongan Jabatan: "); scanf("%[^\n]%*c", employeePosition);
  printf("Pendidikan: "); scanf("%[^\n]%*c", employeeEducation);
  printf("Jumlah jam kerja: "); scanf("%d", &employeeWorkingHours);

  getchar();
  return 0;
}
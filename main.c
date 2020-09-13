#include <stdio.h>
#include <strings.h>

const unsigned int BASIC_SALARY = 2000000;
const unsigned int MINIMUM_WORKING_HOURS = 8;
const unsigned int OVERTIME_ALLOWANCE = 3000;
const unsigned int WORKING_DAYS_IN_MONTH = 20;

struct Map {
  char group[3];
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
  for(int i = 0; i < length; i++){
    if(strcasecmp(group, Position[i].group) == 0){
      return i;
    }
  }
  return -1;
}

int getEducationIndex(char group[]){
  int length = sizeof(Education) / sizeof(Education[0]);
  for(int i = 0; i < length; i++){
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
  char employeeName[20], employeePosition[2], employeeEducation[4];
  int employeeWorkingHours;

  unsigned int positionAllowance, educationAllowance, overtimeAllowanve, totalSalary;

  printf("PROGRAM HITUNG GAJI KARYAWAN\n");
  printf("Nama Karyawan: "); scanf("%[^\n]%*c", employeeName);
  printf("Golongan Jabatan: "); scanf("%[^\n]%*c", employeePosition);
  printf("Pendidikan: "); scanf("%[^\n]%*c", employeeEducation);
  printf("Jumlah jam kerja: "); scanf("%d", &employeeWorkingHours);

  int indexPosition = getPositionIndex(employeePosition);
  
  int indexEducation = getEducationIndex(employeeEducation);

  if (indexPosition < 0 || indexEducation < 0){
    printf("Data yang anda masukan tidak valid! Periksa kembali!");
  } else if (employeeWorkingHours < MINIMUM_WORKING_HOURS){
    printf("Jumlah jam kerja harian dibawah minimum! Minimum jam kerja %d jam", MINIMUM_WORKING_HOURS);
  } else {
    printf("Nama Karyawan: %s\n", employeeName);
    printf("\t Tunjangan Jabatan Rp %d\n", countPositionAllowance(indexPosition));
    printf("\t Tunjangan Pendidikan Rp %d\n", countEducationAllowance(indexEducation));
    printf("\t Honor Lembur Rp %d\n", countOvertimeAllowance(employeeWorkingHours));
    printf("Total Gaji Rp %d\n", countTotalSalary(countPositionAllowance(indexPosition), countEducationAllowance(indexEducation), countOvertimeAllowance(employeeWorkingHours)));
  }

  getchar();
  return 0;
}
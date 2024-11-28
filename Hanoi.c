/*
Author - Matous Kloucek
Description - Tower Of Hanoi
Date - 13-02-2024
*/
#include <stdio.h>
#define SIZE 12
void towerHanoi(int , char,char,char);
int main()
{
	char dest = 'C';
	char spare = 'B';
	char source = 'A';
	int disks;
	printf("\nHow many disks will your tower have?\n");
	scanf("%d",&disks);
	towerHanoi(disks-1,source,dest,spare);
	return 0;
}

void towerHanoi(int d,char src,char dst,char aux)
{
	if(d == 0)
	{
		printf("Disk %d moved from %c to %c\n",d,src,dst);
	}
	else
	{
		towerHanoi(d-1, src,aux,dst);
		printf("Disk %d moved from %c to %c\n",d,src,dst);
		towerHanoi(d-1,aux,dst,src);
	}
}

/*
TowerHanoi(disks,source,target,spare)
    If(n==0)
        return 1;
    Else
        TowerHanoi(disks-1,source,spare,target)
        move disk to target
        TowerHanoi(disk-1,spare,target,source)
*/
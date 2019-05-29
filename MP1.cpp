#include <iostream>
#include <conio.h>
#include<iomanip>
#include <string>
using namespace std;

int main()
{
	int i=0, n=50;
	float E1[n], E2[n], E3[n], E4[n], totalEXP[i];
	float ST1[n], ST2[n], ST3[n], ST4[n], totalST[i];
	float MP1[n], MP2[n], totalMP[i];
	float WE[n], PE[n], totalME[i];
	float finalGrade[n], transmutedGrade[n];
	string studentName[n];
	
	for(i=0; i<50; i++)
	{
		//This allows the instructor to input the students' names and their raw grades
		//It automatically calculates the total score and total percentage
		cout << "\nEnter student name: ";
		cin >> studentName[i];
		cout << "\nEnter the student's grade on the following: \n";
		
		cout << "\n  EXPERIMENTS (20%) \n";
		cout << "  EXP 1: "; 
		cin >> E1[i];
		cout << "  EXP 2: "; 
		cin >> E2[i];
		cout << "  EXP 3: "; 
		cin >> E3[i];
		cout << "  EXP 4: ";
		cin >> E4[i];
		totalEXP[i] = (E1[i]*0.05) + (E2[i]*0.05) + (E3[i]*0.05) + (E4[i]*0.05);
		cout << "  Total Score: " << E1[i]+E2[i]+E3[i]+E4[i] << "/400";
		cout << "\n  Total Percentage: " << totalEXP[i] << "%" << endl;

		cout << "\n  SKILLS TESTS (20%)\n";
		cout << "  ST 1: "; 
		cin >> ST1[i];
		cout << "  ST 2: "; 
		cin >> ST2[i];
		cout << "  ST 3: "; 
		cin >> ST3[i];
		cout << "  ST 4: ";
		cin >> ST4[i];
		totalST[i] = (ST1[i]*0.05) + (ST2[i]*0.05) + (ST3[i]*0.05) + (ST4[i]*0.05);
		cout << "  Total Score: " << ST1[i]+ST2[i]+ST3[i]+ST4[i] << "/400";
		cout << "\n  Total Percentage: " << totalST[i] << "%"	<< endl;
	
		cout << "\n  MACHINE PROBLEMS (20%) \n";
		cout << "  MP 1: ";
		cin >> MP1[i];
		cout << "  MP 2: ";
		cin >> MP2[i];
		totalMP[i] = (MP1[i]*0.10) + (MP2[i]*0.10);
		cout << "  Total Score: " << MP1[i]+MP2[i] << "/200";
		cout << "\n  Total Percentage: " << totalMP[i] << "%" << endl;
	
		cout << "\n  MAJOR EXAMINATIONS (40%)\n";
		cout << "  Written Examination: ";
		cin >> WE[i];
		cout << "  Practical Examination: ";
		cin >> PE[i];
		totalME[i] = (WE[i]*0.40) + (PE[i]*.40);
		cout << "  Total Score: " << WE[i]+PE[i] << "/100";
		cout << "\n  Total Percentage: " << totalME[i] << "%" << endl;
		
		finalGrade[i] = totalME[i] + totalMP[i] + totalST[i] + totalEXP[i];	
	}
	
	//This code transmutes the students' coressponding grade point average (GPA) based on a table 
	for(i=0; i<50; i++)
	{
		if ((finalGrade[i]>=60.00) && (finalGrade[i]<=64.44)){
		 	transmutedGrade[i] = 3.00;}
		else if ((finalGrade[i]>=64.45) && (finalGrade[i]<=68.89)){
		 	transmutedGrade[i] = 2.75;}
		else if ((finalGrade[i]>=68.90) && (finalGrade[i]<=73.33)){
			transmutedGrade[i] = 2.50;}
		else if ((finalGrade[i]>=73.34) && (finalGrade[i]<=77.78)){
			transmutedGrade[i] = 2.25;}
		else if ((finalGrade[i]>=77.79) && (finalGrade[i]<=82.22)){
			transmutedGrade[i] = 2.00;}	
		else if ((finalGrade[i]>=82.23) && (finalGrade[i]<=86.67)){
			transmutedGrade[i] = 1.75;}	
		else if ((finalGrade[i]>=86.68) && (finalGrade[i]<=91.11)){
			transmutedGrade[i] = 1.50;}
		else if ((finalGrade[i]>=91.12) && (finalGrade[i]<=95.56)){
			transmutedGrade[i] = 1.25;}
		else if ((finalGrade[i]>=95.57) && (finalGrade[i]<=100)){
			transmutedGrade[i] = 1.00;}
		else{
			transmutedGrade[i] = 5.00;}	
	}
	
	//This displays the students' final grade, its transmuted grade and whether the student paased or failed
	cout << endl;
	cout << "Name" << "\t\t" << "Final Grade" << "\t\t" << "Transmuted Grade" << "\t" << "Pass/Fail" << endl;
	for(int i=0; i<50; i++){
		cout << fixed << setprecision(2) << left;
		cout<< studentName[i] << "\t\t" << finalGrade[i] << "\t\t\t" << transmutedGrade[i] << "\t\t\t";
		if(transmutedGrade[i] <= 3){
			cout << "Pass" << endl;
		}else{
			cout << "Fail" << endl;
		}
	}
	
	//This allows the program to determine and display the top 10 outstanding students 
	for(i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(finalGrade[i] < finalGrade[j])
			{
				string temp1 = studentName[i];
				studentName[i] = studentName[j];
				studentName[j] = temp1;
				
				double temp2 = finalGrade[i];
				finalGrade[i] = finalGrade[j];
				finalGrade[j] = temp2;
			}
		}
	}
	
	cout << endl;
	cout << "The Top 10 Performing Students:" << endl;
	cout << endl;
	for(i=0; i<50; i++)
	{
		cout << "  Top " << i+1 << ": " << studentName[i] << "\t" << transmutedGrade[i] << endl;
	}
	
	_getch();
	return 0;
}
